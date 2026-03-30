LTI-System = **L**inear **T**im**i**nvariant System
# Mechanik
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^frame=7Sq5TF-GGDFD2jb24RAt8]]


$$
\begin{array} \\
F_{F} = \text{Federkraft} = y \cdot c \\
F_{T} = \text{Trägheitskraft} = m \cdot a \Leftrightarrow a = \frac{F_{F}}{m}\\
F_{g} = m \cdot g \\
F_{cm} = \text{Luftwiederstand} = 0
\end{array}
$$
Wir betrachten das System im eingependelten Zustand
$$
y = 0 , \quad v=0 , \quad a=0 \quad \Rightarrow \quad
F_{F} = F_{g}
$$
hießt wir können $F_{F}$ aufteilen in $F_{Fg}$ und $F_{F}$, somit kürzt sich die Federkraft, die zum Kontern der Gewichtskraft benötigt wird weg.

![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^frame=N3VFXslDW5W1nXZap744Z]]
und es bleiben nur $F_{F}$ und $F_{T}$ übrig.

so wie eingezeichnet, wirkt die Federkraft gegen y und die Trägheit wirkt auch entgegen y.
$$
a=\frac{F}{m} , \quad F = F_{F} + F_{T} \quad \Rightarrow \quad 
a = \frac{-F_{F}-F_{T}}{m} = 
\frac{-y \cdot c -m \cdot a}{m} = - \frac{c}{m}y-a
$$

$$
a = \dot{v} = \ddot{s}
$$
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^frame=228P9FfDXjBU7yv97xyyz]]
$$
\begin{array} \\
\ddot{y} = - \frac{c}{m} y - \ddot{y} \\
2\ddot{y} + \frac{c}{m}y = 0 \\
\ddot{y} + \frac{c}{2m} y = 0
\end{array}
$$



# Elektrotechnik
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^frame=w-EkoWpaaMgA4bR3yUuzO]]
$$
U = R \cdot J \Leftrightarrow J=\frac{U}{R}
$$
$$
U_{C} = \frac{1}{C} \int I_{C} \space dt
$$
$$
U_{R} = U-y
$$
$$
I = \frac{U_{R}}{R} = \frac{U-y}{R}
$$
$$
\begin{array} \\
U_{C} = y = \frac{1}{C} \int I \space dt = \frac{1}{C} \int \frac{u-y}{R} \space dt \quad /\frac{d}{dt} \\
\dot{y} = \frac{1}{C} \cdot \frac{u-y}{R} = \frac{1}{RC}U - \frac{1}{RC}y \\
\Leftrightarrow \dot{y} + \frac{1}{RC} y = \frac{1}{RC}U
\end{array}
$$
