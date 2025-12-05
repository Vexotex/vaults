Der theoretisch ideale Impuls ist der [Dirac-Impuls](Skript-SY-V1.5.pdf#page=14&selection=81,0,81,12|Skript-SY-V1.5, page 14) auch Dirac-Stoß, 𝛿-Impuls oder 𝛿- Funktion), der zwar ==unendlich kurz== ist, aber dennoch eine Signalenergie > 0 aufweist. 

Eigenschaften:
$$
\int_{-\infty}^\infty 
\delta(t) \cdot
x(t) dt = 
x(0) \quad \Rightarrow \quad
\int_{-\infty}^\infty
\delta(t)dt = 1 
$$
oder
$$
\int_{a}^b 
\delta(t)dt = \begin{cases}
1 & ; a \leq 0 \leq b \\
0 & ; \text{sonst}
\end{cases}
$$
und 
$$
t \cdot \delta(t) = 0 \quad \Rightarrow \quad
\delta(t) = 0 \space \forall \space t \neq 0
$$
$$
\delta(-t) = \delta(t) \quad \text{(gerade Funktion)}
$$

$$
\delta(t)
$$
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=Ug3eSKGf]]

$$
\delta(t-T)
$$
![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Notizen/SY Signale.excalidraw.md#^group=d73DXekO]]

Der Pfeil wird üblicherweise mit der Höhe 1 gezeichnet um 𝛿(𝑡) darzustellen, d. h. für 𝐶 ∙ 𝛿(𝑡) ist der Pfeil entsprechend 𝐶 hoch.



## [Repräsentationsfunktionen](Skript-SY-V1.5.pdf#page=16&selection=6,0,6,24|Skript-SY-V1.5, page 16)

Dreiecksimpuls:
$$
\delta_{\varepsilon}(t) = 
\frac{1}{\varepsilon} tri\left( \frac{t}{\varepsilon} \right)
\quad | \space \varepsilon \rightarrow 0
$$
Rechteckimpuls:
$$
\delta_{\varepsilon}(t) = 
\frac{1}{\varepsilon} rect\left( \frac{t}{\varepsilon} \right)
\quad | \space \varepsilon \rightarrow 0
$$
Annäherungsfunktion:
$$
\delta_{\varepsilon}(t) = \frac{1}{\pi} \frac{\varepsilon}{t²+\varepsilon²}
\quad | \space \varepsilon \rightarrow 0
$$
wobei hier der Funktionswert an Stelle t=0 gegen unendlich geht  .


