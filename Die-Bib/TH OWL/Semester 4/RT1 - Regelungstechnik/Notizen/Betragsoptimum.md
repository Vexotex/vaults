Quelle: Teil 5 – Erweiterte Regelungsstrukturen

## Ziel
- Führungsübertragungsfunktion $G_w(j\omega)$ soll möglichst **flachen Frequenzgang** haben
- $|G_w(j\omega)| \approx 1$ über großen Frequenzbereich → gutes Führungsverhalten

## Optimierungsbedingung
$$|G_w(j\omega)|^2 = 1 \quad \Rightarrow \quad \text{Koeffizientenvergleich}$$

## Ergebnis (typisch für PT2-Strecke mit PI-Regler)
- Nachstellzeit: $T_n = T_1$ (größte Zeitkonstante der Strecke)
- Verstärkung: $K_P = \dfrac{T_1}{2 \cdot K_S \cdot T_2}$

## Eigenschaften
- Überschwingweite: $\approx 4{,}3\%$
- Gutes Störverhalten
- Bei großer Summenzeitkonstante: [[Führungsfilter]] empfohlen
