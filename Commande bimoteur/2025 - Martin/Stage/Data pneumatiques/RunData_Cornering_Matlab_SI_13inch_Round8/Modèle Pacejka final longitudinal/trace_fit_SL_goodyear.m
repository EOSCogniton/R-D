%% Paramètres Pacejka pour FX à FZ = 1050 N
courbe_1050 = [12, 1.55, 1500, -1]; % remplace B_value, C_value, ... par tes valeurs

%% Valeurs de slip ratio
sl = -1:0.001:1;

%% Calcul de FX pour FZ = 1050 N
fx1050 = fx(sl, courbe_1050);

%% Ajout du point SL = 0, FX = 0 si nécessaire
if ~ismember(0, sl)
    sl = sort([sl, 0]);
    fx1050 = interp1(sl(sl~=0), fx1050, sl, 'linear', 'extrap');
end

% Forçage explicite à FX = 0 pour SL = 0
fx1050(sl == 0) = 0;

%% FIGURE : courbe FX vs SL pour FZ = 1050 N
figure
plot(sl, fx1050, 'b', 'LineWidth', 1.5);
grid on
xlabel('Slip Ratio SL')
ylabel('Force longitudinale FX (N)')
title('Courbe FX vs SL pour FZ = 1050 N')
legend('FZ = 1050 N')

%% Fonction FX selon Pacejka
function fx = fx(sl, p)
    fx = p(3) * sin(p(2) * atan(p(1) * sl - p(4) * (p(1) * sl - atan(p(1) * sl))));
end
