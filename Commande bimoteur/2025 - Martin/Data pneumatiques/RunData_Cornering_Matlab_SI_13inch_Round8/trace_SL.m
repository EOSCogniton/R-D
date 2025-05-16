load('B1965run49.mat')

% Nettoyage des données
valid_idx = ~isnan(SL) & ~isnan(FX) & ~isnan(FZ);
SL = SL(valid_idx);
FX = FX(valid_idx);
FZ = FZ(valid_idx);

% Définir les intervalles de charge (les mêmes que l'original)
fz_bins = [-1700, -1400, -1100, -800, -500, -200, -100];
colors = lines(length(fz_bins)-1);
legend_entries = {};

% Paramètres pour le lissage
sl_range = -0.3:0.01:0.3;  % Valeurs typiques du slip ratio (SR ou SL)
window = 0.01;

figure; hold on;

for i = 1:length(fz_bins)-1
    idx_fz = FZ >= fz_bins(i) & FZ < fz_bins(i+1);
    sl_bin = SL(idx_fz);
    fx_bin = FX(idx_fz);

    % Lissage : moyenne autour de chaque valeur de SL
    sl_mean = [];
    fx_mean = [];
    for sl_val = sl_range
        idx_sl = abs(sl_bin - sl_val) <= window;
        if sum(idx_sl) >= 5
            sl_mean(end+1) = sl_val;
            fx_mean(end+1) = mean(fx_bin(idx_sl));
        end
    end

    % Tracé du lissé
    plot(sl_mean, fx_mean, 'LineWidth', 2, 'Color', colors(i,:));
    legend_entries{end+1} = sprintf('Lissé [%d, %d] N', fz_bins(i), fz_bins(i+1));

    % Sauvegarde des données lissées dans un fichier .mat
    filename = sprintf('curve_SL_fx_%d_%d.mat', fz_bins(i), fz_bins(i+1));
    SL_lisse = sl_mean';
    FX_lisse = fx_mean';
    save(filename, 'SL_lisse', 'FX_lisse');
    disp(['Sauvegardé : ' filename]);
end

% Mise en forme du graphe
xlabel('Slip Ratio SL');
ylabel('Force longitudinale FX (N)');
title('Courbes lissées FX vs SL pour différentes charges FZ');
legend(legend_entries, 'Location', 'best');
grid on;
xlim([-0.3 0.3]);
ylim([-4000 4000]);

% Sauvegarde de la figure principale
saveas(gcf, 'courbes_lissees_FX_vs_SL.png');
disp('Figure enregistrée sous : courbes_lissees_FX_vs_SL.png');
