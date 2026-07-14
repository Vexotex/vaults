# Projektbericht: Snake

  

## 1. Formales

| **Projektname**                          | Snake                                                                                                       |
| ---------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| **Kurs**                                 | Software-Lifecycle-Management (SLM), TH OWL                                                                 |
| **Lehrkraft**                            | Dr. rer. nat. Nils Beckmann                                                                                 |
| **Projektteam**                          | Michèle Heinemann, Lenja Lippok, Jeremy Braun                                                               |
| **Ersteller dieses Berichts**            | Jeremy Braun                                                                                                |
| **Datum**                                | 08.07.2026                                                                                                  |
| **Grundlage**                            | Lastenheft (24.05.2026), Pflichtenheft V2 (02.07.2026), Repository-Historie (Git), automatisierte Testläufe |
| **Release-Status zum Berichtszeitpunkt** | Release Candidate (RC)                                                                                      |
 

## 2. Kurzbeschreibung der Software

### 2.1 Aus Benutzersicht — Was ist Snake?

Snake ist ein interaktives, rein lokal laufendes Arcade-Spiel für Einzelspieler. Beim Start konfiguriert der Nutzer im Hauptmenü Spielfeldgröße (5–50 Felder je Dimension) und Taktgeschwindigkeit (50–500 ms) und startet damit eine Runde. Eine Schlange bewegt sich autonom und taktgesteuert über ein Raster, wird vom Spieler über die Pfeiltasten gelenkt und wächst durch das Einsammeln von Äpfeln. Kollidiert die Schlange mit einer Wand oder sich selbst, endet die Runde und ein Punktestand wird angezeigt; füllt sie das gesamte Spielfeld, gilt die Runde als gewonnen. Vergangene Runden werden lokal gespeichert (inkl. Highscore-Hervorhebung) und können als Replay erneut angesehen werden; zusätzlich stehen mehrere Farbthemen zur Auswahl.

## 3. Projektmetriken
### 3.1 Quelltextbezogene Metriken

| Metrik                                     | Wert                                                              |
| ------------------------------------------ | ----------------------------------------------------------------- |
| Quelltextzeilen insgesamt (Physical LOC)   | **1.206** (main.py: 6, snake.py: 813, test_snake.py: 387)         |
| Klassen                                    | 15 (7 in snake.py, 8 in test_snake.py)                            |
| Methoden                                   | 62 (32 in snake.py, 30 in test_snake.py)                          |
| Modulweite Funktionen                      | 1 (`main()`); zusätzlich 2 lokale Closures innerhalb von Methoden |
| Quotient LOC / insgesamt aufgewendete Zeit | 1.206 / 37,45 h ≈ **32,2 Zeilen/h**                               |
| Quotient LOC / Implementierungszeit        | 1.206 / 30 h ≈ **40,2 Zeilen/h**                                  |
| Dateien mit Quelltext                      | 3 (`main.py`, `snake.py`, `test_snake.py`)                        |
| Testfälle insgesamt                        | 26 (automatisiert, `unittest`)                                    |
| Testfälle Resultat „OK“                    | 26                                                                |
| Testfälle Resultat „Nicht OK“              | 0                                                                 |
| Speicherbedarf der Quelltextdateien        | 45.369 Bytes ≈ 44,3 KiB (156 + 30.316 + 14.897 Bytes)             |
![[pie-chart.png]]
  
### 3.2 Kostenschätzung
Kosten [€] = aufgewendete Zeit × 100 €/h = 37,45 h × 100 €/h = **3.745,00 €**

### 3.3 Preisschätzung

| Kundenanzahl | Preis je Kunde (Kosten / Kundenanzahl) |
| ------------ | -------------------------------------- |
| 1            | 3.745,00 €                             |
| 10           | 374,50 €                               |
| 100          | 37,45 €                                |
| 1.000        | 3,75 €                                 |
| 10.000       | 0,37 €                                 |

**Einschätzung:** Ein realistischer Einmalpreis für ein einfaches, unkompliziertes tkinter-Snake-Klon liegt im Bereich vergleichbarer Hobby-/Indie-Titel bei 0–3 €. Bei einem realistischen Preis von 2–3 € wären ca. 1.250–1.870 zahlende Kunden nötig, um die Kosten zu decken. Snake ist eines der am häufigsten nachgebauten Spiele überhaupt (u. a. seit Jahrzehnten kostenlos auf Mobiltelefonen vorinstalliert); ein Alleinstellungsmerkmal gegenüber kostenlosen Alternativen fehlt. Die Erreichung einer vierstelligen zahlenden Kundenzahl erscheint auf dem freien Markt für dieses Produkt **nicht realistisch** (der im Praktikum als „üblicher Fall“ beschriebene Ausgang).

## 4. Projekthistorie

| Version        | Datum              | Release-Art           | Inhalt                                                                                                                                                                                                                                                                                  |
| -------------- | ------------------ | --------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| v0.1           | 21.–22.05.2026     | Pre-Alpha             | Projekt-Setup, Grundlage für das Lastenheft                                                                                                                                                                                                                                             |
| v0.2           | 26.06.2026         | Pre-Alpha             | Vorlesungsunterlagen/Übungsblätter im Projekt hinterlegt                                                                                                                                                                                                                                |
| v0.3           | 02.07.2026, vorm.  | Alpha                 | Kerndatentypen und Spiellogik (FA-03–FA-07, NFA-02), Persistenz (FA-08/09), GUI-Rendering und Farbthemen (FA-02, FA-11), Hauptmenü mit Validierung (FA-01, FA-08), Taktschleife/Steuerung/Spielende, Replay (FA-10), Programmeinstiegspunkt (`main.py`); Pflichtenheft V2 verabschiedet |
| v0.4           | 02.07.2026, nachm. | Alpha → Beta          | Bugfixes: Richtungswechsel-Validierung (FA-03), Schlangen-Spawn fixiert, Rendering-/Rasterbug beim Zug in die alte Schwanzzelle behoben; automatisierte Unit-Test-Suite (26 Testfälle, Kapitel 9) ergänzt                                                                               |
| v0.5 (aktuell) | 08.07.2026         | **Release Candidate** | Schlangenkopf in eigener Farbe gerendert (FA-11, NFA-04, Kontrast); Score-Formel korrigiert — schnellere Schlange ergibt jetzt mehr statt weniger Punkte (FA-06)                                                                                                                        |

## 5. Reifegrad der Software

**Release-Art (aktuell): Release Candidate.** Nach der in der Vorlesung verwendeten Definition ist die Software damit *versionsstabil* (keine bekannten Fehler in den automatisierten Tests, im Alltagsbetrieb spielbar ohne Absturz), aber noch **nicht produktionsstabil**, es müsste ein Test durch externe Testgruppen durchgeführt werden.

**Einsetzbarkeit:** Für den privaten/lokalen Gebrauch ist die Software einsetzbar — alle elf funktionalen Anforderungen (FA-01 bis FA-11, Must-have und Should-have) sind laut Commit-Historie implementiert, und alle 26 automatisierten Unit-Tests laufen fehlerfrei durch. Für eine formale Abnahme im Sinne des Pflichtenhefts fehlt die Dokumentation der Systemtests.

**Fertigstellungsgrad je Entwicklungsphase** (Analyse / Entwurf / Implementierung / Qualitätssicherung):

  
| Phase              | Geschätzter Fertigstellungsgrad | Begründung                                                                                                                                                                                                                                                                                   |
| ------------------ | ------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Analyse            | 100 %                           | Lastenheft und Pflichtenheft (V1 und V2) vollständig ausgearbeitet, inkl. Anwendungsfällen und Testszenarien                                                                                                                                                                                 |
| Entwurf            | ≈ 85 %                          | Datenmodell und Architektur sind im Pflichtenheft (Kap. 6) und im Code konsistent umgesetzt; ein eigenständiges Entwurfsartefakt (z. B. Programmablaufplan/Architekturdiagramm als separates Dokument) liegt im Projektordner nicht vor                                                      |
| mplementierung     | ≈ 95 %                          | Alle FA/NFA im Code umgesetzt; eine dokumentierte Abweichung zur Spezifikation ist offen (siehe unten)                                                                                                                                                                                       |
| Qualitätssicherung | ≈ 55 %                          | Modultest-Ebene vollständig (26/26 automatisierte Tests grün); die 8 im Pflichtenheft definierten Systemtestfälle TC-01–TC-08 (manuelle Blackbox-/GUI-Tests) sind laut Dokument noch nicht durchgeführt (Feld „Tatsächliches Ergebnis“ ist in Pflichtenheft V2 durchgängig mit „—“ vermerkt) |
**Gesamt ≈ 84 % fertiggestellt.**  

## 6. Preisempfehlung

Empfohlener Preis: **0 € (kostenlose Veröffentlichung / Portfolioprojekt).** Ein kommerzieller Einmalpreis von 2–3 € wäre technisch möglich, aber angesichts der Marktsättigung mit kostenlosen Snake-Klonen und ohne Alleinstellungsmerkmal wirtschaftlich nicht kostendeckend zu erzielen (siehe Kapitel 3.3).

  

## 7. Empfehlung zur Nutzung

**Weiterentwickeln, dann veröffentlichen (kostenlos).** Nicht wegwerfen: Codequalität und Testabdeckung auf Modulebene sind gut, alle Muss- und Soll-Anforderungen sind umgesetzt. Vor einer Freigabe als „Stable“-Release sollten jedoch zunächst die in Kapitel 5 genannten offenen Punkte bearbeitet werden — insbesondere die Systemtests TC-01–TC-08 nachholen und die FA-06-Diskrepanz per Änderungsantrag auflösen. Danach eignet sich das Projekt gut zur kostenlosen Veröffentlichung (z. B. als Open-Source-Repository) als Portfolio- und Lernprojekt; eine kommerzielle Vermarktung wird nicht empfohlen.
