% --- Simulation avec TV = 0 ---
TV = 0;
sim('main');

% Extraire phi_dot
phi_dot_0 = out.phi_dot.signals.values;
t0        = out.phi_dot.time;

% --- Simulation avec TV = 1 ---
TV = 1;
sim('main');

% Extraire phi_dot
phi_dot_1 = out.phi_dot.signals.values;
t1        = out.phi_dot.time;

% --- Tracé comparatif ---
figure;
plot(t0, phi_dot_0, 'b', 'DisplayName', 'TV = 0');
hold on;
plot(t1, phi_dot_1, 'r--', 'DisplayName', 'TV = 1');
xlabel('Temps (s)');
ylabel('\phi\_dot (rad/s)');
title('Comparaison de \phi\_dot pour TV = 0 et TV = 1');
legend('show');
grid on;
