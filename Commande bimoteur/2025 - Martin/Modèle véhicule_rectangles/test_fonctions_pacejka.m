alpha=-8:0.01:8;
sl=-0.2:0.01:0.2;
fz=-800;
plot(alpha,fonction_pacejka_3D_SA(fz,alpha))
figure
plot(alpha,fonction_pacejka_3D_SL(fz,alpha))