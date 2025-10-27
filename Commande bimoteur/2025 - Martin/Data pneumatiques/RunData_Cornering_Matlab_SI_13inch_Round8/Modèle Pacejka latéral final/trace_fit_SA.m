% Paramètres des courbes (format : [B C D E])
courbe_1100_800 = [8.48 -1.72 2588.2 -0.11];
courbe_800_500  = [10.48 -1.75 1784.7 0.44];
courbe_500_200  = [10.38 -2.21 1007.6 1.13];

% Valeurs d'angle de glissement
alpha = -20:0.01:20;

% Calcul des FY pour les 3 charges
fy500  = fy(alpha, courbe_500_200);
fy800  = fy(alpha, courbe_800_500);
fy1100 = fy(alpha, courbe_1100_800);

% === Ajout manuel du point (0,0) pour éviter dérive lors de l’interpolation ===
if ~ismember(0, alpha)
    alpha = sort([alpha, 0]);  % ajout explicite de SA = 0
    
    % Interpoler les nouvelles courbes à la nouvelle grille alpha
    fy500  = interp1(alpha(alpha~=0), fy500, alpha, 'linear', 'extrap');
    fy800  = interp1(alpha(alpha~=0), fy800, alpha, 'linear', 'extrap');
    fy1100 = interp1(alpha(alpha~=0), fy1100, alpha, 'linear', 'extrap');
end

% Forcer FY = 0 exactement en alpha = 0 (sécurité numérique)
fy500(alpha == 0)  = 0;
fy800(alpha == 0)  = 0;
fy1100(alpha == 0) = 0;

%% FIGURE 1 : courbes FY vs SA pour 3 niveaux de FZ
figure
plot(alpha, fy500, 'b', 'LineWidth', 1.5); hold on;
plot(alpha, fy800, 'r', 'LineWidth', 1.5);
plot(alpha, fy1100, 'g', 'LineWidth', 1.5);
grid on
xlabel('Slip Angle SA (°)')
ylabel('Force latérale FY (N)')
legend('FZ = 200–500 N', 'FZ = 500–800 N', 'FZ = 800–1100 N')
title('Courbes FY vs SA pour différents FZ')

%% FIGURE 2 : surface 3D interpolée FY = f(SA, FZ)
% Grille de valeurs continues de FZ
[ALPHA, FZ] = meshgrid(alpha, linspace(-1500, -300, 100));

% Interpolation de FY sur la grille
FY_matrix = zeros(size(ALPHA));
for i = 1:length(alpha)
    % Données FY connues aux 3 niveaux de FZ
    fz_data = [-950, -650, -350]; % moyennes
    fy_data = [fy1100(i), fy800(i), fy500(i)];
    
    % Interpolation linéaire FY en fonction de FZ
    FY_matrix(:, i) = interp1(fz_data, fy_data, FZ(:, i), 'linear', 'extrap');
end

% Affichage de la surface interpolée
figure
surf(ALPHA, FZ, FY_matrix)
hold on
contour3(ALPHA, FZ, FY_matrix, 50, 'k', 'LineWidth', 0.3)
colormap('parula')
xlabel('Slip Angle SA (°)')
ylabel('Charge verticale FZ (N)')
zlabel('Force latérale FY (N)')
title('Surface interpolée FY = f(SA, FZ)')
shading interp
colorbar
view(45, 25)
grid on

% Vérification que FY = 0 à SA = 0
fprintf('FY interpolé à SA = 0° pour FZ = -650 N : %.4f N\n', ...
    interp1(fz_data, [fy1100(alpha==0), fy800(alpha==0), fy500(alpha==0)], -650));

% Sauvegarde des données interpolées dans un fichier .mat
save('donnees_interpolees_SA.mat', 'ALPHA', 'FZ', 'FY_matrix', 'alpha', 'fy500', 'fy800', 'fy1100');

%% Fonction FY selon Pacejka
function fy = fy(alpha, p)
    alpha_rad = alpha * pi / 180;
    fy = p(3) * sin(p(2) * atan(p(1) * alpha_rad - p(4) * (p(1) * alpha_rad - atan(p(1) * alpha_rad))));
end
