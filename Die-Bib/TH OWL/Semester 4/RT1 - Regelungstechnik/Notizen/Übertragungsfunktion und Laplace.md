Quelle: Teil 2 – Übertragungssysteme

## Laplace-Transformation
- Überführt DGL im Zeitbereich in algebraische Gleichung im Bildbereich
- $\mathcal{L}\{f(t)\} = F(s)$, mit $s = \sigma + j\omega$

## Übertragungsfunktion
$$G(s) = \frac{Y(s)}{U(s)}$$

- Gilt nur für **LTI-Systeme** bei **Nullanfangsbedingungen**

## Pol-Nullstellen-Darstellung
$$G(s) = K \cdot \frac{\prod_i (s - z_i)}{\prod_j (s - p_j)}$$

- **Pole** $p_j$: Nenner = 0 → bestimmen Stabilität und Dynamik
- **Nullstellen** $z_i$: Zähler = 0 → beeinflussen Frequenzverhalten
- Stabiles System: alle Pole in **linker** s-Halbebene
