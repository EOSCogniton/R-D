m=275; %masse véhicule
g=9.81; %pesanteur
fr=0.51; %répartition R/F
h=0.29; %hauteur COG
L=1.55; %empattement
t=1.3; %largeur
A=1; %surface frontale véhicule
rho=1.225; %masse volumique air
CL=0.29; %coeff portance
CD=2; %coeff trainee
Re=0.259; %rayon extérieur roues chargées
J=0.8; %moment d'inertie d'une roue, à préciser
lf=L*fr; %distance COG à l'essieu avant
lr=L-lf; %distance COG à l'essieu arrière
bf=t/2; %demi largeur avant
br=t/2; %demi largeur arrière
Ts=0.001; %période d'échantillonage
Izz=180; %inertie selon l'axe z, à préciser 
v0=3; %vitesse initiale pour la simulation
Crr=0.02; %coeff de résistance au roulement
Frr=Crr*m*g; %frottements solides
gyro=1; %0 ou 1, active le terme gyroscopique des PFD, laisser à 1
LT=1; %0 ou 1, active le calcul des transferts de charge
delta_skidpad=L/9.125*180/pi; %neutral steer angle pour skidpad en degré
TV=1; %0 ou 1, active le torque vectoring
TC=0;
epsilon=0.1; %pour éviter les divisions par 0 dans le calcul du SR
mu_tires=1.2; %coeff de frottement pneu
TirePressure=65e3; %pression pneu



