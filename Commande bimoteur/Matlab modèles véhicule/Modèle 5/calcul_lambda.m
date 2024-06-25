function [lambda]=calcul_lambda(alpha1,alpha2,alpha3,alpha4,R1,R2,R3,R4,omega1,omega2,omega3,omega4,Vx1,Vx2,Vx3,Vx4,Vy1,Vy2,Vy3,Vy4,accel)

V1 = (Vx1^2+Vy1^2)/2;
V2 = (Vx2^2+Vy2^2)/2;
V3 = (Vx3^2+Vy3^2)/2;
V4 = (Vx4^2+Vy4^2)/2;

Vxr1 = V1 * cos(alpha1);
Vxr2 = V2 * cos(alpha2);
Vxr3 = V3 * cos(alpha3);
Vxr4 = V4 * cos(alpha4);

if accel>=0
    lambdax1=-(R1*omega1-Vxr1)/(R1*omega1);
    lambdax2=-(R2*omega2-Vxr2)/(R2*omega2);
    lambdax3=(R3*omega3-Vxr3)/(R3*omega3);
    lambdax4=(R4*omega4-Vxr4)/(R4*omega4);
    lambday1=(1+lambdax1)*tan(alpha1);
    lambday2=(1+lambdax2)*tan(alpha2);
    lambday3=(1-lambdax3)*tan(alpha3);
    lambday4=(1-lambdax4)*tan(alpha4);
else
    lambdax1=-(R1*omega1-Vxr1)/Vxr1;
    lambdax2=-(R2*omega2-Vxr2)/Vxr2;
    lambdax3=(R3*omega3-Vxr3)/Vxr3;
    lambdax4=(R4*omega4-Vxr4)/Vxr4;
    lambday1=tan(alpha1);
    lambday2=tan(alpha2);
    lambday3=tan(alpha3);
    lambday4=tan(alpha4);
end
lambda=[lambdax1 lambday1 lambdax2 lambday2 lambdax3 lambday3 lambdax4 lambday4];
% lambda = [-1 0 -1 0 1 0 1 0];
% lambda = [lambdax1 0 lambdax2 0 lambdax3 0 lambdax4 0];
% if lambdax1>1 || Vxr1 <=0.5 || omega1 <=0.5
%    lambda(1)=0;
%    lambda(2)=0;
% end
% if lambdax2>1 || Vxr2 <=0.5 || omega2 <=0.5
%     lambda(3)=0;
%     lambda(4)=0;
% end
% if lambdax3>1 || Vxr3 <=0.5 || omega3 <=0.5
%     lambda(5)=0;
%     lambda(6)=0;
% end
% if lambdax4>1 || Vxr4 <=0.5 || omega4 <=0.5
%     lambda(7)=0;
%     lambda(8)=0;
% end

if accel>=0
    if abs(omega1)<=0.5
       lambda(1)=-1;
       lambda(2)=0;
    end
    if abs(omega2)<=0.5
        lambda(3)=-1;
        lambda(4)=0;
    end
    if abs(omega3)<=0.5
        lambda(5)=1;
        lambda(6)=0;
    end
    if abs(omega4)<=0.5
        lambda(7)=1;
        lambda(8)=0;
    end

else
    if abs(Vxr1)<=0.5
        lambda(1)=-1;
        lambda(2)=0;
    end
    if abs(Vxr2)<=0.5
        lambda(3)=-1;
        lambda(4)=0;
    end
    if abs(Vxr3)<=0.5
        lambda(5)=1;
        lambda(6)=0;
    end
    if abs(Vxr4)<=0.5
        lambda(7)=1;
        lambda(8)=0;
    end
end
end

