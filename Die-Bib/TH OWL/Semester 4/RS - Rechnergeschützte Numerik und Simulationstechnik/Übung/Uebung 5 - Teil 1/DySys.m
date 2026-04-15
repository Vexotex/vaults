% Aufgabe 5.1

A1 = [0 -100; 20 -4];
B1 = [100; 0];
C1 = [1 0];
D1 = 0;

num2 = 15;
den2 = [0.01 1];

S1 = ss(A1,B1,C1,D1)
S2 = tf(num2,den2)

S = tf(S1 * S2)

[num, den] =tfdata(S)

% Aufgabe 5.2

num1 = 20;
den1 = [1 2 5];
S1 = tf(num1,den1)

num2 = 1.2;
den2 = [0.01 1];
S2 = tf(num2,den2)

S = S1/(1-S1*S2)

