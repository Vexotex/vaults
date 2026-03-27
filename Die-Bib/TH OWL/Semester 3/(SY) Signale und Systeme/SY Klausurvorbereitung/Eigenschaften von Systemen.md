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