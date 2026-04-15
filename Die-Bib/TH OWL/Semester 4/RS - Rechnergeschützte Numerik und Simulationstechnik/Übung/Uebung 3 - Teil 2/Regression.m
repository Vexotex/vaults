% Messdaten

x = (-5 : 1 : 5);
y_ = 0.1 * x.^2 + 0.1 * exp(x);
y = y_ + 2*(rand(size(y_))-0.5);

A = [x'.^2,exp(x')];

lambda = inv(A'*A)*A'*y';

yr = lambda(1) * x.^2 + lambda(2) * exp(x);

hold off
plot(x,y,'kx')
hold on
grid on
plot(x,y_,'b')
plot(x,yr,'r')
