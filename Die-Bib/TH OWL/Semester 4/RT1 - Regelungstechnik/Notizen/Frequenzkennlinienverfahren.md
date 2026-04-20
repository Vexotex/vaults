Quelle: Teil 4 – Frequenzbereichsverfahren

## Vorgehen
1. **Reglerstruktur wählen** (P, PI, PID) anhand Streckentyp und Anforderungen
2. **Bode-Diagramm** des offenen Kreises $G_o^*(j\omega) = G_R(j\omega) \cdot G_S(j\omega)$ zeichnen
3. **Phasenreserve-Vorgabe** $\varphi_r$ festlegen (z.B. 60°)
4. **Parameter ermitteln**: $K_P$ so wählen, dass Amplitudenkennlinie bei $\omega_D$ durch 0 dB geht

## Regler-Auswahl nach Strecke
| Strecke | Empfohlener Regler |
|---------|-------------------|
| PT1 | P oder PI |
| PT2, PT3 | PI oder PID |
| I-Strecke | P oder PD |

## Vorteil
- Intuitiv nachvollziehbar
- Robustheit direkt über $\varphi_r$ einstellbar
