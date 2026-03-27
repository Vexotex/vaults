![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^group=Y4p_qqmb86OBpwIWFcP6t]]




# Linearität

$$
\begin{array} \\

f(u_{1}) + f(u_{2}) = f(u_{1} + u_{2})  \\
f(a*u_{1}) = a*f(u_{1})
\end{array}
$$

## Bsp:
$$
\begin{array} \\
f(u) = 3u \\
3u_{1} + 3u_{2} = 3 (u_{1}+u_{2}) && \checkmark \\
 \\
f(u) = u^{2} \\
(u_{1})^{2} + (u_{2})^{2} \neq (u_{1}+u_{2})^{2} = (u_{1})^{2}+2u_{1}u_{2} + (u_{2})^{2} && \text{X} \\
 \\
 f(u) = \sin(u) \\
3u \neq 3 \sin(u) && \text{X} \\

 \\
f(u) = \int u \space dt && \checkmark \\
f(u) = \frac{d}{dt}u && \checkmark
\end{array}
$$



# Kausalität:

Mathematisch nicht wichtig für Systemtheorie. Allerdings sind akausale Systeme nicht realistisch, weil sie sonst die Zukunft vorhersagen könnten.

"Wir können nur auf Dinge antworten, die entweder jetzt gerade passieren oder in der Vergangenheit liegen"

$$
f(u) = \frac{d}{dt} u = \frac{u(t+h)-u(t)}{h}
$$
Hier würde $u(t+h)$ auf Werte der Zukunft greifen... und das geht nicht



# Zeitinvarianz

Besagt, dass das Ausgangssignal nicht abhängig von dem zeitlichen auftreten des Eingangssignal ist.

"Ob ich eine Glocke jetzt oder in einer halben Stunde anschlage wird sie den gleichen Ton von sich geben"
$$
f(u(t)) = y(t) \Rightarrow f(u(t-a)) = y(t-a)
$$
## Bsp: 

$$
\begin{array} \\
f(u) = e^{ u(t) } && \checkmark \\
f(u) = t \cdot e^{ u(t) } && \text{X}
\end{array}
$$ 

# Gedächtnisbehaftung (Dynamisch $\leftrightarrow$ Statisch)

Ein dynamisches System ist Gedächtnisbehaftet. Ein statisches nicht.

$$
\begin{array} \\
f(u) = e^{ u(t) } && \text{X} \\
f(u) = u(t-a) , a \neq 0 && \checkmark \\
f(u) = \int u \space dt && \checkmark
\end{array}
$$

statisch greift nur auf aktuelle Werte zu
dynamisch auf vergangene oder zukünftige (muss nicht kausal sein)


# Sprungfähigkeit

![[TH OWL/Semester 3/(SY) Signale und Systeme/SY Klausurvorbereitung/Klausurvorberreitung.excalidraw.md#^frame=8Jg0uJZk3Z-6tZl5KcbA7]]

Wenn das Ausgangssignal springen kann
$$
f(u) = 3u \quad \checkmark
$$
hier wäre der Sprung am Ausganssignal 3-Mal so hoch wie beim Eingangssignal kann also springen
$$
f(u) = \int u \space dt \quad \text{X}
$$
nein, weil das Integral auf einen Bereich verweist und auch wenn der sich sprungartig verändert, wenn auch steil aber nur stetig an.
$$
f(u) = \frac{d}{dt}u
$$
ja, da die Ableitung einer Sprungstelle theoretisch eine unendliche Steigung hat, würde hier auch das Ausgangssignal sprungfähig sein.


# Durchgriff

Nur, wenn das System auch Sprungfähig ist und bedeutet, dass wenn das Eingangssignal springt. Das Ausgangssignal auch sofort springt und nicht mit zeitlicher Verzögerung
mit Durchgriff "springt das Signal durch"
ohne Durchgriff nicht


# Stabilität

Bedeutet das sich das System nicht selber zerstört, also abklingend (oder haltend)
Wenn das System immer weiter aufklingt, ist das System instabil