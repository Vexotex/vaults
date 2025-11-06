# Eigenschaften
## [1. Linearität](Skript-SY-V1.5.pdf#page=41&selection=10,0,10,10|Skript-SY-V1.5, page 41)



## [2. Reele Zeitfunktion](Skript-SY-V1.5.pdf#page=41&selection=95,0,95,19|Skript-SY-V1.5, page 41)



## [3. Konjugiert-komplexe Zeitfunktionen](Skript-SY-V1.5.pdf#page=41&selection=202,0,202,34|Skript-SY-V1.5, page 41)



## [4. Spiegelung](Skript-SY-V1.5.pdf#page=42&selection=8,0,8,10|Skript-SY-V1.5, page 42)
"Vertauschung der Zeiger"


## [5. Gerade und ungerade Signale]([[Skript-SY-V1.5.pdf#page=42&selection=72,0,72,30|Skript-SY-V1.5, page 42]])
I:
$$
\begin{array} \\
x \in \mathbb{C} \\
\text{gerade:} & x(t) = x(-t) \Leftrightarrow x_{n} = x_{-n} \\
\text{ungerade:} & x(t) = -x(t) \Leftrightarrow x_{n} = -x_{-n}  
\end{array}
$$
II:
$$
\begin{array} \\
x \in \mathbb{R} \\
\text{gerade} & x_{n} = x_{-n} = 
x_{-n}^* \Rightarrow \mathrm{Im}(x_{n}) = 0 , n \in \mathbb{Z} \\
\text{ungerade} & x_{n} = x_{-n} = 
x_{-n}^* \Rightarrow \mathrm{Re}(x_{n}) = 0 , n \in \mathbb{Z}
\end{array}
$$

## [6. Zeitverschiebung]([[Skript-SY-V1.5.pdf#page=43&selection=89,0,89,16|Skript-SY-V1.5, page 43]])

$$
x(t-t_{0})
$$
Bzw.
$$
\frac{1}{T} \int ^T_{0} x(t-t_{0}) e^{-jn\Omega t} dt = 
\int^{T - t_{0}}_{-t_{0}} x(\tau) e^{-jn\Omega (\tau + t_{0})} dt = 
\frac{1}{T} \int^T_{0} x(\tau) e^{-jn\Omega \tau}dt e^{-jn\Omega t_{0}}
$$

bei 
$$
t_{0} = T \Rightarrow e^{jn\Omega t_{0}} = e^{jn \frac{2\pi}{T} T} = 1 \quad n \in \mathbb{Z}
$$


## [7. Halbwellensymmetrie](Skript-SY-V1.5.pdf#page=43&selection=400,0,400,19|Skript-SY-V1.5, page 43)

wenn das Signal um die halbe Periodenlänge verschoben wird, bekommt man das invertierte Signal

## [8. Ableitung](Skript-SY-V1.5.pdf#page=44&selection=324,0,324,9|Skript-SY-V1.5, page 44)


## [9. Stammfunktion / Integral](Skript-SY-V1.5.pdf#page=45&selection=8,0,8,8|Skript-SY-V1.5, page 45)
$$
X_{0} = 0
$$
weil Gleichanteil bei Stammfunktion ja mit "+c" immer frei gewählt / nicht definiert werden kann


## [10. Multiplikation im Zeitbereich](Skript-SY-V1.5.pdf#page=45&selection=77,0,77,29|Skript-SY-V1.5, page 45)

- beide Faktoren haben die gleiche Periodizität
- ähnlich wie Faltung (diskrete Faltung)

## [11. Faltung](Skript-SY-V1.5.pdf#page=45&selection=265,0,265,7|Skript-SY-V1.5, page 45)



