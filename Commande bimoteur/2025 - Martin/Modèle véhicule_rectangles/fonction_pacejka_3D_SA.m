function fy = fonction_pacejka_3D_SA(fz_input, alpha_input)
    % fonction_pacejka_3D_SA - Interpole FY à partir d'un alpha et FZ donnés

    persistent ALPHA FZ FY_matrix

    if isempty(ALPHA)
        % Charger les données une seule fois
        data = load('donnees_interpolees_SA.mat');  % Assure-toi que ce fichier est dans le path

        ALPHA = data.ALPHA;
        FZ = data.FZ;
        FY_matrix = data.FY_matrix;
    end

    % Interpolation bilinéaire
    fy = interp2(ALPHA, FZ, FY_matrix, alpha_input, fz_input, 'linear');

    % Optionnel : gérer les cas hors domaine
    if isnan(fy)
        warning('Valeur hors du domaine d''interpolation SA. Résultat = NaN');
    end
end
