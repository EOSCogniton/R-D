N=1000;
L=2.757;
d_f=1.254;
delta=linspace(-pi,pi,N);
delta_1=atan(L.*tan(delta)./(L-d_f/2.*tan(delta)));
delta_2=atan(L.*tan(delta)./(L+d_f/2.*tan(delta)));

%delta1=linspace(-pi,pi,N);
%delta2=linspace(-pi,pi,N);
%sum=zeros(N,N);
%dif=zeros(N,N);
%for i=1:N
%    for j=1:N
%        dif(i,j)=cos(delta1(i))-sin(delta1(i))+cos(delta2(j))-sin(delta2(j));
%        sum(i,j)=cos(delta1(i))+sin(delta1(i))+cos(delta2(j))+sin(delta2(j));
%
%    end
%end    
%surf(delta1,delta2,dif)

dif=cos(delta_1)-sin(delta_1)+cos(delta_2)-sin(delta_2);
sum=cos(delta_1)+sin(delta_1)+cos(delta_2)+sin(delta_2);

delta=180/pi.*delta;

plot(delta,dif)
hold on,
plot(delta,sum)
axis([-pi pi 1.5 2.5])
legend('dif','sum')
xlabel('delta')

