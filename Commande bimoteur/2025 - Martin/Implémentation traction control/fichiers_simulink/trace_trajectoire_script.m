
% Lancer la simulation
% sim('main');  % Simule ton modèle

% Extraire les données depuis les variables simulink
vx_data = out.v_x.signals.values;
vy_data = out.v_y.signals.values;
phi     = out.phi.signals.values;       % angle de lacet (psi)
t       = out.v_x.time;                 % vecteur temps
%T_RL = out.T_RL.signals.values;
%T_RR = out.T_RR.signals.values;

% Pas de temps
dt = Ts ;  % supposé constant

% Initialisation des positions (x0 = y0 = 0)
x_calc = zeros(length(t), 1);
y_calc = zeros(length(t), 1);

% Intégration numérique : méthode d’Euler
for k = 2:length(t)
    x_dot = vx_data(k-1)*cos(phi(k-1)) - vy_data(k-1)*sin(phi(k-1));
    y_dot = vx_data(k-1)*sin(phi(k-1)) + vy_data(k-1)*cos(phi(k-1));
    
    x_calc(k) = x_calc(k-1) + x_dot * dt;
    y_calc(k) = y_calc(k-1) + y_dot * dt;
end

% Calcul de la vitesse absolue
v_abs = sqrt(vx_data.^2 + vy_data.^2);

% Tracer la trajectoire recalculée colorée par la vitesse
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

% === Marquage du point où la distance parcourue atteint 75 m ===

dx = diff(x_calc);
dy = diff(y_calc);
distance_cum = [0; cumsum(sqrt(dx.^2 + dy.^2))];

idx_75 = find(distance_cum >= 75, 1, 'first');

if ~isempty(idx_75)
    x_75 = x_calc(idx_75);
    y_75 = y_calc(idx_75);
    vx_75 = vx_data(idx_75);

    figure(3);
    hold on;
    plot(x_75, y_75, 'ro', 'MarkerSize', 10, 'LineWidth', 2);

    % Ajout d’un léger décalage vertical pour la lisibilité (par ex. +2 m)
    text(x_75, y_75 + 2, sprintf('v_x = %.2f m/s', vx_75), ...
         'Color', 'r', 'FontWeight', 'bold', 'FontSize', 10, ...
         'HorizontalAlignment', 'left');

    disp(['🔹 v_x à 75 m : ', num2str(vx_75), ' m/s']);
else
    warning('La trajectoire ne dépasse pas 75 m — aucun point marqué.');
end



% === Bloc additionnel : Tracé de phi_dot, v_x et beta ===
% Extraction des autres signaux
phi_dot = out.phi_dot.signals.values;
beta    = out.beta.signals.values;
target  = out.target_yaw.signals.values;

% Création de la figure pour les signaux
figure(1);
subplot(3,1,1);
plot(t, phi_dot, 'b');
xlabel('Temps (s)');
ylabel('\phi\_dot (rad/s)');
title('Évolution de \phi\_dot');
hold on;
grid on;

subplot(3,1,2);
plot(t, vy_data, 'r');
xlabel('Temps (s)');
ylabel('v_y (m/s)');
title('Évolution de v_y');
hold on;
grid on;

subplot(3,1,3);
plot(t, beta, 'g');
xlabel('Temps (s)');
ylabel('\beta (deg)');
title('Évolution de \beta');
hold on;
grid on;

figure(2);
plot(t,phi_dot, 'DisplayName', 'Actual yaw rate')
hold on;
plot(t,target,'DisplayName','Target yaw rate')
%hold off
legend

% figure(4);
% plot(t,T_RL, 'DisplayName', 'Rear left torque')
% hold on;
% plot(t,T_RR,'DisplayName','Rear right torque')
% %hold off
% legend

% % main_data_vehicle

