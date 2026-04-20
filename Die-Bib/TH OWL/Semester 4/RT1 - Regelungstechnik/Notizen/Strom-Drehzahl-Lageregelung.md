Quelle: Teil 6 – Kaskadenregelung

## Kaskadierte Struktur
$$\text{Lage-Soll} \rightarrow [\text{Lageregler}] \rightarrow \text{Drehzahl-Soll} \rightarrow [\text{Drehzahlregler}] \rightarrow \text{Strom-Soll} \rightarrow [\text{Stromregler}] \rightarrow \text{Spannung}$$

## Entwurfsreihenfolge (innen → außen)
1. **Stromregler** (schnellste Dynamik, $T_A$ klein) → Symmetrisches Optimum
2. **Drehzahlregler** (mittlere Dynamik) → Betragsoptimum oder Frequenzkennlinien
3. **Lageregler** (langsamste Dynamik) → oft P-Regler

## 4Q-Steller
- Leistungselektronische Ansteuerung des Motors
- Ermöglicht motorischen und generatorischen Betrieb in beiden Drehrichtungen
- Modelliert als $G_{St}(s) \approx \frac{1}{1 + T_{St} s}$ (kleine Zeitkonstante)
