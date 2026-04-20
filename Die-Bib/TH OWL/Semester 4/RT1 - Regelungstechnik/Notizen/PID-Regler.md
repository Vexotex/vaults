Quelle: Teil 3 – Einschleifiger Regelkreis

## Übertragungsfunktion
$$G_R(s) = K_P \left(1 + \frac{1}{T_n s} + T_v s\right)$$

- $K_P$: Proportionalverstärkung
- $T_n$: Nachstellzeit (I-Anteil)
- $T_v$: Vorhaltzeit (D-Anteil)

## Reglervarianten
| Typ | Eigenschaft |
|-----|-------------|
| P | Einfach, bleibende Regeldifferenz |
| PI | Kein bleibender Fehler, leichte Phasendrehung |
| PD | Schneller, aber kein I-Anteil |
| PID | Kompromiss aus allen Eigenschaften |

## D-Anteil in der Praxis
- Reines D-Glied nicht realisierbar → **PID-T1**: $T_v s$ ersetzt durch $\frac{T_v s}{1 + T_1 s}$
