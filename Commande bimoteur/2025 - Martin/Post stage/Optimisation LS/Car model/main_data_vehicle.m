m=265; %masse véhicule
g=9.81; %pesanteur
fr=0.51; %répartition R/F
h=0.29; %hauteur COG
L=1.55; %empattement
t=1.3; %largeur
A=1; %surface frontale véhicule
rho=1.225; %masse volumique air
CL=0.2; %coeff portance
CD=0.9; %coeff trainee
Re=0.235; %rayon extérieur roues chargées
J=0.9; %moment d'inertie d'une roue, à préciser
lf=L*fr; %distance COG à l'essieu avant
lr=L-lf; %distance COG à l'essieu arrière
bf=t/2; %demi largeur avant
br=t/2; %demi largeur arrière
Ts=0.001; %période d'échantillonage
Izz=180; %inertie selon l'axe z, à préciser 
v0=0; %vitesse initiale pour la simulation
Crr=0.02; %coeff de résistance au roulement
Frr=Crr*m*g; %frottements solides
TV=0; %0 ou 1, active le torque vectoring
TC=0;
TirePressure=65e3; %pression pneu
TireGripFactor=0.7;



