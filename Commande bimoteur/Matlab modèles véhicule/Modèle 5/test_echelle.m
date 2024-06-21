abstest=linspace(0,1.2,1200);
ordtest=30.3.*abstest.^2;
erreur=linspace(0,1,1000);

orderr=erreur'*ordtest;

% plot(abstest,ordtest)
% hold on
% plot(abstest,0.95*ordtest)
% hold off

surf(orderr,erreur'*abstest);
xlabel('longueur')
ylabel('erreur sur la masse (%)')
zlabel('masse')
