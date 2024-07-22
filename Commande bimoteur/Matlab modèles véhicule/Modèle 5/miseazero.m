function [sortie]=miseazero(u)

if u<10e-9
    sortie=0;
else
    sortie=u;
end
