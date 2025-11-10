Definition: Die Faltungsoperation angewendet auf zwei Signale 𝑥1 und 𝑥2 liefert die als Faltung bezeichnete Funktion 𝑦(𝑡) mit:
$$
y(t) = \int_{-\infty}^\infty x_{1}(\tau) \cdot x_{2}(t-\tau)d\tau 
$$
Hint:
$$
x_{2}(t - \tau) = x_{2}(\underbrace{-}_{\text{Spiegelung}}(\tau \underbrace{- t}_{\text{Verschiebung}}))
$$
Die Faltung wird auch geschrieben als:
$$
y(t) = (x_{1} * x_{2})(t) 
\quad \text{oder} \quad
y(t) = x_{1}(t) * x_{2}(t)
$$

[Eigenschaften der Faltung](Skript-SY-V1.5.pdf#page=29&selection=6,0,6,25|Skript-SY-V1.5, page 29)

Aufgrund der der Multiplikation äquivalenten Eigenschaften wird auch vom Faltungsprodukt gesprochen. 
Der Dirac-Impuls ist damit das *neutrale* Element der Faltung.

[Veranschaulichung der Faltungsoperation](Skript-SY-V1.5.pdf#page=30&selection=6,0,8,59|Skript-SY-V1.5, page 30)

