load('B1965run36.mat')

% Nettoyage des données
valid_idx = ~isnan(SA) & ~isnan(FY) & ~isnan(FZ);
SA = SA(valid_idx);
FY = FY(valid_idx);
FZ = FZ(valid_idx);

% Définir les intervalles de charge
fz_bins = [-1700, -1400, -1100, -800, -500, -200, -100];
colors = lines(length(fz_bins)-1);
legend_entries = {};

% Paramètres pour le lissage
sa_range = -15:0.5:15;
window = 1;

figure; hold on;

for i = 1:length(fz_bins)-1
    idx_fz = FZ >= fz_bins(i) & FZ < fz_bins(i+1);
    sa_bin = SA(idx_fz);
    fy_bin = FY(idx_fz);

    % Lissage : moyenne autour de chaque valeur de SA
    sa_mean = [];
    fy_mean = [];
    for sa_val = sa_range
        idx_sa = abs(sa_bin - sa_val) <= window;
        if sum(idx_sa) >= 5
            sa_mean(end+1) = sa_val;
            fy_mean(end+1) = mean(fy_bin(idx_sa));
        end
    end

    % Tracé du lissé
    plot(sa_mean, fy_mean, 'LineWidth', 2, 'Color', colors(i,:));
    legend_entries{end+1} = sprintf('Lissé [%d, %d] N', fz_bins(i), fz_bins(i+1));

    % Sauvegarde des données lissées dans un fichier .mat
    filename = sprintf('curve_%d_%d.mat', fz_bins(i), fz_bins(i+1));
    SA_lisse = sa_mean';
    FY_lisse = fy_mean';
    save(filename, 'SA_lisse', 'FY_lisse');
    disp(['Sauvegardé : ' filename]);
end

% Mise en forme du graphe
xlabel('Slip Angle SA (°)');
ylabel('Force latérale FY (N)');
title('Courbes lissées FY vs SA pour différentes charges FZ');
legend(legend_entries, 'Location', 'best');
grid on;
xlim([-15 15]);
ylim([-4000 4000]);

% Sauvegarde de la figure principale
saveas(gcf, 'courbes_lissees_FY_vs_SA.png');
disp('Figure enregistrée sous : courbes_lissees_FY_vs_SA.png');
