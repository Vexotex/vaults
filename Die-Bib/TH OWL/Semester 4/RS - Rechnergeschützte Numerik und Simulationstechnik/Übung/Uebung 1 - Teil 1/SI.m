clc;
clear all;

n = 1001;
x = linspace(-6*pi,6*pi,n);
y = sin(x)./x; 
y((n-1)/2+1) = 1;

F = cumsum(y)*12*pi/n;
F = F - F((n-1)/2+1); 

hold off;
plot(x,y);
hold on;
grid on;
plot(x,F);

