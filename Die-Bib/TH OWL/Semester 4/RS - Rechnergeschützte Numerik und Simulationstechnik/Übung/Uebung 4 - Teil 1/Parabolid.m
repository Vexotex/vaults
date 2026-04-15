clc
figure(1);
hold off
[p,t]=meshgrid(linspace(-pi,pi,30),linspace(0,3,30));
x=cos(p).*t;
y=sin(p).*t;
z= 9-t.^2;
surf(x,y,z);
colormap cool;
hold on
t=linspace(0,16*pi,500);
x=cos(t)*3.*t/16/pi;
y=sin(t)*3.*t/16/pi;
z= 9-(3*t/16/pi).^2+0.1;
phandle=plot3(x,y,z,'r')
set(phandle,'LineWidth',5,'Color',[0,0,1]);
