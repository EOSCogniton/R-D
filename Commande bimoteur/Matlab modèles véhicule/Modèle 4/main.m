%====================== Paramètres de Simulation =========================%

tps=12;             %Temps de simulation en secondes
Nb=100000;            %Nombre de points
dt=tps/(Nb+1);      %Pas de temps retenu
t=linspace(0,tps,Nb+1);

%========================= Initialisation ================================%
X=zeros(39,Nb+1);

X(17,1)=C_M(1);
X(18,1)=C_M(2);
X(19,1)=C_M(3);
X(20,1)=C_M(4);

X(21,1)=C_F(1);
X(22,1)=C_F(2);
X(23,1)=C_F(3);
X(24,1)=C_F(4);

X(37,1)=V_cons;
X(38,1)=V_cons;
%============================ Evolution ==================================%

for j=2:Nb+1
    %Prise en compte des entrées
    X(17,j)=C_M(1);
    X(18,j)=C_M(2);
    X(19,j)=C_M(3);
    X(20,j)=C_M(4);

    X(21,j)=C_F(1);
    X(22,j)=C_F(2);
    X(23,j)=C_F(3);
    X(24,1)=C_F(4);
    
    X(16,j)=0;
    
    %Calcul des angle de glissement des roues
    delta=calcul_delta(X(16,j-1),L,d_f);
    Vx1=(X(38,j-1)-t_f*X(12,j-1))*cos(delta(1))+(X(39,j-1)+l_f*X(12,j-1))*sin(delta(1));
    Vy1=-(X(38,j-1)-t_f*X(12,j-1))*sin(delta(1))+(X(39,j-1)+l_f*X(12,j-1))*cos(delta(1));

    Vx2=(X(38,j-1)+t_f*X(12,j-1))*cos(delta(2))+(X(39,j-1)+l_f*X(12,j-1))*sin(delta(2));
    Vy2=-(X(38,j-1)+t_f*X(12,j-1))*sin(delta(2))+(X(39,j-1)+l_f*X(12,j-1))*cos(delta(2));

    Vx3=(X(38,j-1)-t_r*X(12,j-1))*cos(delta(3))+(X(39,j-1)-l_r*X(12,j-1))*sin(delta(3));
    Vy3=-(X(38,j-1)-t_r*X(12,j-1))*sin(delta(3))+(X(39,j-1)-l_r*X(12,j-1))*cos(delta(3));

    Vx4=(X(38,j-1)+t_r*X(12,j-1))*cos(delta(4))+(X(39,j-1)-l_r*X(12,j-1))*sin(delta(4));
    Vy4=-(X(38,j-1)+t_r*X(12,j-1))*sin(delta(4))+(X(39,j-1)-l_r*X(12,j-1))*cos(delta(4));
    X(33,j-1)=angle(Vx1+1i*Vy1)-delta(1);
    X(34,j-1)=angle(Vx2+1i*Vy2)-delta(2);
    X(35,j-1)=angle(Vx3+1i*Vy3)-delta(3);
    X(36,j-1)=angle(Vx4+1i*Vy4)-delta(4);
    
    %Calcul des coefficients de glissement
    if X(1,j-1)<0
        X(25,j-1)=(Vx1-X(8,j-1))/Vx1;
        X(26,j-1)=(Vx2-X(9,j-1))/Vx2;
        X(27,j-1)=(Vx3-X(10,j-1))/Vx3;
        X(28,j-1)=(Vx4-X(11,j-1))/Vx4;
        X(29,j-1)=tan(X(33,j-1));
        X(30,j-1)=tan(X(34,j-1));
        X(31,j-1)=tan(X(35,j-1));
        X(32,j-1)=tan(X(36,j-1));
        if Vx1==0
            X(25,j-1)=1;
            X(29,j-1)=1;
        end
        if Vx2==0
            X(26,j-1)=1;
            X(30,j-1)=1;
        end
        if Vx3==0
            X(27,j-1)=1;
            X(31,j-1)=1;
        end
        if Vx4==0
            X(28,j-1)=1;
            X(32,j-1)=1;
        end        
    else
        X(25,j-1)=-(Vx1-X(8,j-1))/X(8,j-1);
        X(26,j-1)=-(Vx2-X(9,j-1))/X(9,j-1);
        X(27,j-1)=-(Vx3-X(10,j-1))/X(10,j-1);
        X(28,j-1)=-(Vx4-X(11,j-1))/X(11,j-1);
        X(29,j-1)=(1-X(25,j-1))*tan(X(33,j-1));
        X(30,j-1)=(1-X(26,j-1))*tan(X(34,j-1));
        X(31,j-1)=(1-X(27,j-1))*tan(X(35,j-1));
        X(32,j-1)=(1-X(28,j-1))*tan(X(36,j-1));
        if X(8,j-1)==0
            X(25,j-1)=1;
            X(29,j-1)=1;
        end
        if X(9,j-1)==0
            X(26,j-1)=1;
            X(30,j-1)=1;
        end
        if X(10,j-1)==0
            X(27,j-1)=1;
            X(31,j-1)=1;
        end
        if X(11,j-1)==0
            X(28,j-1)=1;
            X(32,j-1)=1;
        end        
    end
    
    %Calcul des forces en jeu
    delta=calcul_delta(X(16,j),L,d_f);
    N1=M/(2*L)*(-l_r*h*X(2,j-1)/l-X(1,j-1)*h+g*l_r);
    N2=M/(2*L)*(l_r*h*X(2,j-1)/l-X(1,j-1)*h+g*l_r);
    N3=M/(2*L)*(-l_f*h*X(2,j-1)/l+X(1,j-1)*h+g*l_f);
    N4=M/(2*L)*(l_f*h*X(2,j-1)/l+X(1,j-1)*h+g*l_f);
    
    Fx1=(Pacejka(X(25,j-1),B,C,D,E)*cos(delta(1))-Pacejka(X(29,j-1),B,C,D,E)*sin(delta(1)))*N1;
    Fx2=(Pacejka(X(26,j-1),B,C,D,E)*cos(delta(2))-Pacejka(X(30,j-1),B,C,D,E)*sin(delta(2)))*N2;
    Fx3=(Pacejka(X(27,j-1),B,C,D,E)*cos(delta(3))-Pacejka(X(31,j-1),B,C,D,E)*sin(delta(3)))*N3;
    Fx4=(Pacejka(X(28,j-1),B,C,D,E)*cos(delta(4))-Pacejka(X(32,j-1),B,C,D,E)*sin(delta(4)))*N4;
    Fy1=(Pacejka(X(25,j-1),B,C,D,E)*sin(delta(1))+Pacejka(X(29,j-1),B,C,D,E)*cos(delta(1)))*N1;
    Fy2=(Pacejka(X(26,j-1),B,C,D,E)*sin(delta(2))+Pacejka(X(30,j-1),B,C,D,E)*cos(delta(2)))*N2;
    Fy3=(Pacejka(X(27,j-1),B,C,D,E)*sin(delta(3))+Pacejka(X(31,j-1),B,C,D,E)*cos(delta(3)))*N3;
    Fy4=(Pacejka(X(28,j-1),B,C,D,E)*sin(delta(4))+Pacejka(X(32,j-1),B,C,D,E)*cos(delta(4)))*N4;
    
    F_aerox=-C_x*A_L*rho/2*(X(38,j-1))^2;
    F_aeroy=-C_x*A_S*rho/2*(X(39,j-1))^2;
    
    %Calcul des dérivées secondes
    X(1,j)=(Fx1+Fx2+Fx3+Fx4+F_aerox)/M;
    X(2,j)=(Fy1+Fy2+Fy3+Fy4+F_aeroy)/M;
    X(3,j)=((Fy1+Fy2)*l_f-(Fy3+Fy4)*l_r+(Fx2-Fx1)*t_f+(Fx4-Fx3)*t_r)/Iz;
    X(4,j)=1/J(1)*(X(17,j-1)-X(21,j-1)-R(1)*Pacejka(X(25,j-1),B,C,D,E)*N1);
    X(5,j)=1/J(2)*(X(18,j-1)-X(22,j-1)-R(2)*Pacejka(X(26,j-1),B,C,D,E)*N2);
    X(6,j)=1/J(3)*(X(19,j-1)-X(23,j-1)-R(3)*Pacejka(X(27,j-1),B,C,D,E)*N3);
    X(7,j)=1/J(4)*(X(20,j-1)-X(24,j-1)-R(4)*Pacejka(X(28,j-1),B,C,D,E)*N4);
    
    %Le reste en découle
    
    X(8,j)=X(8,j-1)+(X(4,j)+X(4,j-1))/2*dt;
    X(9,j)=X(9,j-1)+(X(5,j)+X(5,j-1))/2*dt;
    X(10,j)=X(10,j-1)+(X(6,j)+X(6,j-1))/2*dt;
    X(11,j)=X(11,j-1)+(X(7,j)+X(7,j-1))/2*dt;
    
    X(12,j)=X(12,j-1)+(X(3,j)+X(3,j-1))/2*dt;
    X(13,j)=X(13,j-1)+(X(12,j)+X(12,j-1))/2*dt;
    X(14,j)=X(14,j-1)+(X(2,j)+X(2,j-1))/2*dt;
    X(15,j)=X(15,j-1)+(X(1,j)+X(1,j-1))/2*dt;
    
    if X(14,j)>0
        X(37,j)=V_cons-(X(14,j)^2+X(15,j)^2)^0.5;
        X(38,j)=X(37,j)*cos(X(13,j));
        X(39,j)=X(37,j)*sin(X(13,j));
    else
        X(37,j)=V_cons+(X(14,j)^2+X(15,j)^2)^0.5;
        X(38,j)=X(37,j)*cos(X(13,j));
        X(39,j)=X(37,j)*sin(X(13,j));
    end
end

%=============================== Tracés ==================================%

accelx=X(1,:);
accely=X(2,:);
psisec=X(3,:);
omegap1=X(4,:);
omegap2=X(5,:);
omegap3=X(6,:);
omegap4=X(7,:);
omega1=X(8,:);
omega2=X(9,:);
omega3=X(10,:);
omega4=X(11,:);
psip=X(12,:);
psi=X(13,:);
yp=X(14,:);
xp=X(15,:);
deltacom=X(16,:);
lambdax1=X(25,:);
lambdax2=X(26,:);
lambdax3=X(27,:);
lambdax4=X(28,:);
lambday1=X(29,:);
lambday2=X(30,:);
lambday3=X(31,:);
lambday4=X(32,:);
epsilon=X(37,:);
epsilonx=X(38,:);
epsilony=X(39,:);

figure,
plot(t,omega1)
hold on
plot(t,omega2)
hold on
plot(t,omega3)
hold on
plot(t,omega4)
hold off
legend ('omega1','omega2','omega3','omega4')
title('Vitesse de rotation des différentes roues')

figure,
plot(t,epsilon)
hold on
plot(t,epsilonx)
hold on
plot(t,epsilony),
hold off
legend ('Erreur','selon x','selon y')
title('Evolution de l erreur')

figure,
plot(t,lambdax1)
hold on
plot(t,lambday1),
hold on
plot(t,lambdax2)
hold on
plot(t,lambday2),
hold on
plot(t,lambdax3)
hold on
plot(t,lambday3),
hold on
plot(t,lambdax4)
hold on
plot(t,lambday4),
hold off
axis([0 tps -2 2])
legend('lambdax1','lambday1','lambdax2','lambday2','lambdax3','lambday3','lambdax4','lambday4')