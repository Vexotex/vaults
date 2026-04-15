clc;
clear all;

n = 5;

x = [0,0,0.5,1,0,1,1,0,1];
y = [0,1,1.5,1,1,0,1,0,0];

hold off;

for id_x = 0 : n - 1
    plot(x + id_x,y,'r');
    hold on;
end