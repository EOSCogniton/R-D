clear, clc

run 'original version'\main_data_vehicle.m
run 'original version'\main_phi.m

mu = 1.5;
g = 9.81;

vx = linspace(1,50,4901);
delta_asymptot = 0.85*mu*g*m*(lr*Cr - lf*Cf)/(lf+lr)/Cf/Cr;
delta = 0.85*mu*g*(lr+lf)./(vx.^2) + delta_asymptot;

figure(1);
subplot(2,1,1);
semilogy(vx, delta,'k');
grid on
title("Maximum value of steering angle at a given speed");
xlabel("Longitudinal speed vx (m/s)");
ylabel("Steering angle delta (radians, logarythmic scale)");

subplot(2,1,2);
semilogy(vx, delta*360/2/pi,'k');
grid on
title("Maximum value of steering angle at a given speed");
xlabel("Longitudinal speed vx (m/s)");
ylabel("Steering angle delta (degrees, logarythmic scale)");
