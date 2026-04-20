Quelle: Teil 7 – Implementierung, Simulation, Anwendung

## Inkrementalgeber
- Liefert Impulse proportional zur Winkelbewegung
- **Vierfachauswertung**: 4× Auflösung durch Auswertung beider Flanken beider Kanäle

## Drehzahlerfassung (aus Inkrementalgeber)
### Frequenzmessung (hohe Drehzahl)
$$n = \frac{\Delta\text{Pulse}}{\Delta t \cdot N_{Geber}}$$

### Periodenmessung (niedrige Drehzahl)
$$n = \frac{1}{t_{Periode} \cdot N_{Geber}}$$

## Auflösungsproblem
- Bei niedriger Drehzahl: wenige Pulse pro Abtastperiode → grobe Quantisierung
- Lösung: Periodenmessung oder Schätzverfahren (Luenberger-Beobachter)
