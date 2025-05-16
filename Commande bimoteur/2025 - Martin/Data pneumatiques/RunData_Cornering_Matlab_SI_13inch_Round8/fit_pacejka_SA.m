load('B1965run36.mat') 

% Nettoyage des données
valid_idx = ~isnan(SA) & ~isnan(FY) & ~isnan(FZ);
SA = SA(valid_idx);
FY = FY(valid_idx);
FZ = FZ(valid_idx);

% Définir les intervalles de charge (négatifs)
fz_bins = [-1700, -1400, -1100, -800, -500, -200, -100];
colors = lines(length(fz_bins)-1);
legend_entries = {};
pacejka_coeffs = {};
smoothed_data = {};

% Paramètres pour le lissage
sa_range = -15:0.5:15;  % plage de slip angle en degrés
window = 1;             % demi-largeur autour de chaque angle pour la moyenne

% Étape 1 : Lissage + sauvegarde
for i = 1:length(fz_bins)-1
    idx_fz = FZ >= fz_bins(i) & FZ < fz_bins(i+1);
    sa_bin = SA(idx_fz);
    fy_bin = FY(idx_fz);

    sa_mean = [];
    fy_mean = [];
    for sa_val = sa_range
        idx_sa = abs(sa_bin - sa_val) <= window;
        if sum(idx_sa) >= 5
            sa_mean(end+1) = sa_val;
            fy_mean(end+1) = mean(fy_bin(idx_sa));
        end
    end

    % Sauvegarde pour traçage plus tard
    smoothed_data{i}.sa = sa_mean;
    smoothed_data{i}.fy = fy_mean;
    smoothed_data{i}.fz_range = [fz_bins(i), fz_bins(i+1)];
end

% Étape 2 : Fit Pacejka pour chaque courbe lissée
for i = 1:length(smoothed_data)
    sa_mean = smoothed_data{i}.sa;
    fy_mean = smoothed_data{i}.fy;

    if length(sa_mean) < 5
        warning('Pas assez de points pour le fit dans l''intervalle [%d, %d]', smoothed_data{i}.fz_range);
        continue
    end

    % Modèle Pacejka simplifié
    pacejka_eq = @(p, x) p(3) * sin(p(2) * atan(p(1) * x - p(4) * (p(1) * x - atan(p(1) * x)))) + p(5);

    % Paramètres initiaux [B, C, D, E, Sh]
    p0 = [10.38, -2.2, max(abs(fy_mean)), 1.1, 1.1];
    error_fun = @(p) fy_mean - pacejka_eq(p, deg2rad(sa_mean));
    options = optimset('Display','off');
    [p_fit, ~, ~, exitflag] = lsqnonlin(error_fun, p0, [], [], options);

    if exitflag > 0
        pacejka_coeffs{i}.params = p_fit;
        pacejka_coeffs{i}.fz_range = smoothed_data{i}.fz_range;
    else
        pacejka_coeffs{i}.params = [];
        pacejka_coeffs{i}.fz_range = smoothed_data{i}.fz_range;
        warning('Fit échoué pour FZ ∈ [%d, %d]', smoothed_data{i}.fz_range(1), smoothed_data{i}.fz_range(2));

    end
end

% Étape 3 : Tracé final des courbes lissées + fits Pacejka
figure; hold on;

for i = 1:length(smoothed_data)
    % Couleur unique pour l’intervalle
    color = colors(i,:);
    sa_mean = smoothed_data{i}.sa;
    fy_mean = smoothed_data{i}.fy;
    fz_str = sprintf('[%.0f, %.0f] N', smoothed_data{i}.fz_range);

    % Courbe lissée
    plot(sa_mean, fy_mean, '-', 'LineWidth', 2, 'Color', color);
    legend_entries{end+1} = ['Lissé ' fz_str];

    % Si les coefficients Pacejka sont présents
    if ~isempty(pacejka_coeffs{i}.params)
        sa_fit = linspace(min(sa_mean), max(sa_mean), 200);
        fy_fit = pacejka_eq(pacejka_coeffs{i}.params, deg2rad(sa_fit));
        plot(sa_fit, fy_fit, '--', 'LineWidth', 1.5, 'Color', color);
        legend_entries{end+1} = ['Fit ' fz_str];
    end
end

xlabel('Slip Angle SA (°)');
ylabel('Force latérale FY (N)');
title('Courbes lissées et fits Pacejka FY vs SA pour différentes charges FZ');
legend(legend_entries, 'Location', 'best');
grid on;
xlim([-15 15]);

% Étape 4 : Affichage console des coefficients
fprintf('\n--- Coefficients Pacejka (B, C, D, E, Sh) ---\n');
for i = 1:length(pacejka_coeffs)
    fz_range = pacejka_coeffs{i}.fz_range;
    params = pacejka_coeffs{i}.params;
    if ~isempty(params)
        fprintf('FZ ∈ [%.0f, %.0f] N => B=%.2f, C=%.2f, D=%.1f, E=%.2f, Sh=%.2f\n', ...
            fz_range(1), fz_range(2), params(1), params(2), params(3), params(4), params(5));
    else
        fprintf('FZ ∈ [%.0f, %.0f] N => Fit échoué\n', fz_range(1), fz_range(2));
    end
end
