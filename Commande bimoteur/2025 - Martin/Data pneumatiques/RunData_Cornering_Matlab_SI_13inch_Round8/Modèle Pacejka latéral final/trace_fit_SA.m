% Paramètres des courbes (format : [B C D E Sh])
courbe_1100_800 = [8.48 -1.72 2588.2 -0.11 63.63];
courbe_800_500  = [10.48 -1.75 1784.7 0.44 37.55];
courbe_500_200  = [10.38 -2.21 1007.6 1.13 1.18];

% Valeurs d'angle de glissement
alpha = -10:0.01:10;

% Calcul des FY pour les 3 charges
fy500  = fy(alpha, courbe_500_200);
fy800  = fy(alpha, courbe_800_500);
fy1100 = fy(alpha, courbe_1100_800);

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
[ALPHA, FZ] = meshgrid(alpha, linspace(-1000, -300, 100));

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
colormap('parula')  % Couleurs 
xlabel('Slip Angle SA (°)')
ylabel('Charge verticale FZ (N)')
zlabel('Force latérale FY (N)')
title('Surface interpolée FY = f(SA, FZ)')
shading interp
colorbar
view(45, 25)
grid on

% Sauvegarde des données interpolées dans un fichier .mat
save('donnees_interpolees.mat', 'ALPHA', 'FZ', 'FY_matrix', 'alpha', 'fy500', 'fy800', 'fy1100');


%% Fonction FY selon Pacejka
function fy = fy(alpha, p)
    alpha_rad = alpha * pi / 180;
    fy = p(3) * sin(p(2) * atan(p(1) * alpha_rad - p(4) * (p(1) * alpha_rad - atan(p(1) * alpha_rad)))) + p(5);
end
