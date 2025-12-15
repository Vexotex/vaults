[[Objektorientierte Analyse und Design - Info]]

# Vorlesung
- [[Objektorientierung 2025.pdf]]
	- [[_Objektorientierung]]
- [[Analyse25.pdf]]
- [[Aspekte25.pdf]]
- [[Systemdesign25.pdf]]
- [[ThreatModeling25.pdf]]

- [[Git.pdf]]

# Übung
- [[Aufgabenblatt 1]]
- [[Aufgabenblatt 2]]
- [[Aufgabenblatt 3]]
- [[Aufgabenblatt 4]]


# Ausarbeitung

## Infos
1. Themen für die Ausarbeitung werden durch Umfage im Ilias bis zum 15.12.2025 vergeben. Die Themen werden am 8.12.2025 vorgestellt.
2. Gruppeneinteilung bitte über Umfrage auf der Vorlesungsseite, maximal 3 Personen pro Gruppe. Die Gruppen müssen bis zum 15.12.2025 feststehen.
3. In der Vorlesung wird auch eine Schablone für die Ausarbeitung vorgestellt.
4. Ausarbeitung: ca. 15 Seiten pro Person, die Beiträge müssen namentlich gekennzeichnet werden.
5. Die Vorlesungen in 2026 werden zu einem Praktikum, in dem jede Gruppe Fragen stellen kann, und die der Bearbeitung der Ausarbeitung dienen.
6. Die Ausarbeitung muss spätestens am 24. Februar 2026 per Email an sebastian.gutsche@th-owl.de abgegeben werden.
7. Ausschließlich die fertige Ausarbeitung wird benotet.


## Thema & Aufgabenstellung
### Projekt 3: Lagerverwaltung

Wir designen die Lagerverwaltung eines Großhändlers. Der Großhändler besitzt mehrere Lager. Wir wollen sowohl eine zentrale Bestandsaufnahme als auch eine Bestandsaufnahme an jedem Standort, so dass die Systeme autark funktionieren können.

Zentral soll nur gespeichert werden, wie viele Gegenstände von welcher Art an welchem Standort vorhanden sind.

In jedem Standort soll außerdem die Position des Gegenstandes im Lager angezeigt werden. Es kann davon ausgegangen werden, dass jedes Lager die gleiche Struktur hat.

Das System soll die Möglichkeit haben, anfragen bearbeiten zu können, es sollen also Gegenstände eingelagert, ausgelagert und angezeigt werden können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden.

Weiterhin soll jeder Zugriff und jede Entnahme von Gegenständen gespeichert werden. Weiterhin soll es die Möglichkeit geben, automatisch Auswertungen einzelner Artikel zu erstellen: Wie viele Verkäufe, etc. Das System soll dann in der Lage sein, Artikel, die nicht häufig angefragt werden, nicht mehr an allen Standorten vorzuhalten oder zu entscheiden, dass ein Artikel an mehreren Standorten vorgehalten werden soll. Hierzu soll es die passende Abteilung per Email informieren oder automatisch für andere Standorte zu bestellen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.

---
## Design Template

### Problemstellung

Beschreibe, möglichst knapp, das Problem

### Pflichtenheft / Problemanalyse

Dokumentiere möglichst genau, was das System tun soll. Dieser Abschnitt soll enthalten:

- Dokumentation Akteure und Anwendungsfälle
    
- Ablaufpläne
    
- Dokumentation von nicht ersichtlichem Bedarf
    

Beschreibe für jeden Anwendungsfall mindestens einen Ablaufplan! Am besten unterlegst du die tabellarische Form mit einem Kommunikationsdiagram (siehe Vorlesung Systemdesign).

### Systemdesign

Gebe eine grobe Übersicht über alle Komponenten des Systems (Server/Client/Datenbank/etc.) und wie diese Systeme zusammenspielen. Zeichne Diagramme und dokumentiere alle APIs.

#### Threat model

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

Beschreibe für jeden potentiellen threat eine Lösung


### Komponentendesign
Erzeuge den nächsten Abschnitt für jede Komponente

#### Komponente 1

##### Beschreibung
Beschreibe die Komponente: Funktion, Rolle im System

##### Design: Klassendiagramm/Datenflussdiagram
Erzeuge, je nachdem, ob die Komponente funktional oder objektorientiert implementiert werden soll, die passenden Diagramme, und dokumentiere diese.
Dokumentiere alle Funktionen in den Klassen/Datenflussdiagrammen.
Falls UI, so muss ein UI mock erzeugt werden.

##### Threat model und Risikoanalyse
Führe, wie oben, eine threat Analyse und eine Risikobewertung durch

##### Optional: Code
Implementiere die Komponente, oder schaffe ein Gerüst für die Klassen

#### Komponente 2

#### Komponente 3

