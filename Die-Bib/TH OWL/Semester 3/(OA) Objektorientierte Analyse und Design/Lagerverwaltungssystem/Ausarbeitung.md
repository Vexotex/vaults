## Problemstellung

Ein Großhändler mit mehreren Lagerstandorten benötigt ein verteiltes Lagerverwaltungssystem, dass zu lokaler, autarker Bestandsverwaltung auch eine zusammengefasste Übersicht über alle Standorte bietet.

Die Mitarbeiter sollen in der Lage sein lokal vorhandene Artikel einzulagern, auszulagern und anzeigen zu können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden. Jeder dieser Zugriffe soll protokolliert werden.
Das System soll Auswertungen erstellen können: Wie viele Verkäufe, etc.. Darauf hin soll das System standortübergreifend entscheiden, ob ein Artikel mehr, weniger oder gar nicht vorgehalten werden soll und die Zuständige Abteilung per E-Mail informieren oder automatisch Bestellungen tätigen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.


## Pflichtenheft / Problemanalyse

### Akteure

1. LV - **Lagerverwalter** – Verwaltet lokalen Lagerbestand, Ein-/Auslagerungen
2. ZV - **Zentralverwalter** – Hat Übersicht über alle Standorte, steuert Artikelverteilung
3. EK - **Einkaufsabteilung** – Erhält Bestellvorschläge, bestellt bei Lieferanten
4. S   - **System** – Automatische Nachbestellung, Artikel-Umverteilung
5. VK - **Verkäufer** – Fragt Artikel an, löst Auslagerungen aus

### Anwendungsfälle

|      | Anwendungsfall            | Artikel einlagern                                                                                                                       |
| ---- | ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Lagerartikel im System erfassen. Dabei bekommt er einen Lagerplatz vom System, wenn er selber keinen definiert. |
|      | Beteiligte Akteure        | Lagerverwalter, System                                                                                                                  |
|      | Vorbedingung              | Artikel ist am Standort eingetroffen                                                                                                    |
|      | Nachbedingung             | Artikel im System erfasst, Position zugewiesen                                                                                          |
|      | Auslöser                  | Artikel werden angeliefert und müssen eingelagert werden.                                                                               |
|      | **Standardszenario**      |                                                                                                                                         |
| 1    | LV                        | Lagerverwalter scannt Artikel-Barcode                                                                                                   |
| 2    | S                         | System zeigt Artikelinformationen an                                                                                                    |
| 3    | LV                        | Lagerverwalter wählt Lagerposition                                                                                                      |
| 4    | S                         | System speichert Artikel mit Position, Verfallsdatum (falls vorhanden)                                                                  |
| 5    | S                         | System sendet Bestandsaktualisierung an Zentralsystem                                                                                   |
| 6    | S                         | Zentralsystem aktualisiert Gesamtbestand                                                                                                |
|      | **Alternative Scenarien** |                                                                                                                                         |
| zu 1 | LV                        | Lagerverwalter trägt Artikelnummer von hand ein                                                                                         |
| zu 3 | LV                        | Lagerverwalter bestätigt die vom System vorgeschlagene Lagerposition                                                                    |
|      | **Erweiterungen**         |                                                                                                                                         |
| zu 3 | LV                        | Lagerverwalter trägt Verfallsdatum ein                                                                                                  |
|      | **Fehlersituationen**     |                                                                                                                                         |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgerochen                                                              |
| zu 3 | LV                        | Lagerverwalter wählt belegten Lagerplatz                                                                                                |
