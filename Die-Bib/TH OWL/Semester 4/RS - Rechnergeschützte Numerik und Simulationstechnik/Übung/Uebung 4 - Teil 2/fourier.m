function C = fourier(t,y,n)

T = t(end) - t(1);

C = trapz(t, y .* exp(-j*n*2*pi/T*t))/T;  

end