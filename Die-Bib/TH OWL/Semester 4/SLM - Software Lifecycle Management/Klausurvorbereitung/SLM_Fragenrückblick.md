[[009_SLM_Fragenrueckblick.pdf]]

## 1. Welche zentralen Werkzeuge und Methoden nutzt ALM?
die Werkzeuge und Methoden lassen sich gut entlang der ALM-Disziplinen gliedern:

1. (REQ) Requirement Management
	- **Methoden:** Anforderungsanalyse, Anforderungsspezifikation mit EARS (_Easy Approach to Requirements Syntax_)
	- **Werkzeuge:** Lastenheft, Pflichtenheft die Softwareanforderungsspezifikation (SAS)
	
2. (TQM) Test and Quality Management
	- **Methoden:** Test Driven Development (TDD), 
	- **Werkzeuge:** Formalisierte Testpläne, Testberichte (_Defect Reports_) und statische Codeanalyse-Werkzeuge
	
3. (IDM) Issue and Defect Managment
	- **Methoden:**  Tickets Tracken von Umwelteinflüssen und Fehlern (Defect Tracking)
	- **Werkzeuge:** Jira, Redmine
	
4. (CCM) Change and Configure Managment
	- **Methoden:**  Request for Change (RfC), Konfigurations-Identifikationsdokument (KID), Change Record (CR)
	- **Werkzeuge:** Git, Team Foundation Server (TFS)
	
5. (RM) Resource Management
	- **Methoden:** Drei-Punkt-Schätzung
	- **Werkzeuge:** Redmine
	
6. (VM) Version Management
	- **Methoden:**  Versionsverwaltung und die Steuerung der Produktvariantenvielfalt
	- **Werkzeuge:** Git
	
7. (BRM) Build and Realese Management
	- **Methoden:**  Nightly Builds / Daily Builds, strukturierte Releasewechselplanung
	- **Werkzeuge:** Releasewechselpläne, Build-Server

# 2. Welche Managementdisziplinen sind Teil des ALM?
1. (REQ) Requirement Management
2. (TQM) Test and Quality Management
3. (IDM) Issue and Defect Management
4. (CCM) Change and Configure Managment
5. (RM) Resource Management
6. (VM) Version Management
7. (BRM) Build and Realease Management

# 3. Welche Ergebnisse werden neben dem Quelltext bei der Software-Entwicklung erzeugt?
- Analysedokumente: Lastenheft, Pflichtenheft, Funktionale Einheiten, GUI-Prototypen
- Architekturdokumente: UML-Diagramme, Kontext- und Schichtenmodelle
- Technische Spezifikationen: Festlegung von Schnittstellen, Datenstrukturen, Algorithmen
- Verlaufsdokumente: Gantt-Diagramme, Definition von Rollen, Tickets
- Testdokumente: Testfälle, Testpläne, Testergebnisse, Bugreports
- Änderungsanträge, Änderungsberichte
- Konfigurations-Identifikationsdokument
- Installer, Systemdokumentation, Benutzerhandbuch

# 4. Welche Phasen laufen in jedem Softwareentwicklungsprozess ab?
1. Analyse
2. Entwurf
3. Implementierung
4. Qualitätssicherung
5. Evolution

# 5. Was ist ein Software-Prozess?
"Software ist die Menge von Programmen oder Daten zusammen mit begleitenden Dokumenten, die für ihre Anwendung notwendig oder hilfreich sind." 
- Hesse et al, 1984

# 6. Was meint man mit dem Begriff "Software Lifecycle"?
Die Software wird von Idee "über ihren Lebenszyklus hinweg" bis hin zur Abkündigung gemanaget

# 7. Welche Unterschiede oder Gemeinsamkeiten hat Software als Produkt zu anderen Produkten?

| Unterschiede                         | Gemeinsamkeiten              |
| ------------------------------------ | ---------------------------- |
| immaterielles gut                    | Phasenbezogener Lebenszyklus |
| kein Verschleiß                      |                              |
| Kosten hauptsächlich bei Entwicklung |                              |

# 8. Was regeln Vorgehensmodelle?
Aktivitäten:
- Analyse
- Entwurf
- Entwicklung
- Qualitätssicherung
---
Ein Software-Vorgehensmodell konkretisiert einen Software-Prozess in allen Phasen und definiert Aktivitäten, Methoden, Rollen, Ergebnisse

# 9. Welche Vorgehensmodelle gibt es?
Klassisch
Agil
Gemischt (Klassisch + Agil)
Generisch (Klassisch oder Agil anpassbar)

# 10. Welche Regeln, Rollen, Werkzeuge, Methoden, Aktivitäten, Philosophien gibt es in den verschiedenen Vorgehensmodellen?
**Klassische Vorgehensmodelle:**
- Wasserfallmodell
- V-Modell
- Komonentenbasierte Entwicklung
- Rational Unified Process (RUP)
- Joint Application Development (JAD)
- ...
**Agil:**
- Scrum
- Kanban
- Iterative Entwicklung
- Inkrementelle Entwicklung
- Evolutionäre Entwicklung
- Extreme Programmierung (XP)

# 11. Was unterscheidet klassische, agile und generische Vorgehensmodelle?

|                                  | Klassisch                                                                    | Agil                                                              |
| -------------------------------- | ---------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| **Dauer von Iteration / Zyklus** | Lang                                                                         | Kurz                                                              |
| **Planung**                      | Umfangreich                                                                  | Eher kürzer                                                       |
| **Historie**                     | Älter                                                                        | Jünger                                                            |
| **Umfeld, Markt, Anforderung**   | Stabil                                                                       | Wandelbar                                                         |
| **Ziel, Vorteile**               | Durch gute Struktur ein fest und klar vereinbartes Ergebnis sicher erreichen | Frühzeitige Darstellung und Erhalt von Ergebnissen und Prototypen |
# 12. ALM ist (grob gesagt) PLM (Product Lifecycle Management) für Software – was unterscheidet beide?
