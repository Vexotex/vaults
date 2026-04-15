x = [-6,-3,0,3,6,9];
y = [-231,-61.5,-9,7.5,69,256.5];

coeff_3g = polyfit(x,y,3);
coeff_1g = polyfit(x,y,1);

xi = (-8:0.01:11);
yi = polyval(coeff_3g,xi);
yi_ = polyval(coeff_1g,xi);

hold off
plot(x,y,'kx')
hold on
grid on
plot(xi,yi,'r')
plot(xi,yi_,'b')

yi_linear = interp1(x,y,xi,'linear');
yi_spline = interp1(x,y,xi,'spline');

plot(xi,yi_linear,'m')
plot(xi,yi_spline,'g--')
