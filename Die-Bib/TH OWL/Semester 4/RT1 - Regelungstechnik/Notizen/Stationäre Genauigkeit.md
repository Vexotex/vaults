Quelle: Teil 3 – Einschleifiger Regelkreis

## Bleibende Regeldifferenz
$$e_\infty = \lim_{t \to \infty} e(t) = \lim_{s \to 0} s \cdot E(s)$$

Mit $E(s) = \dfrac{1}{1 + G_o(s)} \cdot W(s)$

## Systemtyp
- Anzahl der Integratoren im offenen Kreis $G_o(s)$

| Systemtyp | Sprung $w = \frac{1}{s}$ | Rampe $w = \frac{1}{s^2}$ |
|-----------|--------------------------|---------------------------|
| 0 (kein I) | $e_\infty \neq 0$ | $e_\infty \to \infty$ |
| 1 (ein I) | $e_\infty = 0$ | $e_\infty \neq 0$ |
| 2 (zwei I) | $e_\infty = 0$ | $e_\infty = 0$ |

## Fazit
- **PI- oder I-Regler** nötig für $e_\infty = 0$ bei Sprung
