function fx = fonction_pacejka_3D_SL(fz_input, sl_input)
    % get_admissible_fx - Interpole FX à partir d'un sl et FZ donnés
    % INPUTS:
    %   fz_input     - Force normale (N), ex: -750
    %   sl_input  - Slip ratio, ex: 0.1
    % OUTPUT:
    %   fx_admissible - Force longitudinale interpolée FX (N)

    % Charger les données sauvegardées
    data = load('donnees_interpolees_SL.mat'); % Assure-toi que ce fichier est dans le chemin

    % Extraire les grilles
    SL = data.SL;
    FZ = data.FZ;
    FX_matrix = data.FX_matrix;

    % Interpolation bilinéaire
    fx = interp2(SL, FZ, FX_matrix, sl_input, fz_input, 'linear');

    % Optionnel : gérer les cas hors domaine
    if isnan(FX_matrix)
        warning('Valeur hors du domaine d''interpolation. Résultat = NaN');
    end
end