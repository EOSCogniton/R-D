%% Lecture du CSV

filename = "skidpad_olap_v2.csv";
data = readmatrix(filename,'NumHeaderLines',68);

%% Couper les données avant les NaN

% data = data(1:1297,:);   % garder seulement les lignes valides

%% Extraction des colonnes d'intérêt

vitesse  = data(:,1);    % colonne A
distance = data(:,3);    % colonne B
aYaw     = data(:,21);   % colonne W
x        = data(:,24);   % colonne X
y        = data(:,25);   % colonne Y

%% Création de la table MATLAB

lapData = table(distance, vitesse, x, y, aYaw);