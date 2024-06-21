function [V]=calcul_retourvitesse(Vx,Vy)
if sign(Vx)>0 
    V=(Vx^2+Vy^2)^(1/2);
else
    V=-(Vx^2+Vy^2)^(1/2);
end
end
