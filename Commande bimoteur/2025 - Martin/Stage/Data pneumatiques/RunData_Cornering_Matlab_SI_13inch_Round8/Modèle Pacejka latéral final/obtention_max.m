y = fonction_pacejka_3D_SA(-1420, sa); % calcul de la fonction
plot(sa, y)
hold on

% Chercher le maximum
[val_max, idx_max] = max(y);
sa_max = sa(idx_max);

% Marquer le point
plot(sa_max, val_max, 'ro', 'MarkerSize', 8, 'LineWidth', 1.5)

% Ajouter une annotation complète
text(sa_max, val_max, ...
    sprintf('Max = %.2f à sa = %.2f', val_max, sa_max), ...
    'VerticalAlignment', 'bottom', 'HorizontalAlignment', 'right')

hold off
