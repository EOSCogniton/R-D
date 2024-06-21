%-------------------------------------------------------------------------%
%Grandeurs géométriques 
%-------------------------------------------------------------------------%
d_f=1;          %Longueur inter-roues avant
d_r=1;          %Longueur inter-roues arrière
R=[1 1 1 1];    %Matrice contenant les rayons des roues

%-------------------------------------------------------------------------%
%Grandeurs issues de la simulation
%-------------------------------------------------------------------------%
l_f=1;                      %Distance entre le centre de gravité et l'axe des roues avant (m)
l_r=1;                      %Distance entre le centre de gravité et l'axe des roues arrière (m)
L=l_r+l_f;                  %Distance inter-axes des roues
h=1;                        %Hauteur du centre de gravité au repos (m)
A_L=1;                      %Surface offerte au vent de face (m^2)
A_S=1;                      %Surface offerte au vent latéralement (m^2)
I=[2 0 0; 0 3 0; 0 0 3];    %Matrice d'inertie du véhicule (kg.m^2)
C_aero=[1 1 1];             %Matrice des coefficients de trainée dans la direction i
J=[1 1 1 1];                %Matrice des inerties selon l'axe de rotation pour chaque roue

%-------------------------------------------------------------------------%
%Constantes générales
%-------------------------------------------------------------------------%
g=9.81;             %Constante d'accélération terrestre (m.s^-2)
Cte_1=1;            %B Pacejka
Cte_2=1;            %C Pacejka
Cte_3=1;            %D Pacejka
Cte_4=1;            %E Pacejka
%Cte_5=1;            %Constantes du modèle de contact du pneu avec la route
k_route=[1 1 1 1];  %Matrice des raideurs de la route sous la roue i (N/m)
c_route=[1 1 1 1];  %Matrice des coefs d'amortissement de la route sous la roue i (N.s/m)
C_x=1;              %Coef de résistance aérodynamique de l'air
M=400;              %Masse totale du véhicule (kg)
m=M/4.*[l_f/L l_f/L l_r/L l_r/L];        %Matrice des masses équivalentes portées par chaque suspension (kg)
k=30000.*[1 1 1 1];        %Matrice des raideurs des suspensions de la roue i (N/m)
c=2000.*[1 1 1 1];        %Matrice des coefs d'amortissement des suspensions de la roue i (N.s/m)
k_roue=[1 1 1 1];  %Matrice des raideurs de la roue i (N/m)
c_roue=[1 1 1 1];  %Matrice des coefs d'amortissement de la roue i (N.s/m)
rho=1;             %Masse volumique de l'air (kg/m^3)
P=20*10e3;         %Puissance du moteur choisi (W)
C_M=1000;          %Couple moteur choisi (Nm)