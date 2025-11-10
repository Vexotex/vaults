# [Übung 1](SY_Uebung_02.pdf#page=1&selection=8,0,10,21|SY_Uebung_02, page 1)
## Ü 2.1
$$
\begin{array}\
M\{x(-t) = M\{x(t) \} \\
\frac{1}{T} \int^T_{0} x(t)dt \\
subs\quad-t = \tilde{t} \\
\frac{d\tilde{t}}{dt}=-1 \\

\end{array}
$$



$$
M\{x(-t) = M\{x(t) \}
$$
M{} steht für den Mittelwert eines Signals
**Definition des zeitlichen Mittelwerts**
$$
M\{x(t)\} = \lim_{ T \to \infty } \frac{1}{2T} \int^T_{-T} x(t) dt 
$$
also
$$
M\{x(-t)\} = \lim_{ T \to \infty } \frac{1}{2T} \int^T_{-T} x(-t) dt 
$$
$$
\begin{array}
\text{substituiere} \space \tau = -t \text{, dann } dt = -d\tau \\
\text{Wenn } T = -t \text{, dann } \tau = T \\
\text{Wenn } T = t \text{, dann } \tau = -T 
\end{array}
$$
$$
\int^T_{-T} x(-t) dt 
= \int^{-T}_{T} x(\tau) (-d\tau) 
= \int^T_{-T} x(\tau) d\tau 
$$




## Ü 2.2
Klassifikation von Signalen:
- Leistungssignal größer 0 und kleiner als unendlich
- Energiesignal kleiner als unendlich
- Kausale und nicht kausale Signale (Kausal heist x(t) = 0 für alle t < 0)
- gerade oder ungerade Signale (Spiegelung an der y-Achse oder durch den Ursprung)


## Ü 2.3


## Ü 2.4



## [Ü 3.1](SY_Uebung_03.pdf#page=1&selection=9,0,9,5|SY_Uebung_03, page 1)

$$
g_{\nabla}(t) = 
\left[ \frac{2}{T} rect\left( \frac{2t}{T} - \frac{1}{2} \right) \right] * 
\left[ \frac{2}{T} rect\left( \frac{2t}{T} - \frac{1}{2} \right) \right]
$$

$$
\begin{array} \\
\frac{2}{T} rect\left( \frac{2t}{T} - \frac{1}{2} \right) =
\frac{2}{T} rect\left(\frac{t- \frac{T}{4}}{\frac{T}{2}} \right) \\
\text{mit} \\
\frac{2t}{T} - \frac{1}{2} =  
\frac{4t}{2T} - \frac{T}{2T} = 
\frac{4t - T}{2T} =
\frac{t- \frac{T}{4}}{\frac{T}{2}}
\end{array}
$$

[[Faltung]]

$$
g_{\nabla}(t) = 
\left[ \frac{2}{T} \right]^2 
\int^{\infty}_{-\infty}
\underbrace{rect\left(  \frac{\tau - \frac{T}{4}}{\frac{T}{2}} \right)}_{x_{1}} 
\cdot
\underbrace{rect\left(  \frac{t - \tau - \frac{T}{4}}{\frac{T}{2}} \right)}_{x_{2}}
d\tau
$$

![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=RkAQbOoHrdwfXSE7lJrr_]]
$$
y(t) = 0 \quad \forall t \leq 0
$$

![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=OJ6tBtPMgXNFXnWT7YJB0]]
$$
\int_{0}^t \frac{2}{T} \cdot \frac{2}{T} d\tau = \frac{4}{T^2} \int_{0}^t d\tau
\quad \forall 0<t\leq \frac{T}{2} 
$$
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=eBzK55ZgSG-BnZb04FqsZ]]
$$
\int^{T/2}_{t- \frac{T}{2}} \left[ \frac{2}{T} \right]^2 d\tau =
\frac{4}{T^2}\left( 1- \frac{t}{T} \right) 
\quad \forall \frac{T}{2} < t \leq T
$$
$$
y(t) = 0 \quad \forall T < t
$$
Also zusammengefasst:
$$
y(t) = 
\begin{cases}
0 & 0\geq t \geq T \\
\frac{4t}{T^2} & 0 < t \leq \frac{T}{2} \\
\frac{4}{T}\left( 1- \frac{t}{T} \right) & \frac{T}{2} < t < T
\end{cases}
$$
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=rUTQg8GSKaWfzaxWLObXf]]


## [Ü 3.2](SY_Uebung_03.pdf#page=1&selection=136,0,136,6|SY_Uebung_03, page 1)

$$
|\sin(x+jy)|^2 = \sin^2(x) + \sinh^2(y)

$$
Umformung in Exponentialschreibweise:

$$
\begin{array} \\
\left| \frac{e^{ j(x+jy) } - e^{ -j(x+jy) } }{2j} \right|^2  \\
=
\left| \frac{1}{2j} [e^{ -y } \cdot e^{ jx } - e^{ y } \cdot e^{ -jx }] \right|^2 \\
= \left| \frac{1}{2j} [e^{ -y }(\cos(x) + j\sin(x)) - e^{ y }(\cos(-x) + j\sin(-x))] \right|^2
\end{array}
$$
