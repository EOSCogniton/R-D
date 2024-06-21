function [Matforces]= calcul_matriceforces(Fx1,Fy1,Fx2,Fy2,Fx3,Fy3,Fx4,Fy4,Fzc1,Fzc2,Fzc3,Fzc4,Faerox,Faeroy,Faeroz,Px,Py,Pz)
Matforces=[Fx1+Fx2+Fx3+Fx4+Faerox+Px; Fy1+Fy2+Fy3+Fy4+Faeroy+Py; Fzc1+Fzc2+Fzc3+Fzc4+Faeroz+Pz];
end
