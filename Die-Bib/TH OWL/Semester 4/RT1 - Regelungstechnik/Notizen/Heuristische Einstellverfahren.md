Quelle: Teil 3 – Einschleifiger Regelkreis

## Ziegler-Nichols (Schwingungsversuch)
1. I- und D-Anteil abschalten (reiner P-Regler)
2. $K_P$ erhöhen bis Dauerschwingung → **kritische Verstärkung** $K_{krit}$, **Periodendauer** $T_{krit}$
3. Parameter ablesen aus Tabelle:

| Regler | $K_P$ | $T_n$ | $T_v$ |
|--------|--------|--------|--------|
| P | $0{,}5 \cdot K_{krit}$ | — | — |
| PI | $0{,}45 \cdot K_{krit}$ | $0{,}85 \cdot T_{krit}$ | — |
| PID | $0{,}6 \cdot K_{krit}$ | $0{,}5 \cdot T_{krit}$ | $0{,}12 \cdot T_{krit}$ |

## Sprungantwortverfahren (Wendetangente)
- Aus Sprungantwort der Strecke: Verzugszeit $T_u$, Ausgleichszeit $T_g$
- Einfacher, aber weniger genau als Schwingungsversuch
