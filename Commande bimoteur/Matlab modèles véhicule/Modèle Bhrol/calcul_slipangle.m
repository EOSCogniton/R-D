function [alpha]=calcul_slipangle(Vx1,Vy1,Vx2,Vy2,Vx3,Vy3,Vx4,Vy4,delta1,delta2,delta3,delta4)
alpha1=angle(Vx1+1i*Vy1)-delta1;
alpha2=angle(Vx2+1i*Vy2)-delta2;
alpha3=angle(Vx3+1i*Vy3)-delta3;
alpha4=angle(Vx4+1i*Vy4)-delta4;
alpha=[alpha1 alpha2 alpha3 alpha4];
if Vy1==0
    alpha(1)=0;
end
if Vy2==0
    alpha(2)=0;
end
if Vy3==0
    alpha(3)=0;
end
if Vy4==0
    alpha(4)=0;
end
end
