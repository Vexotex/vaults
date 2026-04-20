Quelle: Teil 2 – Übertragungssysteme

## Allgemeine Form
$$\dot{\mathbf{x}}(t) = \mathbf{A}\,\mathbf{x}(t) + \mathbf{B}\,u(t)$$
$$y(t) = \mathbf{C}\,\mathbf{x}(t) + D\,u(t)$$

- $\mathbf{x}$: Zustandsvektor (innere Systemzustände)
- $\mathbf{A}$: Systemmatrix, $\mathbf{B}$: Eingangsmatrix
- $\mathbf{C}$: Ausgangsmatrix, $D$: Durchgangsterm

## Integratorkette
- Standardform für ein System $n$-ter Ordnung
- Jeder Zustand ist Integral des vorherigen

## Zusammenhang mit Übertragungsfunktion
- $G(s) = \mathbf{C}(s\mathbf{I} - \mathbf{A})^{-1}\mathbf{B} + D$
