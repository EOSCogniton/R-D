function fy = fonction_pacejka_3D_SA(fz_input, alpha_input)
    % get_admissible_fy - Interpole FY à partir d'un alpha et FZ donnés
    % INPUTS:
    %   fz_input     - Force normale (N), ex: -750
    %   alpha_input  - Slip angle (degrés), ex: 5
    % OUTPUT:
    %   fy_admissible - Force latérale interpolée FY (N)

    % Charger les données sauvegardées
    data = load('donnees_interpolees_SA.mat'); % Assure-toi que ce fichier est dans le chemin

    % Extraire les grilles
    ALPHA = data.ALPHA;
    FZ = data.FZ;
    FY_matrix = data.FY_matrix;

    % Interpolation bilinéaire
    fy = interp2(ALPHA, FZ, FY_matrix, alpha_input, fz_input, 'linear');

    % Optionnel : gérer les cas hors domaine
    if isnan(fy)
        warning('Valeur hors du domaine d''interpolation SA. Résultat = NaN');
        fy
    end
end
