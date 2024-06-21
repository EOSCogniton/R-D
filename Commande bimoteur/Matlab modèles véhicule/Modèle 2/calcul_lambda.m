function [lambda]=calcul_lambda(alpha1,alpha2,alpha3,alpha4,R1,R2,R3,R4,omega1,omega2,omega3,omega4,Vx1,Vx2,Vx3,Vx4,accel)

if accel>=0
    lambdax1=(R1*omega1-Vx1)/(R1*omega1);
    lambdax2=(R2*omega2-Vx2)/(R2*omega2);
    lambdax3=(R3*omega3-Vx3)/(R3*omega3);
    lambdax4=(R4*omega4-Vx4)/(R4*omega4);
    lambday1=(1-lambdax1)*tan(alpha1);
    lambday2=(1-lambdax2)*tan(alpha2);
    lambday3=(1-lambdax3)*tan(alpha3);
    lambday4=(1-lambdax4)*tan(alpha4);
else
    lambdax1=-(R1*omega1-Vx1)/Vx1;
    lambdax2=-(R2*omega2-Vx2)/Vx2;
    lambdax3=-(R3*omega3-Vx3)/Vx3;
    lambdax4=-(R4*omega4-Vx4)/Vx4;
    lambday1=tan(alpha1);
    lambday2=tan(alpha2);
    lambday3=tan(alpha3);
    lambday4=tan(alpha4);
end
lambda=[lambdax1 lambday1; lambdax2 lambday2; lambdax3 lambday3; lambdax4 lambday4];

if omega1==0
    lambda=ones(4,2);
end
if omega2==0
    lambda=ones(4,2);
end
if omega3==0
    lambda=ones(4,2);
end
if omega4==0
    lambda=ones(4,2);
end
if Vx1==0
    lambda=ones(4,2);
end
if Vx2==0
    lambda=ones(4,2);
end
if Vx3==0
    lambda=ones(4,2);
end
if Vx4==0
    lambda=ones(4,2);
end
end

