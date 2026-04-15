figure(1);
[x,y]=meshgrid(linspace(-3,3,30),linspace(-3,3,30));

z= 9-(x.^2+y.^2);
surf(x,y,z);
