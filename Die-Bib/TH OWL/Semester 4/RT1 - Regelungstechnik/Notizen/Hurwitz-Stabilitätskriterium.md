Quelle: Teil 3 – Einschleifiger Regelkreis

## Anwendung
- Stabilitätsanalyse **ohne** Berechnung der Pole
- Gilt nur für LTI-Systeme mit bekanntem charakteristischem Polynom

## Charakteristisches Polynom
$$N(s) = a_n s^n + a_{n-1} s^{n-1} + \ldots + a_1 s + a_0$$

## Bedingungen
**Notwendige Bedingung (a)**: Alle Koeffizienten $a_i > 0$

**Hinreichende Bedingung (b)**: Alle Hauptminoren der Hurwitz-Matrix positiv
$$H = \begin{pmatrix} a_{n-1} & a_{n-3} & \ldots \\ a_n & a_{n-2} & \ldots \\ 0 & a_{n-1} & \ldots \end{pmatrix}$$

## Vereinfachung für n ≤ 3
- $n=2$: $a_0, a_1, a_2 > 0$ reicht
- $n=3$: zusätzlich $a_1 a_2 > a_0 a_3$
