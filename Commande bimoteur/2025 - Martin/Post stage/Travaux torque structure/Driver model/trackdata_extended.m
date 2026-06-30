%% Lecture du CSV

filename = "endurance_fsg2012_olap.csv";
data = readmatrix(filename,'NumHeaderLines',69);

%% Couper les données avant les NaN

% data = data(1:1297,:);   % garder seulement les lignes valides

%% Extraction des colonnes d'intérêt

vitesse  = data(:,1);    % colonne A
distance = data(:,3);    % colonne C
aYaw     = data(:,21);   % colonne U
x        = data(:,24);   % colonne X
y        = data(:,25);   % colonne Y

%% Création de la table MATLAB

lapData = table(distance, vitesse, x, y, aYaw);