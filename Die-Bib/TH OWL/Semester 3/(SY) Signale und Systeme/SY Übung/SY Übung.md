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


