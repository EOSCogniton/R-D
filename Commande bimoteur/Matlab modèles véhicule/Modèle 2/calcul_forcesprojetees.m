function [F]=calcul_forcesprojetees(delta1,delta2,delta3,delta4,F1,P1,F2,P2,F3,P3,F4,P4)
F_L=cos(delta1)*F1-sin(delta1)*P1+cos(delta2)*F2-sin(delta2)*P2+cos(delta3)*F3-sin(delta3)*P3+cos(delta4)*F4-sin(delta4)*P4;
F_S=sin(delta1)*F1+cos(delta1)*P1+sin(delta2)*F2+cos(delta2)*P2+sin(delta3)*F3+cos(delta3)*P3+sin(delta4)*F4+cos(delta4)*P4;
F=[F_L F_S];
end
