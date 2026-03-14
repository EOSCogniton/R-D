%% === Optimisation des gains Kp et Ki pour la meilleure vitesse à 75m ===
clear; clc; close all;

% === Paramètres d’exploration ===
Kp_values = linspace(0,5000,10);
Ki_values = linspace(0,5,5);

% Matrice de stockage des vitesses à 75m
results = zeros(length(Kp_values), length(Ki_values));

%% === Boucle principale ===
for i = 1:length(Kp_values)
    for j = 1:length(Ki_values)

        % --- Définir les gains ---
        K_p = Kp_values(i);
        K_I = Ki_values(j);
        fprintf('\n=== Simulation avec Kp = %.3f, Ki = %.3f ===\n', K_p, K_I);

        % --- Initialisation des données véhicule ---
        run('main_data_vehicle.m');

        % --- Lancer la simulation Simulink ---
        simOut = sim('step_response_torque', 'ReturnWorkspaceOutputs', 'on');
        out = simOut;  % pour compatibilité avec trace_trajectoire

        % --- Trajectoire et vitesse à 75 m ---
        vx_75 = trace_trajectoire(out,Ts);

        % --- Stockage du résultat ---
        results(i, j) = vx_75;
        fprintf('→ v_x(75 m) = %.2f m/s\n', vx_75);

        % Option : fermer les figures pour accélérer les boucles
        close all;
    end
end

%% === Analyse finale ===
disp('=== Tableau des vitesses à 75 m ===');
disp(array2table(results, ...
    'VariableNames', compose('Ki_%.3f', Ki_values), ...
    'RowNames', compose('Kp_%.3f', Kp_values)));

% Trouver les meilleurs gains
[max_val, idx] = max(results(:));
[i_best, j_best] = ind2sub(size(results), idx);
Kp_best = Kp_values(i_best);
Ki_best = Ki_values(j_best);

fprintf('\n🏁 Meilleure vitesse : %.2f m/s obtenue pour Kp = %.3f, Ki = %.3f\n', ...
    max_val, Kp_best, Ki_best);

% Visualisation 3D
figure;
surf(Ki_values, Kp_values, results);
xlabel('K_I'); ylabel('K_P'); zlabel('v_x @ 75m (m/s)');
title('Performance du correcteur PI');
grid on;
 