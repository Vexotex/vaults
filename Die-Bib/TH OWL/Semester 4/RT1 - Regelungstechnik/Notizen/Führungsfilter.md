Quelle: Teil 5 – Erweiterte Regelungsstrukturen

## Problem
- Bei PID-Entwurf: Zielkonflikt zwischen gutem Führungsverhalten und gutem Störverhalten
- Regler auf Störverhalten optimiert → schlechtes Führungsverhalten (und umgekehrt)

## Lösung: Vorfilter $G_V(s)$
- Zusätzliches Filter **vor** dem Regelkreis
- Formt Führungsgröße $w$ so, dass $y$ sanft dem Sollwert folgt
- Regler kann unabhängig auf Störverhalten ausgelegt werden

## Auslegung
- $G_V(s) = \dfrac{1}{G_w(s)|_{\text{ideal}}}$ (vereinfacht)
- Häufig: einfaches PT1 oder PT2 als Führungsfilter
