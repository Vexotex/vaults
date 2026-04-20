Quelle: Teil 2 – Übertragungssysteme

## Motivation
- LTI-Methoden gelten nur für lineare Systeme
- Viele reale Systeme sind nichtlinear (z.B. Pendel)
- Lösung: Linearisierung um einen **Arbeitspunkt (Ruhelage)**

## Vorgehen
1. Ruhelage $\mathbf{x}_0, u_0$ bestimmen: $\dot{\mathbf{x}} = 0$
2. Taylorentwicklung 1. Ordnung um Ruhelage
3. **Jacobi-Matrizen** bilden:
$$\mathbf{A} = \left.\frac{\partial \mathbf{f}}{\partial \mathbf{x}}\right|_{\mathbf{x}_0, u_0}, \quad \mathbf{B} = \left.\frac{\partial \mathbf{f}}{\partial u}\right|_{\mathbf{x}_0, u_0}$$

## Gültigkeit
- Nur für **kleine Abweichungen** von der Ruhelage gültig
- Beispiel: Pendel linearisiert um $\theta = 0$ → $\sin\theta \approx \theta$
