%-------------------------------------------------------------------------%
%Grandeurs géométriques 
%-------------------------------------------------------------------------%
d_f=1;          %Longueur inter-roues avant
d_r=1;          %Longueur inter-roues arrière
R=[0.52 0.52 0.52 0.52];    %Matrice contenant les rayons des roues
Mroue=[5 5 5 5];

%-------------------------------------------------------------------------%
%Grandeurs issues de la simulation
%-------------------------------------------------------------------------%
l_f=1.7;                    %Distance entre le centre de gravité et l'axe des roues avant (m)
l_r=1.2;                    %Distance entre le centre de gravité et l'axe des roues arrière (m)
L=l_r+l_f;                  %Distance inter-axes des roues
h=0.4;                      %Hauteur du centre de gravité au repos (m)
A_L=1;                      %Surface offerte au vent de face (m^2)
A_S=3;                      %Surface offerte au vent latéralement (m^2)
Iz=500;                     %Inertie du véhicule selon son axe vertical (kg.m^2)
C_aero=0.2.*[1 1 1];        %Matrice des coefficients de trainée dans la direction i
J=Mroue.*R.^2./2;                %Matrice des inerties selon l'axe de rotation pour chaque roue
f=0.1;                      %Coef cr_mot
%-------------------------------------------------------------------------%
%Constantes générales
%-------------------------------------------------------------------------%
g=9.81;             %Constante d'accélération terrestre (m.s^-2)
Cte_1=10;           %B Pacejka
Cte_2=1.9;          %C Pacejka
Cte_3=1;            %D Pacejka
Cte_4=0.97;         %E Pacejka
C_x=0.2;              %Coef de résistance aérodynamique de l'air
M=400;              %Masse totale du véhicule (kg)
m=M/4.*[l_f/L l_f/L l_r/L l_r/L];        %Matrice des masses équivalentes portées par chaque suspension (kg)
rho=1;             %Masse volumique de l'air (kg/m^3)
P=20e3;         %Puissance du moteur choisi (W)
C_M=1000;          %Couple moteur choisi (Nm)