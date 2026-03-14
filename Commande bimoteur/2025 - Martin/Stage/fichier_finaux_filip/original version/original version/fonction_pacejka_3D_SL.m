function fx = fonction_pacejka_3D_SL(fz_input, sl_input)
    % Interpole FX à partir d'un slip ratio et FZ donnés sans recharger à chaque appel

    % Variables persistantes pour éviter le rechargement à chaque appel
    persistent SL FZ FX_matrix

    % Chargement unique des données
    if isempty(SL)
        data = load('donnees_interpolees_SL.mat');  % Chargement une seule fois
        SL = data.SL;
        FZ = data.FZ;
        FX_matrix = data.FX_matrix;
    end

    % Interpolation bilinéaire
    fx = interp2(SL, FZ, FX_matrix, sl_input, fz_input, 'linear');

    % Gestion des cas hors domaine
    if isnan(fx)
        warning('Valeur hors du domaine d''interpolation SL. Résultat = NaN');
    end
end
