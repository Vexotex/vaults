Quelle: Teil 6 – Kaskadenregelung

## Elektrische Gleichung (Ankerkreis)
$$U_A = R_A \cdot I_A + L_A \cdot \dot{I}_A + U_{ind}$$
$$U_{ind} = k_\Phi \cdot \omega$$

## Mechanische Gleichung
$$M_{el} = k_\Phi \cdot I_A$$
$$J \cdot \dot{\omega} = M_{el} - M_{Last}$$

## Parameter
| Symbol | Bedeutung |
|--------|-----------|
| $R_A$ | Ankerwiderstand |
| $L_A$ | Ankerinduktivität |
| $k_\Phi$ | Motor-/Generatorkonstante |
| $J$ | Trägheitsmoment |

## Übertragungsfunktionen
- Elektrische Zeitkonstante: $T_A = L_A / R_A$ (klein)
- Mechanische Zeitkonstante: $T_M = J R_A / k_\Phi^2$ (groß)
