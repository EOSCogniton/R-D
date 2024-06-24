function [Fp]=projection(F1, P1, F2, P2, F3, P3, F4, P4, delta1, delta2, delta3, delta4)
Fx1=F1*cos(delta1)-P1*sin(delta1);
Fy1=F1*sin(delta1)+P1*cos(delta1); 
Fx2=F2*cos(delta2)-P2*sin(delta2);
Fy2=F2*sin(delta2)+P2*cos(delta2);
Fx3=F3*cos(delta3)-P3*sin(delta3);
Fy3=F3*sin(delta3)+P3*cos(delta3);
Fx4=F4*cos(delta4)-P4*sin(delta4);
Fy4=F4*sin(delta4)+P4*cos(delta4);
Fp=[Fx1 Fy1 Fx2 Fy2 Fx3 Fy3 Fx4 Fy4];
end
