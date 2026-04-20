Quelle: Teil 5 – Erweiterte Regelungsstrukturen

## Windup-Problem
- I-Anteil im Regler **integriert weiter**, auch wenn Stellgröße $u$ bereits **gesättigt** ist (z.B. Ventil voll offen)
- Beim Verlassen der Sättigung: großes Überschwingen durch aufgefüllten Integrator

## ARW-Maßnahme (Anti-Reset-Windup)
- **Bedingte Integration**: I-Anteil wird eingefroren, wenn Stellgröße begrenzt
- **Back-Calculation**: Differenz zwischen tatsächlicher und ungegrenzter Stellgröße wird zurückgeführt und korrigiert den Integratorzustand

## Bedeutung
- In der Praxis **immer** notwendig bei Reglern mit I-Anteil und Stellgrößenbegrenzung
