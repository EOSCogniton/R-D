%% ================================
% Lecture du CSV
%% ================================

filename = "endurance_fsg2012_olap.csv";
data = readmatrix(filename,'NumHeaderLines',69);

%% Extraction des colonnes

vitesse  = data(:,1);
distance = data(:,3);
x        = data(:,24);
y        = data(:,25);
psi      = data(:,21); 

%% Nettoyage NaN

valid = ~isnan(distance) & ~isnan(x) & ~isnan(y) & ~isnan(psi);
distance = distance(valid);
x = x(valid);
y = y(valid);
psi = psi(valid);

%% ================================
% Échantillonnage tous les 5 m
%% ================================

ds = 1; % espacement des cônes
s_sample = distance(1):ds:distance(end);

x_sample   = interp1(distance, x, s_sample);
y_sample   = interp1(distance, y, s_sample);
psi_sample = interp1(distance, psi, s_sample);

%% ================================
% Calcul des normales
%% ================================

psi_sample = unwrap(psi_sample);

dx = gradient(x_sample);
dy = gradient(y_sample);

norm = sqrt(dx.^2 + dy.^2);

nx = -dy ./ norm;
ny =  dx ./ norm;

% Correction de cohérence
for i = 2:length(nx)
    if nx(i)*nx(i-1) + ny(i)*ny(i-1) < 0
        nx(i) = -nx(i);
        ny(i) = -ny(i);
    end
end

% Adapter au repère Unreal
y_sample = y_sample;
ny = -ny;

%% ================================
% Génération des cônes
%% ================================

d = 3; % distance latérale (m)

leftCones  = [x_sample + d*nx; -y_sample + d*ny]';
rightCones = [x_sample - d*nx; -y_sample - d*ny]';



conesZ0 = 0;

%% ================================
% Création du sol (comme ton skidpad)
%% ================================

% trackSurface = sim3d.Actor('ActorName','TrackSurface');
% createShape(trackSurface, 'box', [200,200,0.05]);
% 
% trackSurface.Color = [0.2 0.2 0.2];
% trackSurface.Translation = [0 0 0];
% trackSurface.Shininess = 0;
% trackSurface.Transparency = 0;
% 
% World.add(trackSurface,Actor);

%% ================================
% Génération des cônes BLEUS (gauche)
%% ================================

for i = 1:size(leftCones,1)
    
    coneName = "bCone_" + num2str(i);
    conLoc = [leftCones(i,:) conesZ0];

    cone = sim3d.Actor('ActorName',coneName,...
        'Mesh','/Game/Environment/Industrial/Props/Cone/Mesh/SM_Cone_Blue.SM_Cone_Blue',...
        'Mobility', sim3d.utils.MobilityTypes.Movable,...
        'SimulatePhysics', true,...
        'Translation',conLoc,...
        'EnableGravity', true,...
        'Scale',ones(1,3).*325/500);

    World.add(cone,Actor);
end

%% ================================
% Génération des cônes JAUNES (droite)
%% ================================

for i = 1:size(rightCones,1)
    
    coneName = "yCone_" + num2str(i);
    conLoc = [rightCones(i,:) conesZ0];

    cone = sim3d.Actor('ActorName',coneName,...
        'Mesh','/Game/Environment/Industrial/Props/Cone/Mesh/SM_Cone_Yellow.SM_Cone_Yellow',...
        'Mobility', sim3d.utils.MobilityTypes.Movable,...
        'SimulatePhysics', true,...
        'Translation',conLoc,...
        'EnableGravity', true,...
        'Scale',ones(1,3).*325/500);

    World.add(cone,Actor);
end