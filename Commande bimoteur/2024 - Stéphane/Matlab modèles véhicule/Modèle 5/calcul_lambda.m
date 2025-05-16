function [lambda]=calcul_lambda(alpha1,alpha2,alpha3,alpha4,R1,R2,R3,R4,omega1,omega2,omega3,omega4,Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,accel)

V1=(Vx1^2+Vy1^2)^0.5;
V2=(Vx2^2+Vy2^2)^0.5;
V3=(Vx3^2+Vy3^2)^0.5;
V4=(Vx4^2+Vy4^2)^0.5;

Vx1=V1*cos(alpha1);
Vx2=V2*cos(alpha2);
Vx3=V3*cos(alpha3);
Vx4=V4*cos(alpha4);

if accel>0
    lambdax1=-(R1*omega1-Vx1)/(R1*omega1);
    lambdax2=-(R2*omega2-Vx2)/(R2*omega2);
    lambdax3=(R3*omega3-Vx3)/(R3*omega3);
    lambdax4=(R4*omega4-Vx4)/(R4*omega4);
    lambday1=(1+lambdax1)*tan(alpha1);
    lambday2=(1+lambdax2)*tan(alpha2);
    lambday3=(1-lambdax3)*tan(alpha3);
    lambday4=(1-lambdax4)*tan(alpha4);
else
    lambdax1=(R1*omega1-Vx1)/Vx1;
    lambdax2=(R2*omega2-Vx2)/Vx2;
    lambdax3=-(R3*omega3-Vx3)/Vx3;
    lambdax4=-(R4*omega4-Vx4)/Vx4;
    lambday1=tan(alpha1);
    lambday2=tan(alpha2);
    lambday3=tan(alpha3);
    lambday4=tan(alpha4);
end
lambda=[lambdax1 lambday1 lambdax2 lambday2 lambdax3 lambday3 lambdax4 lambday4];

if accel>0
    if omega1==0
       lambda(1)=-1;
       lambda(2)=0;
    end
    if omega2==0
        lambda(3)=-1;
        lambda(4)=0;
    end
    if omega3==0
        lambda(5)=1;
        lambda(6)=0;
    end
    if omega4==0
        lambda(7)=1;
        lambda(8)=0;
    end

else
    if Vx1==0
        lambda(1)=-1;
        lambda(2)=0;
    end
    if Vx2==0
        lambda(3)=-1;
        lambda(4)=0;
    end
    if Vx3==0
        lambda(5)=1;
        lambda(6)=0;
    end
    if Vx4==0
        lambda(7)=1;
        lambda(8)=0;
    end
end
end

