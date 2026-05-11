Quelle: Teil 3 – Einschleifiger Regelkreis

## Anwendung
- Stabilitätsanalyse **ohne** Berechnung der Pole
- Gilt nur für LTI-Systeme mit bekannter Gesamtübertragungsfunktion

## Nenner Polynom der Gesamtübertragungsfunktion 
$$N(s) = a_n s^n + a_{n-1} s^{n-1} + \ldots + a_1 s + a_0$$

## Bedingungen
**Notwendige Bedingung (a)**: Alle Koeffizienten $a_i > 0$

**Bedingung (b)**: Alle Hurwitzdeterminanten der Hurwitz-Matrix > 0 
$$H = \begin{pmatrix}
a_{n-1} & a_{n-3} & a_{n-5} & a_{n-7} & \ldots & 0 \\
a_n     & a_{n-2} & a_{n-4} & a_{n-6} & \ldots & 0 \\
0       & a_{n-1} & a_{n-3} & a_{n-5} & \ldots & 0 \\
0       & a_n     & a_{n-2} & a_{n-4} & \ldots & 0 \\
\vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
0&0&0&0& \dots &a_{0}
\end{pmatrix}$$

## Vereinfachung für n ≤ 3
- $n=2$: $a_0, a_1, a_2 > 0$ reicht
- $n=3$: zusätzlich $a_1 a_2 > a_0 a_3$
