function fy = fonction_pacejka_3D_SA(fz_input, alpha_input)
    % Interpole FY à partir d'un alpha et FZ donnés, sans recharger les données à chaque appel

    % Déclarer des variables persistantes
    persistent ALPHA FZ FY_matrix

    % Si les données ne sont pas encore chargées, on les charge une seule fois
    if isempty(ALPHA)
        data = load('donnees_interpolees_SA.mat'); % Une seule fois !
        ALPHA = data.ALPHA;
        FZ = data.FZ;
        FY_matrix = data.FY_matrix;
    end

    % Interpolation bilinéaire
    fy = interp2(ALPHA, FZ, FY_matrix, alpha_input, fz_input, 'linear');

    % Gérer les cas hors domaine
    if isnan(fy)
        warning('Valeur hors du domaine d''interpolation. Résultat = NaN');
    end
end
