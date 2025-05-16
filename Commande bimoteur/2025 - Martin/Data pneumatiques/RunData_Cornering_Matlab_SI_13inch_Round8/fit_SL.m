load('B1965run49.mat');

% Nettoyage des données
valid_idx = ~isnan(SL) & ~isnan(FX) & ~isnan(FZ);
SL = SL(valid_idx);
FX = FX(valid_idx);
FZ = FZ(valid_idx);

% Définir les intervalles de charge (négatifs)
fz_bins = [-1700, -1400, -1100, -800, -500, -200, -100];
colors = lines(length(fz_bins)-1);
legend_entries = {};
pacejka_coeffs = {};
smoothed_data = {};

% Paramètres pour le lissage
sl_range = -0.2:0.01:0.2;  % plage de slip ratio (SR)
window = 0.005;            % demi-largeur autour de chaque valeur

% Étape 1 : Lissage + sauvegarde
for i = 1:length(fz_bins)-1
    idx_fz = FZ >= fz_bins(i) & FZ < fz_bins(i+1);
    sl_bin = SL(idx_fz);
    fx_bin = FX(idx_fz);

    sl_mean = [];
    fx_mean = [];
    for sl_val = sl_range
        idx_sl = abs(sl_bin - sl_val) <= window;
        if sum(idx_sl) >= 5
            sl_mean(end+1) = sl_val;
            fx_mean(end+1) = mean(fx_bin(idx_sl));
        end
    end

    % Sauvegarde si au moins quelques points
    smoothed_data{i}.sl = sl_mean;
    smoothed_data{i}.fx = fx_mean;
    smoothed_data{i}.fz_range = [fz_bins(i), fz_bins(i+1)];
end

% Étape 2 : Fit Pacejka longitudinal
for i = 1:length(smoothed_data)
    sl_mean = smoothed_data{i}.sl;
    fx_mean = smoothed_data{i}.fx;

    if length(sl_mean) < 5
        fz_range = smoothed_data{i}.fz_range;
        warning('Pas assez de points pour le fit dans l''intervalle [%d, %d]', fz_range(1), fz_range(2));
        continue
    end

    % Modèle Pacejka simplifié
    pacejka_eq = @(p, x) p(3) * sin(p(2) * atan(p(1) * x - p(4) * (p(1) * x - atan(p(1) * x)))) + p(5);

    % Paramètres initiaux [B, C, D, E, Sh]
    p0 = [8, 2, max(abs(fx_mean)), -2, 100];
    error_fun = @(p) fx_mean - pacejka_eq(p, sl_mean);
    options = optimset('Display','off');

    [p_fit, ~, ~, exitflag] = lsqnonlin(error_fun, p0, [], [], options);

    if exitflag > 0
        pacejka_coeffs{i}.params = p_fit;
        pacejka_coeffs{i}.fz_range = smoothed_data{i}.fz_range;
    else
        warning('Fit échoué pour FZ ∈ [%d, %d]', smoothed_data{i}.fz_range(1), smoothed_data{i}.fz_range(2));
    end
end

% Étape 3 : Tracé final des courbes lissées + fits
figure; hold on;

for i = 1:length(smoothed_data)
    sl_mean = smoothed_data{i}.sl;
    fx_mean = smoothed_data{i}.fx;
    color = colors(i,:);
    fz_str = sprintf('[%.0f, %.0f] N', smoothed_data{i}.fz_range);

    % Courbe lissée
    plot(sl_mean, fx_mean, '-', 'LineWidth', 2, 'Color', color);
    legend_entries{end+1} = ['Lissé ' fz_str];

    % Tracé du fit si dispo
    if i <= length(pacejka_coeffs) && isfield(pacejka_coeffs{i}, 'params') && ~isempty(pacejka_coeffs{i}.params)
        sl_fit = linspace(min(sl_mean), max(sl_mean), 200);
        fx_fit = pacejka_eq(pacejka_coeffs{i}.params, sl_fit);
        plot(sl_fit, fx_fit, '--', 'LineWidth', 1.5, 'Color', color);
        legend_entries{end+1} = ['Fit ' fz_str];
    end
end

xlabel('Slip Ratio SL');
ylabel('Force longitudinale FX (N)');
title('Fit Pacejka FX vs SL pour différentes charges FZ');
legend(legend_entries, 'Location', 'best');
grid on;
xlim([-0.2 0.2]);

% Étape 4 : Affichage console des coefficients
fprintf('\n--- Coefficients Pacejka (B, C, D, E, Sh) ---\n');
for i = 1:length(pacejka_coeffs)
    if isfield(pacejka_coeffs{i}, 'params') && ~isempty(pacejka_coeffs{i}.params)
        fz_range = pacejka_coeffs{i}.fz_range;
        params = pacejka_coeffs{i}.params;
        fprintf('FZ ∈ [%.0f, %.0f] N => B=%.2f, C=%.2f, D=%.1f, E=%.2f, Sh=%.2f\n', ...
            fz_range(1), fz_range(2), params(1), params(2), params(3), params(4), params(5));
    end
end
