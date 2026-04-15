t=linspace(0,pi*2,200);
y = cos(t);
C1 = fourier(t,y,1)
C_1 = fourier(t,y,-1)
C2 = fourier(t,y,2)
C3 = fourier(t,y,3)
