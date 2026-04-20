Quelle: Teil 2 – Übertragungssysteme

## Grundglieder

| Glied | $G(s)$ | Eigenschaft |
|-------|---------|-------------|
| P | $K_P$ | Proportional, keine Dynamik |
| I | $\frac{1}{T_I s}$ | Integrierend, bleibende $e$ → 0 |
| D | $T_D s$ | Differenzierend, nicht realisierbar allein |
| PT1 | $\frac{K}{1 + Ts}$ | Verzögerung 1. Ordnung |
| PT2 | $\frac{K}{1 + 2DTs + T^2s^2}$ | Verzögerung 2. Ordnung (Dämpfung $D$) |
| IT1 | $\frac{K}{s(1+Ts)}$ | I-Glied mit Verzögerung |
| Tt | $e^{-T_t s}$ | Totzeit |

## PT2-Sonderfall
- $D > 1$: zwei reelle Pole (überdämpft)
- $D = 1$: Doppelpol (aperiodischer Grenzfall)
- $0 < D < 1$: konjugiert komplexe Pole (schwingend)
