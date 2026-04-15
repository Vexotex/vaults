clear all;

x = linspace(0,4,500);

for idx = 1 : length(x)
    y(idx) = exp_fun(x(idx));
end

hold off;
plot(x,y);
hold on;
grid on;

x_s = linspace(0,4,10);
%x_s = [0,1.12,1.17,1.53,1.56,2.72,3.28,3.33,3.52,3.8];

for idx = 1 : length(x_s)
    y_s(idx) = exp_fun(x_s(idx));
end

plot(x_s,y_s,'kx');

polyappr = polyfit(x_s,y_s,7);
plot(x,polyval(polyappr,x),'r');

polyappr_int = [polyappr./(length(polyappr):-1:1),0];
Int1 = polyval(polyappr_int,4) - polyval(polyappr_int,0)

Int2 = quad(@(x)polyval(polyappr,x),0,4)

Int3 = trapz(x,polyval(polyappr,x))

Int4 = quad(@exp_fun,0,4)

Int5 = trapz(x,y)




