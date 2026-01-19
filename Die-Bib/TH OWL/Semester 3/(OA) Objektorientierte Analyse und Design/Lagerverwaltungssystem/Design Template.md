# Problemstellung
Beschreibe, möglichst knapp, das Problem
- [x] 
# Pflichtenheft / Problemanalyse
Dokumentiere möglichst genau, was das System tun soll. Dieser Abschnitt soll enthalten:
- Dokumentation Akteure und Anwendungsfälle
- Ablaufpläne
- Dokumentation von nicht ersichtlichem Bedarf
Beschreibe für jeden Anwendungsfall mindestens einen Ablaufplan! Am besten unterlegst du die tabellarische Form mit einem Kommunikationsdiagram (siehe Vorlesung Systemdesign).
- [x] 
# Systemdesign
Gebe eine grobe Übersicht über alle Komponenten des Systems (Server/Client/Datenbank/etc.) und wie diese Systeme zusammenspielen. Zeichne Diagramme und dokumentiere alle APIs.
- [ ] 
## Threat model
Erzeuge threat model und Risikoanalyse deines Systemdesigns. Hierbei können die folgenden Werte für die Risikoanalyse verwendet werden:
- Damage potential
	- Daten
		- 0: Kein Verlust kritischer Daten
		- 1: Verlust eines einzelnen Datensatzes
		- 5: Verlust einer bestimmten Gruppe von Datensätzen (Beispiel: Alle Nutzer eines bestimmten Landes, alle Personaldaten einer bestimmten Abteilung)
		- 10: Verlust aller Nutzerdaten
	- System:
		- 0: Kein Ausfall
		- 5: Übernahme einzelner Server
		- 10: Komplettausfall des gesamten Systems
	- Finanziell:
		- 0: Kein finanzieller Schaden
		- 5: niedriger finanzieller Schaden (<1000€)
		- 8: Fester, hoher finanzieller Schaden
		- 9: Prozentsatz des Gewinns
		- 10: Komplettverlust aller Werte
- Reproducibility
	- Übernehme die Werte aus Vorlesung
- Exploitability
	- Übernehme Werte aus Vorlesung
	- Affected Users
	- 0: Wenige Nutzer
	- 3: Hohe Anzahl, aber fest
	- 5: 1% der Nutzer
	- 9:10% der Nutzer
	- 10: Alle Nutzer
- Discoverability
	- Übernehme die Werte aus der Vorlesung
- [ ] 
Beschreibe für jeden potentiellen threat eine Lösung
- [ ] 

# Komponentendesign
Erzeuge den nächsten Abschnitt für jede Komponente
- [ ] 
## Komponente 1
### Beschreibung
Beschreibe die Komponente: Funktion, Rolle im System
- [ ] 
### Design: Klassendiagramm/Datenflussdiagram
Erzeuge, je nachdem, ob die Komponente funktional oder objektorientiert implementiert werden soll, die passenden Diagramme, und dokumentiere diese.
Dokumentiere alle Funktionen in den Klassen/Datenflussdiagrammen.
Falls UI, so muss ein UI mock erzeugt werden.
- [ ] 
### Threat model und Risikoanalyse
Führe, wie oben, eine threat Analyse und eine Risikobewertung durch
- [ ] 
### Optional: Code
Implementiere die Komponente, oder schaffe ein Gerüst für die Klassen

## Komponente 2

## Komponente 3

