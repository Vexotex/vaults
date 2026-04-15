%% Parameter des RLC Filters
L=10;
C=500e-5;
R=10;

% Anregung (Rechteckschwingung)
uet = linspace(0,40,1000); % Zeitpunkte von t=0 bis t=12 verteilt.
ue  = (mod(uet,10)<5)*2;        % Sprungfunktion bei t = 0.1
 
% ODE45 Solver
options = odeset('RelTol',1e-6,'AbsTol',1e-6);
[T,Y]=ode23(@(t,x) RLC(t,x,R,L,C,ue,uet),[0 40],[0 0],options);
figure(1);
subplot(2,1,1)
hold off;
plot(T,Y(:,1))
hold on 
grid on
xlabel('Zeit in s');
ylabel('Strom i in A');

subplot(2,1,2)
hold off;
plot(uet,ue)
hold on 
grid on
xlabel('Zeit in s');
ylabel('Spannung u in V');

