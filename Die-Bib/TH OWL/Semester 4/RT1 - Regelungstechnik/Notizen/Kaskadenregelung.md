Quelle: Teil 6 – Kaskadenregelung

## Motivation
- Einschleifiger Regelkreis stößt bei komplexen Strecken an Grenzen
- Störungen tief in der Strecke werden sehr spät ausgeregelt

## Struktur
- **Innerer Regelkreis** (Hilfsregelkreis): regelt innere Hilfsgröße $y_h$ schnell
- **Äußerer Regelkreis** (Hauptregelkreis): regelt eigentliche Regelgröße $y$
- Ausgang des äußeren Reglers = **Sollwert** des inneren Kreises

$$w \rightarrow G_{R,äuß} \rightarrow w_h \rightarrow G_{R,inn} \rightarrow u \rightarrow G_{S1} \rightarrow y_h \rightarrow G_{S2} \rightarrow y$$

## Entwurfsreihenfolge
1. Inneren Regelkreis zuerst auslegen (schnell, z.B. mit [[Symmetrisches Optimum]])
2. Äußeren Regelkreis auslegen (langsamer, innerer Kreis = Teil der Strecke)

## Faustregel
- Innerer Kreis mind. **3–5× schneller** als äußerer
