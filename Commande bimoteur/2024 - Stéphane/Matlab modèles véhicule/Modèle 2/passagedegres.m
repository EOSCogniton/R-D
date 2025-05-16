function [angdeg]=passagedegres(thetarad,phirad,psirad)
thetadeg=mod(thetarad*180/pi,360);
phideg=mod(phirad*180/pi,360);
psideg=mod(psirad*180/pi,360);
angdeg=[thetadeg phideg psideg];
end
