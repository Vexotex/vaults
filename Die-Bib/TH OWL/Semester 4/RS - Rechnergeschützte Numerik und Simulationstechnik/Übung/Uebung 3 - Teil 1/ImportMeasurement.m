clear all;

[Data, Header] = xlsread('Measurement','Exp1');

hold off
plot(Data(:,1),Data(:,2));
hold on
plot(Data(:,1),Data(:,3));
grid on
xlabel(Header(1))
legend(Header(2:3))