function vx_75 = trace_trajectoire(out,Ts)
% TRACE_TRAJECTOIRE
% Recalcule la trajectoire à partir des sorties Simulink
% et renvoie la vitesse v_x au moment où la distance cumulée atteint 75 m.

    % === Extraire les données depuis les variables simulink ===
    
    vx_data = out.v_x;
    vy_data = out.v_y;
    phi     = out.phi;       % angle de lacet (psi)
    t       = 0:Ts:10;     % vecteur temps


    % Pas de temps
    dt = Ts;  % supposé constant

    % === Intégration numérique ===
    x_calc = zeros(length(t), 1);
    y_calc = zeros(length(t), 1);

    for k = 2:length(t)
        x_dot = vx_data(k-1)*cos(phi(k-1)) - vy_data(k-1)*sin(phi(k-1));
        y_dot = vx_data(k-1)*sin(phi(k-1)) + vy_data(k-1)*cos(phi(k-1));

        x_calc(k) = x_calc(k-1) + x_dot * dt;
        y_calc(k) = y_calc(k-1) + y_dot * dt;
    end

    % === Calcul de la vitesse absolue ===
    v_abs = sqrt(vx_data.^2 + vy_data.^2);

    % === Tracé de la trajectoire ===
    figure(3);
    scatter(x_calc, y_calc, 10, v_abs, 'filled');
    xlabel('Position X (m)');
    ylabel('Position Y (m)');
    title('Trajectoire recalculée à partir de v_x, v_y et \phi');
    colormap(jet);
    colorbar;
    grid on;
    axis equal;
    hold on;

    % === Calcul du point à 75 m ===
    dx = diff(x_calc);
    dy = diff(y_calc);
    distance_cum = [0; cumsum(sqrt(dx.^2 + dy.^2))];
    idx_75 = find(distance_cum >= 75, 1, 'first');

    if ~isempty(idx_75)
        x_75 = x_calc(idx_75);
        y_75 = y_calc(idx_75);
        vx_75 = vx_data(idx_75);

        plot(x_75, y_75, 'ro', 'MarkerSize', 10, 'LineWidth', 2);
        text(x_75, y_75 + 2, sprintf('v_x = %.2f m/s', vx_75), ...
             'Color', 'r', 'FontWeight', 'bold', 'FontSize', 10, ...
             'HorizontalAlignment', 'left');

        disp(['🔹 v_x à 75 m : ', num2str(vx_75), ' m/s']);
    else
        warning('La trajectoire ne dépasse pas 75 m — aucun point marqué.');
        vx_75 = NaN;
    end

   
end
