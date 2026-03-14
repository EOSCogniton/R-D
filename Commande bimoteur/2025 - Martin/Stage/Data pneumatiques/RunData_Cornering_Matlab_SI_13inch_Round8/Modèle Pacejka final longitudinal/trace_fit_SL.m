%% Paramètres des courbes Pacejka pour FX (format : [B C D E])
courbe_1100_800 = [19.79 0.95 2380.6 -1.17];
courbe_800_500  = [16.42 1.17 1407.8 -0.48];
courbe_500_200  = [15.28 1.51 461.4 0.63];

%% Valeurs de slip ratio
sl = -1:0.001:1;

%% Calcul des FX pour les 3 charges
fx500  = fx(sl, courbe_500_200);
fx800  = fx(sl, courbe_800_500);
fx1100 = fx(sl, courbe_1100_800);

%% Ajout du point SL = 0, FX = 0 si nécessaire
if ~ismember(0, sl)
    sl = sort([sl, 0]);  % ajoute SL = 0

    % Réinterpolation des courbes pour s'ajuster à la nouvelle grille SL
    fx500  = interp1(sl(sl~=0), fx500, sl, 'linear', 'extrap');
    fx800  = interp1(sl(sl~=0), fx800, sl, 'linear', 'extrap');
    fx1100 = interp1(sl(sl~=0), fx1100, sl, 'linear', 'extrap');
end

% Forçage explicite à FX = 0 pour SL = 0
fx500(sl == 0)  = 0;
fx800(sl == 0)  = 0;
fx1100(sl == 0) = 0;

%% FIGURE 1 : courbes FX vs SL pour 3 niveaux de FZ
figure
plot(sl, fx500, 'b', 'LineWidth', 1.5); hold on;
plot(sl, fx800, 'r', 'LineWidth', 1.5);
plot(sl, fx1100, 'g', 'LineWidth', 1.5);
grid on
xlabel('Slip Ratio SL')
ylabel('Force longitudinale FX (N)')
legend('FZ = 200–500 N', 'FZ = 500–800 N', 'FZ = 800–1100 N')
title('Courbes FX vs SL pour différents FZ')

%% FIGURE 2 : surface 3D interpolée FX = f(SL, FZ)
% Grille de valeurs continues de FZ
[SL, FZ] = meshgrid(sl, linspace(-1000, -300, 100));

% Interpolation de FX sur la grille
FX_matrix = zeros(size(SL));
for i = 1:length(sl)
    % Données FX connues aux 3 niveaux de FZ
    fz_data = [-950, -650, -350]; % moyennes
    fx_data = [fx1100(i), fx800(i), fx500(i)];
    
    % Interpolation linéaire FX en fonction de FZ
    FX_matrix(:, i) = interp1(fz_data, fx_data, FZ(:, i), 'linear', 'extrap');
end

% Affichage de la surface interpolée
figure
surf(SL, FZ, FX_matrix)
hold on
contour3(SL, FZ, FX_matrix, 50, 'k', 'LineWidth', 0.3)
colormap('parula')  % Couleurs
xlabel('Slip Ratio SL')
ylabel('Charge verticale FZ (N)')
zlabel('Force longitudinale FX (N)')
title('Surface interpolée FX = f(SL, FZ)')
shading interp
colorbar
view(45, 25)
grid on

% Vérification que FX = 0 à SL = 0
fprintf('FX interpolé à SL = 0 pour FZ = -650 N : %.4f N\n', ...
    interp1(fz_data, [fx1100(sl==0), fx800(sl==0), fx500(sl==0)], -650));

% Sauvegarde des données interpolées dans un fichier .mat
save('donnees_interpolees_SL.mat', 'SL', 'FZ', 'FX_matrix', 'sl', 'fx500', 'fx800', 'fx1100');

%% Fonction FX selon Pacejka
function fx = fx(sl, p)
    fx = p(3) * sin(p(2) * atan(p(1) * sl - p(4) * (p(1) * sl - atan(p(1) * sl))));
end
