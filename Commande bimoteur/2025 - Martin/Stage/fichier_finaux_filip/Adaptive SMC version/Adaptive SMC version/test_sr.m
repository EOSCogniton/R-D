SA = -10:0.01:10;
y = fcn(SA);

% Tracer la fonction
figure;
plot(SA, y, 'b', 'LineWidth', 2);
hold on;

% ----------- Bloc pour dérivée et tangente en 0 ------------

% Calcul de la dérivée en u = 0 numériquement
h = 1e-5;  % petit pas pour la dérivée
dy_du0 = (fcn(0 + h) - fcn(0 - h)) / (2*h)  % dérivée centrée

% Valeur de la fonction en 0
y0 = fcn(0);

% Equation de la tangente : y = y0 + dy_du0 * (SA - 0)
tangente = y0 + dy_du0 * SA;

% Tracer la tangente
plot(SA, tangente, 'r--', 'LineWidth', 1.5);

% Ajouter un marqueur à l’origine
plot(0, y0, 'ko', 'MarkerFaceColor', 'k');

% Affichage
legend('fcn(u)', 'Tangente en u = 0', 'Location', 'best');
xlabel('u (°)');
ylabel('fcn(u)');
title('Fonction fcn(u) et sa tangente en u = 0');
grid on;
hold off;

% ---------------------- Fonction ----------------------

function y = fcn(u)
    u_rad = pi/180 * u;
    B = 10.48;
    C = -1.75;
    D = 1784.7;
    E = 0.44;
    y = D * sin(C * atan(B * u_rad - E * (B * u_rad - atan(B * u_rad))));
end
