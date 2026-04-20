Quelle: Teil 7 – Implementierung, Simulation, Anwendung

## Quasikontinuierlicher Ansatz
- Kontinuierlich entworfenen Regler $G_R(s)$ **diskretisieren**
- Gilt für: Abtastzeit $T_0 \ll$ kleinste Systemzeitkonstante

## Diskretisierungsmethoden
| Methode | Formel | Eigenschaft |
|---------|--------|-------------|
| Vorwärts-Euler | $s \approx \frac{z-1}{T_0}$ | Einfach, instabil bei großem $T_0$ |
| Rückwärts-Euler | $s \approx \frac{z-1}{T_0 z}$ | Stabil, ungenau |
| Tustin (bilinear) | $s \approx \frac{2}{T_0} \frac{z-1}{z+1}$ | Genauest, empfohlen |

## Implementierungsschritte (Checkliste)
1. Regleralgorithmus als Task implementieren
2. [[Anti-Windup]]-Maßnahme einbauen
3. ADC-Abtastung synchronisieren
4. Stellgrößenbegrenzung vorsehen
5. Task-Timing sicherstellen (periodisch, harte Echtzeit)
