Quelle: Teil 5 – Erweiterte Regelungsstrukturen

## Problem
- Standardregelkreis reagiert auf Störungen erst, wenn $y$ sich ändert → Verzögerung
- Bei messbaren Störungen: Vorwärtskopplung möglich

## Struktur
- Störung $z$ wird **gemessen** und über $G_A(s)$ dem Reglerausgang additiv überlagert
- Ziel: $G_A(s)$ so wählen, dass Störeinfluss auf $y$ minimiert wird

## Ideale Aufschaltung
$$G_A(s) = -\frac{1}{G_{S2}(s)}$$
→ Störung wird vollständig kompensiert (nur ideal, in Praxis näherungsweise)

## Vorteil
- Schnellere Störkompensation als reiner Regelkreis
- Kombination mit Regler für verbleibende Fehler
