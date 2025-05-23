    @	   	   ��	  P � � �	 S M I   C o r p o r a t i o n                               U S B   D I S K                                                                                                                           
    @ 	   ��	  P �@ �@ � �smiSMI     USB DISK        1100                  =�  ��?�   �  (_   0P      �  f!!� H  �P0219   P0219       #   3259AA_P0219 ���----------------------------------%
%Grandeurs issues de la simulation
%-------------------------------------------------------------------------%
l_f=1;                      %Distance entre le centre de gravité et l'axe des roues avant (m)
l_r=1;                      %Distance entre le centre de gravité et l'axe des roues arrière (m)
L=l_r+l_f;                  %Distance inter-axes des roues
h=0.4;                      %Hauteur du centre de gravité au repos (m)
A_L=1;                      %Surface offerte au vent de face (m^2)
A_S=3;                      %Surface offerte au vent latéralement (m^2)
Iz=500;                     %Inertie du véhicule selon son axe vertical (kg.m^2)
C_aero=0.2.*[1 1 1];        %Matrice des coefficients de trainée dans la direction i
J=[1 1 1 1];                %Matrice des inerties selon l'axe de rotation pour chaque roue
f=0.1;                      %Coef cr_mot
%-------------------------------------------------------------------------%
%Constantes générales
%-------------------------------------------------------------------------%
g=9.81;             %Constante d'accélération terrestre (m.s^-2)
B=10;           %B Pacejka
C=1.9;          %C Pacejka
D=1;            %D Pacejka
E=0.97;         %E Pacejka
C_x=1;              %Coef de résistance aérodynamique de l'air
M=400;              %Masse totale du véhicule (kg)
rho=1;             %Masse volumique de l'air (kg/m^3)
P=20*10e3;         %Puissance du moteur choisi (W)

%-------------------------------------------------------------------------%
%Entrées
%-------------------------------------------------------------------------%

C_M=[0 0 1000 1000];    %Couple moteur choisi (Nm)
C_F=[0 0 0 0];          %Couple de frein (Nm) (juste pour les tests)
V_cons=10/3.6;
