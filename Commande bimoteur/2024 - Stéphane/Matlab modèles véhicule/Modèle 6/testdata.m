data=readtable('rc_33.log');

accelX=data.AccelX__G___3_0_3_0_50;
accelY=data.AccelY__G___3_0_3_0_50;
accel=sign(accelX).*sqrt(accelX.^2+accelY.^2);

tps=linspace(5.515,6.8774,4085);

figure,
plot(tps,accel)
title('Accel véhicule')

angle=data.Volant__F__0_0_300_0_50;
figure,
plot(tps,angle)
title('Angle volant')

anglevoit=data.Yaw__Deg_Sec___120_120_50;
figure,
plot(tps,anglevoit)
title('Yaw Angle voiture')

vitroue=data.WheelSpeed__MPH__0_0_150_0_50;
figure,
plot(tps,vitroue)
title('Vitesse roue')