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
5. (AMR) Audits Metrics and Reports
6. (RM) Resource Management
7. (VM) Version Management
8. (BRM) Build and Realease Management

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
eine Menge von Tätigkeiten die zu einem Softwareprodukt führen
# Was ist ein Software?
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
Software einfacher skalierbar 
viel aufeinander abbildbar

# 13. Was verbirgt sich hinter den Begriffen Lastenheft, Pflichtenheft und Softwareanforderungsspezifikation?
**Lastenheft** ist ein (oft nicht-technisches) Dokument vom Kunden und seinen Vorstellungen an das Produkt.

**Pflichtenheft** ist ein technisches stark definierendes Dokument (meist aus einem Lastenheft abgebildet). Dient oft als rechtliche bindende Grundlage für Kaufverträge. 

Oft ist das ein hin und her zwischen Kunden und Dienstleister bis man sich auf ein Pflichtenheft einigt

# 14. Welche Arten von Anforderungen gibt es?
- Funktional
- Nicht-Funktional
- Benutzer anforderungen (eher Lastenheft)
- System anforderungen (eher Pfichtenheft)

# 15. Mit welchen Eigenschaften kann man Anforderungen ausstatten, wie kann man Anforderungen bewerten und wie kann man Anforderungen formulieren?
Eine gute Systemanforderungsspezifikation (SAS)
1. Korrekt
2. Eindeutig
3. Vollständig
4. Konsistent
5. Bewertet: Bedeutung, Stabilität, Risiko, Reihenfolge
6. Testbar
7. Modifizierbar
8. Nachvollziehbar
9. Verfolgbar
EARS

# 16. Was bedeutet es, wenn eine Anforderung nicht korrekt, eindeutig, vollständig, konsistent, bewertet, testbar, modifizierbar, nachvollziehbar oder verfolgbar ist?
dann ist sie nicht gut

# 17. Warum ist die Formulierung von guten Anforderungen wichtig?
- eingeschränkte Genauigkeit
- Missverständnisse vorbeugen
- rechtliche Absicherung
- Basierte Aufwandsabschätzung

# 18. Was meinen die Begriffe Priorität, Stabilität, Bedeutung, Risiko, Status in Bezug auf Anforderungen?
Priorität:
- Reihenfolge für die Abarbeitung
Stabilität:
- Wie sicher eine Anforderung umsetzbar ist
Bedeutung:
- Welche technische Auswirkung diese Anforderung auf die Software hat
- must-have, can-have, should-have
Risiko:
- Fehleranfälligkeit
Status: 
- Wann ist die Anforderung erfüllt und wie sie im laufe des Projekts zu bewerten ist

# 19. Wo kann man beispielsweise das Spiralmodell anwenden?
beim erstellen vom Pflichtenheft:
1. Der Kunde äußert seine vorstellung
2. Anforderungsdefinition
3. Erstellung eines Pflichtenhefts
4. Vorstellung beim Kunden
repeat

# 20. Was verbirgt sich hinter den folgenden Begriffen Portfolio, Release, Epic, Feature, User Story, Use Case, Backlog, Issue, Defect, EVA-Prinzip, Bug, Error, Aktor, Akteur, Ticket, C-Requirement, DRequirement, Metrik, Task, Failure, Story Points, Build-Server, Nightly Build, V&V, Workitem, und wodurch unterscheiden sich ähnliche Begriffsdefinitionen?

**Portfolio:** Ansammlung an Projekten die bereits durchgeführt worden sind
**Realease:** Ein gut getesteter Build, der Kunden angeboten wird
**Epic:** (Produktanforderung) was soll das System können
**Feature:** (Systemanforderung) Wie ist das Epic genau umzusetzen
**User Story:** Ablauf eines Arbeitsablaufs des Kunden
**Backlog:** ein Issue der noch nicht zugewiesen ist (Warteschlange)
**Issue:** definierte Aufgabe
**Defect:** (Mangel) eine Abweichung von einer Anforderung (fehlt)
**EVA-Prinzip:** Eingabe Verarbeitung Ausgabe, Datenverarbeitungsprinzip
**Bug:** semantischer Programmfehler (falsch umgesetzt)
**Error:** 
**Aktor:** Eine Aktive Systemkomponente (bsp. Server)
**Akteur:** Eine Aktive Person (bsp. Bediener)
**Ticket:** digitale Umsetzungsform einer Aufgabe
**C-Requirement:** Lastenheft
**D-Requirement:** Pfichtenheft
**Metrik:** Bewertungskriterium
**Task:** ein Issue
**Failure:** katastropphaler Defect (absturz)
**Story Points:** variable Zeiteinheit, zur Abschätzung vom Aufwand
**Build-Server:** Automatisierter Server, der aus dem Quellcode ausführbare Dateien, Installer, etc. erzeugt
**Nightly Build:** da ein Build viel Zeit in anspruch nehmen kann wird der Build-Server jede Nacht angeworfen, so dass man die neuste Version am Folgetag testen kann.
**V&V:** Validierung & Verifizierung (macht was der Kunde will & Code funktioniert)
**Workitem:** Issue Synonym

# 21. Was ist ein Burndown-Diagramm und was enthält es?
ein Diagramm über der Verlauf des Backlogs und wie dieser über die Zeit "niedergebrannt" wird

# 22. Welche Software-Tools kennen Sie, die die Aufgaben, Werkzeuge und Methoden des ALM unterstützen können?
- fick Redmine
- Github
- Kanban-board
- E-Mails

# 23. Welche typischen Rollen gibt es im Softwarentwicklungsprozess (die sich auch oft in Stellenausschreibungen wiederfinden)?
- Projektmanager
- Entwickler
- Softwarearchitekt
- Tester

# 24. Was ist der Unterschied zwischen Validierung und Verifizierung bei der Software-Entwicklung?
Validierung: Ist das umgesetzte auch wirklich das was der Kunde bestellt hat
Verifizierung: Funktioniert das auch wirklich

# 25. Was meint Traceability, worauf bezieht sie sich bei der SoftwareEntwicklung und warum ist sie dabei wichtig?
wie und wo Anforderungen umgesetzt worden sind.
rechtliche Absicherung

# 26. Welche UML-Diagramme gibt es und welche gehören zu den häufiger verwendeten?
Ablaufdiagramm
Klassendiagramme
Sequenzdiagramm
Anwendungsfalldiagramm

# 27. Welche Modelle/Diagramme gibt es, um die Entwurfs-Phase der Software-Entwicklung zu unterstützen und was verbirgt sich hinter diesen?
Spezifikation / Pflichtenheft 
UML

# 28. Was ist eine Metrik und welche typischen Metriken gibt es?
Ein Maßstab zum Bewerten.
- Zeilen Code
- Zeilen Code pro Stunde
- Anzahl Funktionen
- Aufgewendete Zeit
- Speicherbedarf

# 29. Was verbirgt sich hinter "Easy Approach to Requirements Syntax"?
EARS:
Vorgegebene Satzstruktur zur Definition von Anforderungen

# 30. Was verbirgt sich hinter einer Produktqualitätsmatrix (IEC/ISO 25010) und was kann man damit definieren?


# 31. Wie hängen die Begriffe Kopplung, Kohäsion, Schnittstellen, CodeDuplizierung mit den Kriterien für einen guten Entwurf zusammen?
**Kopplung:** Schnittstellen anstatt öffentlicher Variablen (Verbindung der Funktionen)
**Kohäsion:** Jedes Modul hat eine eindeutige Aufgabe (eine Funktion hat nur eine Aufgabe)
**Schnittstellen:** Eine Möglichkeit Module lose zu Koppeln, Erhöht die Wiederverwendbarkeit und Modifizierbarkeit der Module
**CodeDuplizierung:** Codeblöcke, die das gleiche machen - sollten vermieden werden

Modifizierbarkeit und Wiederverwendbarkeit

# 32. Was sind Schwierigkeiten bei der Zeitschätzung von Aufgaben?
- Extremfälle können stark auseinanderliegen
- mangelnde Erfahrung mit konkretem Problem
- Konkurrenzfähigkeit erzwingen und Zeit zu niedrig einschätzen

# 33. Welche Methoden helfen, zu einer guten Zeitschätzung zu kommen?
- Drei-Punkt-Schätzung
- Worst-Case-Schätzung

# 34. Wem und wofür hilft eine Zeitschätzung weiter?
- dem Projektleiter zum Planen von Issues
- für die Kostenaufstellung zum Kunden
- Resource Management zum planen der Auslastung ihrer resourcen

# 35. Welche Auswirkungen kann eine schlechte Zeitschätzung haben?
zu schnell fertig -> leerlauf
zu langsam -> Deadlineüberschreitung (Vertragsbruch)

# 36. Welche Werkzeuge und Methoden gibt es, um die Qualität der zu erstellenden Software und der zugehörigen Software-Entwicklung zu sichern?
- TDD
- Metriken
- Tests
- Rollen

# 37. Welche Industrienormen gibt es beispielsweise im Kontext von ALM?
keine ist alles nur heiße Luft

# 38. Was unterscheidet Backlog, Product Backlog und Sprint Backlog?
**Backlog:** generell

Scrum spezifisch
**Product Backlog:** Alles Issues
**Sprint Backlog:** Issues die in diesem Sprint erledigt wrden sollen

# 39. Welche Werkzeuge/Methoden nutzen diese ManagementDisziplinen (REQ, TQM, IDM, CCM, BRM, RM, AMR, VM)?
siehe 1.

# 40. Was sind Beispiele für materielle und immaterielle Ressourcen?
materiell:
- Server
- Geld
- Hardware
- Kaffeepulver
imateriell
- Arbeitszeit
- Software

# 41. Welche Phasen gibt es in Scrum und wer tut dabei was?
- Sprint-Planning (was im nächsten Sprint erledigt werden soll)
	- Product Owner & Entwickler
- Daily Scrum (Statusabfrage)
	- Scrum Master & Entwickler
- Sprint Review (IST-Version vom Planning)
	- PO & E
- Sprint Retrospektive (Wie war der letzte Sprint, was ändern wir)
	- PO & SM
- Product Backlog Refinement (Backlog-update, Zeiteinschätzung, ...)
	- PO & ET

# 42. Welche Phasen gibt es im V-Modell und was wird dabei getan?
- Analyse
- Grobentwurf
- Feinentwurf
- Implementierung
Nebenbei werden die jeweiligen Tests definiert

# 43. Welche Eigenschaften/Attribute kann man den folgenden Dingen zuordnen (Backlog, Ticket, Defect, Testfall)?
- Backlog
	- geplant
	- definiert
	- Zeitplanung
- Ticket
	- digitale Umsetzung 
- Defect
	- Dokumentation eines Problems
	- Anforderung, die nicht erfüllt worden ist
- Testfall
	- zugeordnete Anforderung
	- erwartetes Ergebnis
	- durchführungsplan

# 44. Was ist der Unterschied zwischen Blackbox- und Whitebox-Testen?
Blackbox - Testfälle aus Spezifikation
Whitebox - Testfälle aus Programmstruktur

# 45. Was ist der Unterschied zwischen statischer und dynamischer V&V?
**statisch:** Software wird nicht ausgeführt
**dynamisch:** Software wird ausgeführt

# 46. Wodurch unterscheiden sich V-Modell und Wasserfallmodell?
Testfälle werden währen den einzelnen Phasen definiert

# 47. Kann man V-Modell und Scrum und Kanban direkt vergleichen und warum oder warum nicht und welche Unterschiede und Gemeinsamkeiten gibt es?
nein, kann man nicht
Kanban ist nicht an Prozessphasen gebunden (ist eine Philosophie)
und Scrum ist Agil 
V-Modell ist Klassisch

# 48. Welche Aufgaben werden in einem "Request for Change" bearbeitet?
Dokumentation:
- was soll geändert werden 
- warum

# 49. Was unterscheidet den "Request for Change" und den "Change Record"?
RfC: Anfrage, was und warum es geändert werden soll
CR: Was wurde wie implementiert

# 50. Welche Arten von Dokumenten gibt es im Change Management?
- Change Record
- Request for Change

# 51. Was unterscheidet das Configuration Management und Variant Management?
VM: (Was?) Übersicht, darüber welche Konfigurationen es gibt
CCM: (Wie?) Änderungen einzelne Konfigurationen beeinflussen

# 52. Welche Beispiele für Metriken gibt es – allgemein, im industriellen Kontext und im Software-Kontext?

Allgemein: 
- Schulugsdauer
- Support-Anfragen pro Tag
Software-Kontext:
- Quelltextzeilen
- Zeilen duplizierter Code
- Kommentarzeilen/Quelltextzeilen

# 53. Wobei können Metriken helfen?
Eigenschaften von Software in einen Zahlenwert Abbilden
schaffen von formalen Vergleichs- und Bewertungsmöglichkeiten

# 54. Wie hängen Metrik und Messung zusammen und wie können sie sich beeinflussen?
"Wenn eine Metrik zum Ziel wird, ist sie keine gute Metrik mehr" - Goodhart
Wenn die Metrik selbst bsp. Zeilen code mit viel - gut bewertet wird. Fangen Entwickler an nutzlose Zeilen einzubauen um in dieser Metrik besonders gut abschneiden zu können.

# 55. Was verbindet Reports und Audits mit Metriken?
Report = Bericht, Bestandserfassung des aktuellen IST-Zustands
Audit = Untersuchung, Vergleich IST-Zustand mit SOLL-Zustand

# 56. Welche grundlegenden Daten sind in einem Netzplan enthalten?
- Aktivität
- Vorbedingung
- Zeitschätzung
- Zeiterwartung

# 57. Was zeigt ein Gantt-Diagramm (auch Balkenplan genannt) und wer (welche Rolle) nutzt es?
Ein Gantt-Diagramm zeigt wann welche Aufgaben über welchen Zeitraum erledigt werden.
Meist werden die zu erledigenden Aufgaben untereinander chronologisch eingeordnet und dann werden Balken bei den einzelnen Aufgaben gezogen, die diesen jeweiligen inkementalen Zeitverbrauch visualisieren sollen

# 58. Wobei hilft ein Balkenplan?
Zeitübersicht über die Ganze Projektdauer und der inkrementalen Anteil einer jeden Komonente

# 59. Welche Informationen enthält ein Testfall und ein Testergebnis?
**Testfall:** Testschritte (Tue das so), Erwartetes Ergebnis, 
**Testergebnis:** das ist passiert, ok / nicht ok

# 60. Aus welchen Schritten besteht der fundamentale Testprozess?
Definition:
- Testschritte (tue A,B,C,...)
- Erwartetes Ergebnis
Auswertung:
- Tatsächliches Ergebnis
- Resultat (OK?)

# 61. Was ist der Unterschied zwischen einem logischen und einem konkreten Testfall?
**logisch:** was genau erreich werden soll
**konkrete:** wie es tatsächlich aussieht

# 62. Was ist eine Methode im Gegensatz zum Werkzeug (im ALM)?
Methode ist eine Vorgehensweise.
Werkzeuge sind die Umsetzung der Methode.

# 63. Welche Dinge sollte in einem Releasewechselplan berücksichtigt werden?
- Zeitfenster
- Backup-Plan
- Checkliste
- Kommunikationsmatrix (Kontaktdaten aller Beteiligten)
- Infarstruktur-Check
- Automatisierungsskript

# 64. Was ist der Unterschied zwischen Build, Release und Version?
Version: Ein bestimmter Stand des Quellcodes
Build: kompilierter Quellcode
Realease: ein stabiler Build, der Kunden angeboten wird

# 65. Welche Arten von Software-Produktvarianten (Arten und Typen) gibt es?

# 66. Welche Vorteile gibt es, wenn man Varianten für ein SoftwareProdukt definiert?
verschiedene Software für mehrere Kunden ohne Software von neu auf entwickeln zu müssen. 
kostengünstig viele Kunden bedienen können

# 67. Was ist der Unterschied zwischen Build und Release?
Build ist ein Ergebnis von Quelltextkompilierung und muss nicht Funktionieren
ein Release ist ein stabiler Build

# 68. Welche Build-Typen gibt es?
- Overall: Build über alle Teile und Module eines Softwareprodukts
- Part: Build über Teile des Softwareprodukts oder Modulbereich
- Daily: täglicher Build-Prozess (i.d.R als Nightly)

# 69. Welche Release-Arten gibt es?
1. Alpha
2. Beta
3. Release Candidate (RC)
4. Stable

# 70. Was sind Inhalte von Testplan und Testbericht?
Testplan:
1. Testplanung und -steuerung
2. Testanalyse und -entwurf
Testbericht:
3. Testrealisierung und -durchführung
4. Testauswertung und -bericht

# 71. Welche Kategorien von Ressourcen können als als Zielkriterien für eine Optimierung eines Prozesses berücksichtigt werden?
ein Prozess kann auf jede Ressource optimiert werden.
z.B. immateriell: kann ein Prozess auf Zeiteffizienz optimiert werden.
oder materiell auf maximale Rechenauslastung.

# 72. Wie können die verschiedenen Arten von Ressourcen in einem Projekt verplant werden?
soll ich jetzt die Vorgehensmodelle auflisten

# 73. Was bedeutet "Rüsten" im industriellen Kontext?
Rüsten im industriellen Kontext ist das Vorbereiten oder Anpassen einer Maschine oder Fertigungslinie auf einen neuen Prozess

# 74. Welche Dinge können mittels ALM definiert werden, wenn man ein Team für die Software-Entwicklung anleitet?
- Rollen
- Aufgaben
- Abläufe

# 75. Welche realen Schwierigkeiten können in realen Projekten zur Software-Entwicklung auftauchen?
- Zeitverzug
- Resourcenausfall
- Missverständisse / Kommunikationsschwierigkeiten
- Kunden  Wissen nicht was sie wollen 

# 76. Was ist bei der Größe von Teams zu beachten?
- mit wachsender Teamgröße wächst der Kommunikationsaufwand nahezu quadratisch.
- bei zu kleinen Teams ist kaum aufgabenteilung möglich
- optimalerweise ist eine Teamgröße 3-7 Personen

# 77. Welche Unterschiede (was ist anders, was wurde entwickelt, was hat sich verändert, welche Ergebnisse liegen vor) gibt es zwischen vor Beginn und nach Ende eines Software-Projekts?
- nach dem Projekt ist vor dem Projekt
- Erfahrungszuwachs aller beteiligt
- endlose Dokumente
- maybe Produkt
- evtl. neuverteilung der Rollen bei neuem Projekt
- Kündigungswelle
