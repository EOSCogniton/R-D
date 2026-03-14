t=0:0.1:10;
plot(t,angle_roue(t))

function theta = angle_roue(t)
    % Fonction pour modéliser l'angle de roue d'un double changement de voie
    % Entrée :
    %   t : vecteur ou scalaire temps
    % Sortie :
    %   theta : angle de roue correspondant à chaque t

    theta = zeros(size(t));  % Initialisation

    % Intervalle actif : [2,8]
    idx = (t > 2) & (t < 8);
    
    % Fonction sinus entre 2 et 8 (période complète sur 6 secondes)
    theta(idx) = sin(3*pi * (t(idx) - 2) / 6);
end
