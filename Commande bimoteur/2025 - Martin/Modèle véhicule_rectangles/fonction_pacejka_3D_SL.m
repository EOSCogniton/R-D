function fx = fonction_pacejka_3D_SL(fz_input, sl_input)
    % fonction_pacejka_3D_SL - Interpole FX à partir d'un slip ratio et FZ donnés

    persistent SL FZ FX_matrix

    if isempty(SL)
        % Charger les données une seule fois
        data = load('donnees_interpolees_SL.mat');  % Le fichier doit être dans le path

        SL = data.SL;
        FZ = data.FZ;
        FX_matrix = data.FX_matrix;
    end

    % Interpolation bilinéaire
    fx = interp2(SL, FZ, FX_matrix, sl_input, fz_input, 'linear');

    % Gérer les valeurs hors domaine
    if isnan(fx)
        warning('Valeur hors du domaine d''interpolation SL. Résultat = NaN');
    end
end
