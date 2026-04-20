Quelle: Teil 7 – Implementierung, Simulation, Anwendung

## Motivation
- Reale Antriebe haben **elastische Kupplung** zwischen Motor und Last
- Motor und Last sind keine starre Einheit → **Zweimassensystem (ZMS)**

## Modell
$$J_1 \ddot{\phi}_1 = M_{el} - c(\phi_1 - \phi_2) - d(\dot{\phi}_1 - \dot{\phi}_2)$$
$$J_2 \ddot{\phi}_2 = c(\phi_1 - \phi_2) + d(\dot{\phi}_1 - \dot{\phi}_2) - M_{Last}$$

- $c$: Federsteifigkeit, $d$: Dämpfung der Kupplung
- $J_1$: Motorträgheit, $J_2$: Lastträgheit

## Charakteristik
- Resonanzfrequenz: $\omega_{Res} = \sqrt{c \left(\frac{1}{J_1} + \frac{1}{J_2}\right)}$
- Erzeugt **Resonanzüberhöhung** im Frequenzgang → Stabilitätsproblem
- Maßnahmen: Notch-Filter, geringere Reglerverstärkung, aktive Dämpfung
