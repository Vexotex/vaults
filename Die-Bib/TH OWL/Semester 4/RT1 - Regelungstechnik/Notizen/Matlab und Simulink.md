Quelle: Teil 7 – Implementierung, Simulation, Anwendung

## Matlab
- Numerische Berechnung, Übertragungsfunktionen, Bode/Nyquist-Plots
- Wichtige Funktionen: `tf()`, `bode()`, `nyquist()`, `step()`, `rlocus()`

## Simulink
- Grafische Blockschaltbild-Simulation
- Wirkungspläne direkt umsetzen
- Regler und Strecke als Blöcke verbinden

## Solver-Auswahl
| Solver | Typ | Einsatz |
|--------|-----|---------|
| ode45 | explizit, adaptiv | Standardfall |
| ode23 | explizit, adaptiv | Grobe Genauigkeit |
| ode15s | implizit | Steife Systeme |
| ode4 (RK4) | fest | Echtzeit-Simulation |

## Wichtige Einstellungen
- **Relative/Absolute Toleranz**: Genauigkeit des Solvers
- **Max. Schrittweite**: Wichtig für Regelkreis-Simulation (≤ $T_0/10$)
