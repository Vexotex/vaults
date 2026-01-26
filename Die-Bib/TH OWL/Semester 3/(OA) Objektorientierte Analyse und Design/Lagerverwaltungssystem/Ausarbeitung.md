# Problemstellung

Wir designen die Lagerverwaltung eines Großhändlers. Der Großhändler besitzt mehrere Lager. Wir wollen sowohl eine zentrale Bestandsaufnahme als auch eine Bestandsaufnahme an jedem Standort, so dass die Systeme autark funktionieren können.

Zentral soll nur gespeichert werden, wie viele Gegenstände von welcher Art an welchem Standort vorhanden sind.

In jedem Standort soll außerdem die Position des Gegenstandes im Lager angezeigt werden. Es kann davon ausgegangen werden, dass jedes Lager die gleiche Struktur hat.

Das System soll die Möglichkeit haben, anfragen bearbeiten zu können, es sollen also Gegenstände eingelagert, ausgelagert und angezeigt werden können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden.

Weiterhin soll jeder Zugriff und jede Entnahme von Gegenständen gespeichert werden. Weiterhin soll es die Möglichkeit geben, automatisch Auswertungen einzelner Artikel zu erstellen: Wie viele Verkäufe, etc. Das System soll dann in der Lage sein, Artikel, die nicht häufig angefragt werden, nicht mehr an allen Standorten vorzuhalten oder zu entscheiden, dass ein Artikel an mehreren Standorten vorgehalten werden soll. Hierzu soll es die passende Abteilung per Email informieren oder automatisch für andere Standorte zu bestellen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.


# Pflichtenheft / Problemanalyse

Da die aktuelle Problemstellung noch viel Raum für Interpretation lässt, muss nun genau definiert werden welche Features und in welcher Form implementiert werden sollen. 
Hierzu wird nach dem Schema der Vorlesung "Objektorientierte Analyse" das Problem genauer beschrieben:
- Als erstes werden die Handlungsträger/Akteure identifiziert. 
- Dann wird erkannt wie diese Zusammen interagieren. 
- Daraus werden Szenarien gebildet und möglichst präzise, mit Alternativen und Fehlersituationen, beschrieben  


## Akteure

1. LV - **Lagerverwalter** – Verwaltet lokalen Lagerbestand, Ein-/Auslagerungen
2. EK - **Einkäufer** – Erhält Bestellvorschläge, bestellt bei Lieferanten
3. VK - **Verkäufer** – Fragt Artikel an, löst Auslagerungen aus
4. L - **Lieferant**
5. Z - **Zentralsystem**
6. JS - **Job-Scheduler**


## Darstellung der Akteure und Anwendungsfälle

[[Darstellung_der_Akteure_und_Anwendungsfälle.excalidraw]]

## Anwendungsfälle / Szenarien
### Artikel anzeigen

|      | Anwendungsfall            | Artikel anzeigen                                                                                                                                                                                         |
| ---- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Jeder Akteur kann sich Details zu den Artikeln anzeigen lassen                                                                                                                                           |
|      | Beteiligte Akteure        | Lagerverwalter / Einkäufer / Verkäufer, System                                                                                                                                                           |
|      | Vorbedingung              | Artikelnummer oder Artikelname bekannt                                                                                                                                                                   |
|      | Nachbedingung             | Allgemeine Artikelinformationen, sowie die letzten Änderungsprotokolle werden angezeigt                                                                                                                  |
|      | Auslöser                  | Anfrage durch einen Akteur (LV, EK, VK)                                                                                                                                                                  |
|      | **Standardszenario**      |                                                                                                                                                                                                          |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                    |
| 2    | LV                        | dem Lagerverwalter werden allgemeine Artikelinformationen, lokale Bestände und deren Lagerpositionen und Änderungsprotokolle angezeigt                                                                   |
|      | **Alternative Szenarien** |                                                                                                                                                                                                          |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                        |
| zu 1 | EK                        | Einkäufer gibt Artikelnummer ein                                                                                                                                                                         |
| zu 1 | VK                        | Verkäufer gibt Artikelnummer ein                                                                                                                                                                         |
|      | **Erweiterung**           |                                                                                                                                                                                                          |
| zu 1 | LV / EK / VK              | Es wird der Artikelname eingegeben; <br>Es wird eine Liste mit den wahrscheinlichsten Treffern und deren Artikelnummern angezeigt; <br>Durch Auswahl eines Eintrags wird diese Artikelnummer eingegeben. |
|      | **Fehlersituationen**     |                                                                                                                                                                                                          |
| zu 1 | LV                        | Artikelnummer existiert nicht; Vorgang wird abgebrochen                                                                                                                                                  |


### Artikel einlagern

|      | Anwendungsfall            | Artikel einlagern                                                                                                                                   |
| ---- | ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Lagerartikel im System erfassen. Dabei bekommt er einen Lagerplatz vom System vorgeschlagen, kann aber einen definieren     |
|      | Beteiligte Akteure        | Lagerverwalter, Zentralsystem                                                                                                                       |
|      | Vorbedingung              | Artikel ist am Standort eingetroffen, Artikelnummer ist bekannt                                                                                     |
|      | Nachbedingung             | Artikel im System erfasst, Lagerposition zugewiesen, Lagerbestand aktualisiert, Änderung protokolliert, Zentrallagerbestand aktualisiert            |
|      | Auslöser                  | Artikel müssen eingelagert werden. <br>- Anlieferung neuer Ware <br>- Auftragsstornierung und wieder-Einlagerung<br>- etc.                          |
|      | **Standardszenario**      |                                                                                                                                                     |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                               |
| 2    | LV                        | Dem Lagerverwalter werden Allgemeine Artikelinformationen angezeigt                                                                                 |
| 3    | LV                        | Lagerverwalter trägt Lagerposition und Menge ein                                                                                                    |
| 4    | Z                         | Informierung des Zentralsystem über Bestandsaktualisierung, mit Artikelnummer und hinzugefügter Stückzahl                                           |
| 5    | Z                         | Zentralsystem aktualisiert Gesamtbestand und erstellt eigens Protokoll zu: Mengenänderung und Standort der Änderung                                 |
|      | **Alternative Szenarien** |                                                                                                                                                     |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                   |
| zu 3 | LV                        | Lagerverwalter bestätigt die vom System vorgeschlagene Lagerposition                                                                                |
|      | **Erweiterungen**         |                                                                                                                                                     |
| zu 3 | LV                        | Lagerverwalter trägt zusätzliche ein Verfallsdatum ein; <br>System speichert Artikel mit Position, Stückzahl und Verfallsdatum                      |
| zu 4 | Z                         | Es existieren noch markierte Änderungen, die noch gesendet werden müssen;<br>Zentralsystem wird über alle unsynchronisierten Änderungen informiert; |
|      | **Fehlersituationen**     |                                                                                                                                                     |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgebrochen                                                                         |
| zu 4 | Z                         | Zentralsystem nicht erreichbar;<br>Änderungen bleiben lokal gespeichert und für spätere Synchronisierung markiert                                   |


### Artikel auslagern

|      | Anwendungsfall            | Artikel auslagern                                                                                                                                                                                                  |
| ---- | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Artikel auslagern. Dabei kann er entscheiden, welche Position im Lager ausgelagert wird.<br>Es werden die Bestände der anderen Standorten angezeigt.                                       |
|      | Beteiligte Akteure        | Lagerverwalter, Zentralsystem                                                                                                                                                                                      |
|      | Vorbedingung              | Artikelnummer bekannt, Artikelbestand > 0                                                                                                                                                                          |
|      | Nachbedingung             | Bestand an Lagerposition aktualisiert, Änderung protokolliert, Zentrallagerbestand aktualisiert                                                                                                                    |
|      | Auslöser                  | Artikel muss ausgelagert werden.<br>- Verkauf getätigt und Ware muss für den Versand aus dem Lager.<br>- Ware ist abgelaufen und muss entsorgt.<br>- Ware muss zur Weiterverarbeitung in die Produktion.<br>- etc. |
|      | **Standardszenario**      |                                                                                                                                                                                                                    |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                              |
| 2    | LV                        | Dem Lagerverwalter werden alle Im lokalen Standort vorhandenen Lagerpositionen und deren Verfallsdaten angezeigt. Separat werden die Bestände in anderen Standorten angezeigt.                                     |
| 3    | LV                        | Lagerverwalter wählt Position aus und gibt auszulagernde Menge an                                                                                                                                                  |
| 4    | Z                         | System sendet Bestandsaktualisierung, mit Artikelnummer und entnommener Stückzahl an Zentralsystem                                                                                                                 |
| 7    | Z                         | Zentralsystem aktualisiert Gesamtbestand und erstellt eigens Protokoll zu: Mengenänderung und Standort der Änderung                                                                                                |
|      | **Alternative Szenarien** |                                                                                                                                                                                                                    |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                                  |
|      | **Erweiterungen**         |                                                                                                                                                                                                                    |
| zu 4 | Z                         | Es existieren noch markierte Änderungen, die noch gesendet werden müssen;<br>Zentralsystem wird über alle unsynchronisierten Änderungen informiert;                                                                |
|      | **Fehlersituationen**     |                                                                                                                                                                                                                    |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgebrochen                                                                                                                                        |
| zu 3 | LV                        | auszulagernde Menge größer als Position; Anwendungsfall wird abgebrochen                                                                                                                                           |
| zu 4 | Z                         | Zentralsystem nicht erreichbar;<br>Änderungen bleiben lokal gespeichert und für spätere Synchronisierung markiert                                                                                                  |

### Artikel auswerten

|      | Anwendungsfall            | Artikel auswerten                                                                                                                                                                                                                                                          |
| ---- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Jeder Akteur kann Auswertungen zu einem Artikel erstellen lassen, um Informationen über globale Bestände zu erhalten                                                                                                                                                       |
|      | Beteiligte Akteure        | Lagerverwalter / Einkäufer / Verkäufer / Job-Scheduler, Zentralsystem                                                                                                                                                                                                      |
|      | Vorbedingung              | Artikelnummer bekannt                                                                                                                                                                                                                                                      |
|      | Nachbedingung             | globale Menge und die Verteilung dieser über die Standorte werden angezeigt.<br>Statistiken zu globalen und lokalen Verkaufszahlen werden angezeigt                                                                                                                        |
|      | Auslöser                  | - Einkauf will indizieren, ob eine Bestellung ausgelöst werden sollte oder ob es sich überhaupt lohnt diesen Artikel weiter zu führen.<br>- Lagerverwalter will entscheiden, ob er gewisse Artikel sehr erreichbar oder eher schwer erreichbar einlagern sollte.<br>- etc. |
|      | **Standardszenario**      |                                                                                                                                                                                                                                                                            |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                                                                                      |
| 2    | Z                         | Beim Zentralsystem werden globale Bestände und globale Statistiken angefordert                                                                                                                                                                                             |
| 3    | Z                         | Zentralsystem berechnet globale Statistiken zu Standortbezogenen Aus- und Einlagerungen, sowie aktuellen Beständen und gibt diese zurück                                                                                                                                   |
| 4    | LV                        | dem Lagerverwalter werden lokale / globale Bestände und ihre Verteilung über die Standorte und die Statistiken zu Standortbezogenen Aus- und Einlagerungen an.                                                                                                             |
|      | **Alternative Szenarien** |                                                                                                                                                                                                                                                                            |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                                                                                          |
| zu 1 | EK                        | Einkäufer gibt Artikelnummer ein                                                                                                                                                                                                                                           |
| zu 1 | VK                        | Verkäufer gibt Artikelnummer ein                                                                                                                                                                                                                                           |
| zu 1 | JS                        | Job-Scheduler löst Routineauswertung aus                                                                                                                                                                                                                                   |
| zu 3 | Z                         | Zentralsystem merkt, dass seit der letzten Statistikberechnung keine Änderung vorgenommen worden ist und gibt die letzte Berechnung zurück                                                                                                                                 |
|      | **Erweiterungen**         |                                                                                                                                                                                                                                                                            |
| zu 4 | Z                         | Zentralsystem erkennt, dass Standortbezogener Lagerbestand unter Mindestbestand liegt; <br>System informiert zuständigen Einkauf per E-Mail                                                                                                                                |
| zu 4 | Z                         | Zentralsystem erkennt, dass Standortbezogener Lagerbestand unter Mindestbestand liegt und der Artikel für automatischen Einkauf markiert ist; <br>System löst statistisch empfohlene Bestellung aus und informiert zuständigen Einkauf per E-Mail                          |
|      | **Fehlersituationen**     |                                                                                                                                                                                                                                                                            |
| zu 1 | LV                        | Artikelnummer existiert nicht; Vorgang wird abgebrochen                                                                                                                                                                                                                    |
| zu 3 | Z                         | Zentralsystem merkt, dass eine Verbindung zu einem Standort nicht herrscht und gibt Warnmeldung zu dieser Standortbezogenen Statistik zurück                                                                                                                               |
| zu 4 | LV                        | Zentralsystem antwortet nicht / Es herrscht keine Verbindung;<br>dem Lagerverwalter werden nur lokale Statistiken angezeigt                                                                                                                                                |

### Artikel bestellen
#### *Aus Platzgründen wurde dieser Anwendungsfall ausgelassen*

|      | Anwendungsfall        | Artikel bestellen                                                                                                                                                                                        |
| ---- | --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung      | Durch den Einkauf oder automatisch über das System können Bestellungen bei dem zugehörigen Lieferanten ausgelöst werden.                                                                                 |
|      | Beteiligte Akteure    | Einkauf, Lieferant                                                                                                                                                                                       |
|      | Vorbedingung          | Artikel muss bestellbar sein                                                                                                                                                                             |
|      | Nachbedingung         | Bestellung wurde an den Lieferanten übermittelt                                                                                                                                                          |
|      | Auslöser              | Ein Einkäufer oder das Zentralsystem entschiedet den Artikel zu bestellen.                                                                                                                               |
|      | **Standardszenario**  |                                                                                                                                                                                                          |
| 1    | EK                    | Einkäufer gibt Artikelnummer ein                                                                                                                                                                         |
| 2    | EK                    | Dem Einkäufer werden allgemeine Artikelinformationen, lokale Bestände und verfügbare Lieferanten angezeigt                                                                                               |
| 3    | EK                    | Einkäufer wählt Lieferanten aus, trägt Bestellmenge und gewünschtes Lieferdatum ein                                                                                                                      |
| 4    | EK                    | Dem Einkäufer wird eine Vorschau zur Bestellung angezeigt, welche Bestätigt werden kann                                                                                                                  |
| 5    | EK                    | Einkäufer bestätigt generierte Bestellung                                                                                                                                                                |
| 6    | L                     | Bestellung wird an Lieferanten gesendet und Vorgang wird protokolliert                                                                                                                                   |
|      | **Erweiterungen**     |                                                                                                                                                                                                          |
| zu 1 | EK                    | Es wird der Artikelname eingegeben; <br>Es wird eine Liste mit den wahrscheinlichsten Treffern und deren Artikelnummern angezeigt; <br>Durch Auswahl eines Eintrags wird diese Artikelnummer eingegeben. |
|      | **Fehlersituationen** |                                                                                                                                                                                                          |
| zu 1 | LV                    | Artikelnummer existiert nicht; Vorgang wird abgebrochen                                                                                                                                                  |

### Artikel für automatische Verwaltung markieren
#### *Aus Platzgründen wurde dieser Anwendungsfall ausgelassen*

|     | Anwendungsfall        |     |
| --- | --------------------- | --- |
|     | Kurzbeschreibung      |     |
|     | Beteiligte Akteure    |     |
|     | Vorbedingung          |     |
|     | Nachbedingung         |     |
|     | Auslöser              |     |
|     | **Standardszenario**  |     |
|     |                       |     |
|     | **Erweiterungen**     |     |
|     |                       |     |
|     | **Fehlersituationen** |     |
|     |                       |     |


### Artikel nicht länger automatisch Verwalten
#### *Aus Platzgründen wurde dieser Anwendungsfall ausgelassen*

|     | Anwendungsfall        |     |
| --- | --------------------- | --- |
|     | Kurzbeschreibung      |     |
|     | Beteiligte Akteure    |     |
|     | Vorbedingung          |     |
|     | Nachbedingung         |     |
|     | Auslöser              |     |
|     | **Standardszenario**  |     |
|     |                       |     |
|     | **Erweiterungen**     |     |
|     |                       |     |
|     | **Fehlersituationen** |     |
|     |                       |     |

### Artikel automatisch verwalten

|      | Anwendungsfall        | Artikel automatisch verwalten                                                                                                                                                                                              |
| ---- | --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung      | In regelmaßigen Abständen ruft der Job-Scheduler diese Funktion auf. Darauf hin wird geprüft, ob ein Artikel bestellt werden muss und ggf. wird eine Bestellung ausgelöst                                                  |
|      | Beteiligte Akteure    | Job-Scheduler, Lieferant, Einkäufer, LAgerverwalter                                                                                                                                                                        |
|      | Vorbedingung          | Vordefinierte Zeit des Intervalls ist abgelaufen.<br>Mindestens ein Artikel für automatische Verwaltung markiert.                                                                                                          |
|      | Nachbedingung         | Alle für automatische Verwaltung markierten Artikel wurden geprüft und der Einkauf wurde informiert bzw. die Bestellung wurde ausgelöst                                                                                    |
|      | Auslöser              | Ablauf des Zeitintervalls                                                                                                                                                                                                  |
|      | **Standardszenario**  |                                                                                                                                                                                                                            |
| 1    | JS                    | Der Job-Scheduler iteriert über seine Liste, der für automatische Verwaltung markierter Artikel                                                                                                                            |
| 2    | JS                    | prüft, ob eine Lagerposition des Artikels abgelaufen ist                                                                                                                                                                   |
| 3    | JS                    | prüft, ob der Mindestbestand unterschritten worden ist                                                                                                                                                                     |
|      | **Erweiterungen**     |                                                                                                                                                                                                                            |
| zu 2 | JS, LV                | Der Job-Scheduler stellt fest, dass Lagerpositionen des Artikels abgelaufen sind. Es wird der Lagerverwalter informiert die Artikel auszulagern und zu entsorgen und die Lagerposition wird aus dem Gesamtbestand entfernt |
| zu 3 | JS, EK, L             | Der Job-Scheduler stellt fest, dass der Mindestbestand unterschritten worden ist;<br>die Bestellung wird beim zugeordneten Lieferanten ausgelöst und der                                                                   |
|      | **Fehlersituationen** |                                                                                                                                                                                                                            |
| zu 3 | JS, EK                | Der Job-Scheduler stellt fest, dass der Mindestbestand unterschritten worden ist, aber es wurde kein Lieferant zugeordnet;<br>der Einkauf wird per E-mail über den Mangel informiert und aufgefordert zu Bestellen         |

### Log ausgeben
#### *Aus Platzgründen wurde dieser Anwendungsfall ausgelassen*


# Systemdesign

## Übersicht
Das Systemdesign der Lagerverwaltung für den Großhändler beschreibt die strukturelle Gliederung der Software in Komponenten und deren Interaktion. Es wird eine **verteilte Architektur** mit autonomen Lokalsystemen und einem zentralen Koordinationssystem entworfen, um die Anforderungen an Ausfallsicherheit, Skalierbarkeit und Echtzeit-Bestandsführung zu erfüllen.

Das System folgt einem **Microservice-Ansatz**, bei dem jede wesentliche Funktion (z. B. Bestandsverwaltung, Bestellmanagement, etc.) als eigenständiger Service implementiert wird. Die Kommunikation zwischen den Services erfolgt über definierte APIs (REST/HTTP) und asynchrone Nachrichten (Message Queue). Dadurch können einzelne Teile des Systems unabhängig skaliert, deployed und gewartet werden.


### Kernkomponenten
1. **Lokaler Lagerdienst (LLD)** – Pro Standort ein Service, der die lokale Lagerverwaltung (Ein‑/Auslagerung, Positionsverwaltung, Verfallsdatum) übernimmt.
2. **Zentraler Bestandsdienst (ZBD)** – Führt die aggregierten Bestandsdaten aller Standorte, koordiniert Abfragen und Synchronisation.
3. **Bestellservice (BS)** – Verwaltet Bestellvorgänge (manuell/automatisch) und kommuniziert mit Lieferanten.
4. **Analytics-Service (AS)** – Berechnet Statistiken, Kennzahlen und generiert automatisierte Empfehlungen (z. B. Nachbestellung, Umschichtung).
5. **Job-Scheduler (JS)** – Führt zeitgesteuerte Aufgaben aus (automatische Bestandsprüfung, Auswertungen, Benachrichtigungen).
6. **API-Gateway** – Zentrale Eintrittspunkt für alle Client-Anfragen (Web‑Frontend, Mobile Apps) und Routing zu den jeweiligen Services.
7. **Nachrichten-Broker** (z. B. RabbitMQ, Apache Kafka) – Für asynchrone Kommunikation, insbesondere bei Bestandsaktualisierungen und Ereignis‑Benachrichtigungen.

### Datenbanken
- **Zentrale Datenbank** (z. B. PostgreSQL/MySQL): Speichert Stammdaten (Artikel, Lieferanten, Standorte), aggregierte Bestände, Bestellhistorien und globale Protokolle.
- **Lokale Datenbanken** (pro Standort, z. B. SQLite oder PostgreSQL): Enthalten die detaillierten Lagerpositionen, Verfallsdaten und lokale Transaktionsprotokolle.
- **Analytics-Datenbank** (z. B. TimescaleDB oder ClickHouse): Optimiert für zeitreihenbasierte Abfragen und statistische Auswertungen.

### Caching
- **Valkey** oder ähnlicher In‑Memory‑Cache wird eingesetzt, um häufig abgefragte Daten (z. B. Artikelstammdaten, aktuelle Bestände) zwischenzuspeichern und die Antwortzeiten zu verbessern.
- Cache‑Strategie: LRU (Least Recently Used) mit Time‑to‑Live (TTL) für volatile Daten.


## API-Schnittstellen (REST)

Die APIs werden nach REST‑Prinzipien definiert. Beispiele:
### Artikel anzeigen
```
get_Artikel: {ArtikleID} -> bool x string
```
Eingabe ist die Artikelnummer, Die Rückgabe ist ein Boolean, der Erfolg oder Misserfolg signalisiert, und, im Falle des Erfolgs, eine JSON-Datei mit Artikelinformationen, oder im Falle eines Misserfolgs, eine Fehlermeldung zurückgibt.

### Artikel einlagern
```
store_Artikel: {ArtikelID} -> bool
```
Die Eingabe ist hier die gekürzte URL, die Ausgabe eine Indikation über Erfolg oder Misserfolg. Auch hier können wir wieder eine Fehlermeldung oder einen Fehlercode zusätzlich zurückgeben. 

### Artikel auslagern
```
withdraw_Artikel: {ArtikelID} -> bool
```
Body: { "quantity": 2, "location": "A-12" }
## Threat Modeling



## Komponentendesign



# Eidesstattliche Erklärung

Ich erkläre hiermit an Eides statt, dass ich die vorliegende Ausarbeitung selbstständig und ohne unerlaubte fremde Hilfe angefertigt, andere als die angegebenen Quellen und Hilfsmittel nicht benutzt und die den benutzten Quellen wörtlich oder inhaltlich entnommenen Stellen als solche kenntlich gemacht habe.

………………………………………, den ………………………………

……………………………………………………………………………….
(Unterschrift)