Cf=2*27788; %cornering stiffness, front (N/rad)
Cr=2*31570; %cornering stiffness, rear (N/rad)
m=240; %masse
Izz=120;
vx=[5 10 15 20 25 30 35 40];
s=tf('s');
G = cell(1, length(vx));
K = cell(1, length(vx));

xi=0.69;
wn=6;
Mref=1/(s^2/wn^2+2*xi/wn*s+1);
Lref=Mref/(1-Mref);

for i=1:length(vx)
    a11=-(Cr+Cf)/(m*vx(i));
    a12=(-m*vx(i)^2-Cf*lf+Cr*lr)/(m*vx(i));
    a21=(lr*Cr-lf*Cf)/(Izz*vx(i));
    a22=-(Cf*lf^2+Cr*lr^2)/(Izz*vx(i));
    b11=Cf/(m*vx(i));
    b21=lf*Cf/Izz;
    b22=1/Izz;

    G{i}=b22*(s-a11)/((s-a11)*(s-a22)-a12*a21);
    K{i}=Lref/G{i};
end

% Supposons que K est une cellule de fonctions de transfert
% Exemple :
% K{1} = tf([1 3], [1 5]);
% K{2} = tf([1 2], [1 0]);

K_tab = cell(length(K), 2); % préallocation

for i = 1:length(K)
    [num, den] = tfdata(K{i}, 'v'); % 'v' donne les vecteurs directement
    K_tab{i,1} = num;
    K_tab{i,2} = den;
end


tr=1.2; %rear track, m
r_wheels=0.470/2; %rayon roues, m
delta_skidpad=1.6/9.125*180/pi; %angle ackermann l/R pour le skidpad

Ku=m/(lf+lr)*(lr/Cf-lf/Cr); %understeer gradient en steady

Tr=0.5; %position de la pédale entre 0 et 1
w_wheels=[450 500]; % [RL RR], rpm

T=50; %couple dispo en nominal, Nm
G=4; %réduction au secondaire

