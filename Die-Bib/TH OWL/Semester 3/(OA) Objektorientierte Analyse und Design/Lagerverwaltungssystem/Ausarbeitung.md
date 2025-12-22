# Problemstellung

Ein Großhändler mit mehreren Lagerstandorten benötigt ein verteiltes Lagerverwaltungssystem, dass zu lokaler, autarker Bestandsverwaltung auch eine zusammengefasste Übersicht über alle Standorte bietet.

Die Mitarbeiter sollen in der Lage sein lokal vorhandene Artikel einzulagern, auszulagern und anzeigen zu können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden. Jeder dieser Zugriffe soll protokolliert werden.
Das System soll Auswertungen erstellen können: Wie viele Verkäufe, etc.. Darauf hin soll das System standortübergreifend entscheiden, ob ein Artikel mehr, weniger oder gar nicht vorgehalten werden soll und die Zuständige Abteilung per E-Mail informieren oder automatisch Bestellungen tätigen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.


# Pflichtenheft / Problemanalyse

## Akteure

1. LV - **Lagerverwalter** – Verwaltet lokalen Lagerbestand, Ein-/Auslagerungen
2. EK - **Einkäufer** – Erhält Bestellvorschläge, bestellt bei Lieferanten
3. VK - **Verkäufer** – Fragt Artikel an, löst Auslagerungen aus
4. L - **Lieferant** 

## Anwendungsfälle

### Artikel einlagern

|      | Anwendungsfall            | Artikel einlagern                                                                                                                       |
| ---- | ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Lagerartikel im System erfassen. Dabei bekommt er einen Lagerplatz vom System, wenn er selber keinen definiert. |
|      | Beteiligte Akteure        | Lagerverwalter                                                                                                                          |
|      | Vorbedingung              | Artikel ist am Standort eingetroffen                                                                                                    |
|      | Nachbedingung             | Artikel im System erfasst, Position zugewiesen, Lagerbestand aktualisiert                                                               |
|      | Auslöser                  | Artikel müssen eingelagert werden. <br>- Anlieferung neuer Ware <br>- Auftragsstornierung und wieder-Einlagerung                        |
|      | **Standardszenario**      |                                                                                                                                         |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                   |
| 2    | S                         | System zeigt Artikelinformationen an                                                                                                    |
| 3    | LV                        | Lagerverwalter wählt Lagerposition                                                                                                      |
| 4    | S                         | System speichert Artikel mit Position, Verfallsdatum (falls vorhanden)                                                                  |
| 5    | S                         | System sendet Bestandsaktualisierung an Zentralsystem                                                                                   |
| 6    | S                         | Zentralsystem aktualisiert Gesamtbestand                                                                                                |
|      | **Alternative Szenarien** |                                                                                                                                         |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                       |
| zu 3 | LV                        | Lagerverwalter bestätigt die vom System vorgeschlagene Lagerposition                                                                    |
|      | **Erweiterungen**         |                                                                                                                                         |
| zu 3 | LV                        | Lagerverwalter trägt Verfallsdatum ein                                                                                                  |
|      | **Fehlersituationen**     |                                                                                                                                         |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgebrochen                                                             |

### Artikel anzeigen

|      | Anwendungsfall            | Artikel anzeigen                                                                                                                                                                                         |     |
| ---- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --- |
|      | Kurzbeschreibung          | Jeder Akteur kann sich Details zu den Artikeln anzeigen lassen                                                                                                                                           |     |
|      | Beteiligte Akteure        | Lagerverwalter / Einkäufer / Verkäufer                                                                                                                                                                   |     |
|      | Vorbedingung              | Artikelnummer oder Artikelname bekannt                                                                                                                                                                   |     |
|      | Nachbedingung             | Eindeutige Artikelinformationen, sowie zugehörige Statistiken werden Angezeigt                                                                                                                           |     |
|      | Auslöser                  | Anfrage durch einen Akteur (LV, EK, VK)                                                                                                                                                                  |     |
|      | **Standardszenario**      |                                                                                                                                                                                                          |     |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                    |     |
| 2    | S                         | System zeigt Artikelinformationen und Statistiken an                                                                                                                                                     |     |
|      | **Alternative Szenarien** |                                                                                                                                                                                                          |     |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                        |     |
| zu 1 | EK                        | Einkäufer gibt Artikelnummer ein                                                                                                                                                                         |     |
| zu 1 | VK                        | Verkäufer gibt Artikelnummer ein                                                                                                                                                                         |     |
| zu 2 | S                         | Verbindung zu anderen Systemen schlägt fehl; globale Statistiken werden nicht angezeigt und Akteur über Situation Informiert                                                                             |     |
|      | **Erweiterung**           |                                                                                                                                                                                                          |     |
| zu 1 | LV / EK / VK              | Es wird der Artikelname eingegeben; <br>Es wird eine Liste mit den wahrscheinlichsten Treffern und deren Artikelnummern angezeigt; <br>Durch Auswahl eines Eintrags wird diese Artikelnummer eingegeben. |     |
|      | **Fehlersituationen**     |                                                                                                                                                                                                          |     |
| zu 1 | LV                        | Artikelnummer existiert nicht; kurzer Hinweistext wird angezeigt; Vorgang wird abgebrochen                                                                                                               |     |

### Artikel auslagern

|     | Anwendungsfall            | Artikel auslagern                                                                                                                                                                                        |
| --- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|     | Kurzbeschreibung          | Der Lagerverwalter kann Artikel auslagern. Dabei kann er Entscheiden, welche Position im Lager ausgelagert wird.                                                                                         |
|     | Beteiligte Akteure        | Lagerverwalter,                                                                                                                                                                                          |
|     | Vorbedingung              | Artikel im System erfasst, Bestand größer 0                                                                                                                                                              |
|     | Nachbedingung             | Lagerbestand Aktualisiert, Positionsgröße aktualisiert                                                                                                                                                   |
|     | Auslöser                  | Artikel muss ausgelagert werden.<br>- Verkauf getätigt und Ware muss für den Versand aus dem Lager.<br>- Ware ist abgelaufen und muss entsorgt.<br>- Ware muss zur Weiterverarbeitung in die Produktion. |
|     | **Standardszenario**      |                                                                                                                                                                                                          |
| 1   | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                    |
| 2   | S                         | System zeigt alle Im lokalen Standort vorhandenen Lagerpositionen und deren Verfallsdaten an                                                                                                             |
| 3   | LV                        | Lagerverwalter wählt Position aus und gibt entnommene Stückzahl an                                                                                                                                       |
| 4   | S                         | System aktualisiert Die Lagerposition                                                                                                                                                                    |
| 5   | S                         | System sendet Bestandsaktualisierung an Zentralsystem                                                                                                                                                    |
| 6   | S                         | Zentralsystem aktualisiert Gesamtbestand                                                                                                                                                                 |
|     | **Alternative Szenarien** |                                                                                                                                                                                                          |
|     |                           |                                                                                                                                                                                                          |




# Eidsstaatliche Erklärung