m=230; %masse avec pilote, kg
a=0.9; %distance CG/essieu avant, m
b=0.7; %distance CG/essieu arrière, m
Cr=70000; %front cornering stiffness, N/rad
Cf=70000; %front cornering stiffness, N/rad
tr=1.2; %rear track, m
r_wheels=0.470/2; %rayon roues, m
delta_skidpad=0.17*180/pi; %angle ackermann l/R pour le skidpad

Ku=m/(a+b)*(b/Cf-a/Cr); %understeer gradient en steady

Tr=0.5; %position de la pédale entre 0 et 1
w_wheels=[450 500]; % [RL RR], rpm

T=50; %couple dispo en nominal, Nm
G=4; %réduction au secondaire

