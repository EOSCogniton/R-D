C_yf=15000; %cornering stiffness, front (N/rad)
C_yr=20000; %cornering stiffness, rear (N/rad)
m=240; %masse
v_x0=20; %vitesse longitudinale (m/s)
l_f=0.9; %distance CG/essieu avant (m)
l_r=0.7;
I_zz=120; %moment d'inertie
Ts=0.001; %période d'échantillonage

% Termes de la matrice d'état (2x2)
A = -(C_yf + C_yr) / (m * v_x0);
B = (-l_f*C_yf + l_r*C_yr) / (m * v_x0) - v_x0;
C = (-l_f*C_yf + l_r*C_yr) / (I_zz * v_x0);
D = -(l_f^2*C_yf + l_r^2*C_yr) / (I_zz * v_x0);

% Termes du vecteur de commande (2x1)
E = C_yf / (m * v_x0);
F = (l_f * C_yf) / I_zz;