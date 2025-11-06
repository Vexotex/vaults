Ein periodisches, reellwertiges Signal 
$$
x(t) = x(t+kT) \quad \text{mit } T \in \mathbb{Z}
$$
mit der primitiven Periode T kann durch eine trigonometrische Reihe mit Gleichanteilen dargestellt werden:
$$
x(t) = \frac{a_{0}}{2} + \sum_{n=1}^{\infty}(a_{n} \cdot \cos(n \Omega t) + b_{n} \cdot \sin(n \Omega t))
$$
$$
\begin{array}{l}
\Omega = \frac{2\pi}{T} = 2\pi f & \text{...Grundkreisfrequenz} \quad \text{mit }[\Omega] = \frac{rad}{s} \\
a_{n}, \space b_{n} & \text{...Fourier-Koeffizienten} \\
a_{1}, \space b_{1} & \text{...Grundschwingungs-Fourier-Koeffizienten} \\
\frac{a_{0}}{2} & \text{...Gleichanteil}
\end{array}
$$

## komplexe Darstellung

$$
\cos(n\Omega t) = \frac{1}{2}(e^{jn\Omega t} + e^{-jn\Omega t})
$$
$$
\sin(n\Omega t) = \frac{1}{2j}(e^{jn\Omega t} - e^{-jn\Omega t})
$$
