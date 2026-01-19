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
5. S - System
6. Z - Zentralsystem


## Darstellung der Akteure und Anwendungsfälle



## Anwendungsfälle / Szenarien

### Artikel einlagern

|      | Anwendungsfall            | Artikel einlagern                                                                                                                                                                                               |
| ---- | ------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Lagerartikel im System erfassen. Dabei bekommt er einen Lagerplatz vom System vorgeschlagen, kann aber einen definieren                                                                 |
|      | Beteiligte Akteure        | Lagerverwalter, Zentralsystem                                                                                                                                                                                   |
|      | Vorbedingung              | Artikel ist am Standort eingetroffen, Artikelnummer ist bekannt                                                                                                                                                 |
|      | Nachbedingung             | Artikel im System erfasst, Lagerposition zugewiesen, Lagerbestand aktualisiert, Änderung protokolliert, Zentrallagerbestand aktualisiert                                                                        |
|      | Auslöser                  | Artikel müssen eingelagert werden. <br>- Anlieferung neuer Ware <br>- Auftragsstornierung und wieder-Einlagerung<br>- etc.                                                                                      |
|      | **Standardszenario**      |                                                                                                                                                                                                                 |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                           |
| 2    | S                         | System zeigt Allgemeine Artikelinformationen an                                                                                                                                                                 |
| 3    | LV                        | Lagerverwalter trägt Lagerposition und Menge ein                                                                                                                                                                |
| 4    | S                         | System speichert Artikel mit Lagerposition und Menge                                                                                                                                                            |
| 5    | S                         | System protokolliert den Vorgang mit Personal-ID, Datum, Uhrzeit, Lagerposition und Menge                                                                                                                       |
| 6    | S, Z                      | System sendet Bestandsaktualisierung, mit Artikelnummer und hinzugefügter Stückzahl an Zentralsystem                                                                                                            |
| 7    | Z                         | Zentralsystem aktualisiert Gesamtbestand und erstellt eigens Protokoll zu: Mengenänderung und Standort der Änderung                                                                                             |
|      | **Alternative Szenarien** |                                                                                                                                                                                                                 |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                               |
| zu 3 | LV                        | Lagerverwalter bestätigt die vom System vorgeschlagene Lagerposition                                                                                                                                            |
|      | **Erweiterungen**         |                                                                                                                                                                                                                 |
| zu 3 | LV                        | Lagerverwalter trägt zusätzliche ein Verfallsdatum ein; <br>System speichert Artikel mit Position, Stückzahl und Verfallsdatum                                                                                  |
| zu 6 | S, Z                      | System erkennt markierte Änderungen, die noch gesendet werden müssen;<br>System sendet iterativ alle unsynchronisierten Änderungen;<br>System bestätigt Zentralsystem, dass aktueller Stand wieder Synchron ist |
|      | **Fehlersituationen**     |                                                                                                                                                                                                                 |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgebrochen                                                                                                                                     |
| zu 6 | S, Z                      | Zentralsystem nicht erreichbar;<br>Änderungen bleiben lokal gespeichert und für spätere Synchronisierung markiert                                                                                               |

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
| 2    | S, Z                      | System fordert beim Zentralsystem globale Bestände an                                                                                                                                                    |
| 3    | S                         | System zeigt Allgemeine Artikelinformationen, lokale Bestände und deren Lagerpositionen und Änderungsprotokolle, sowie globale Bestände an                                                               |
|      | **Alternative Szenarien** |                                                                                                                                                                                                          |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                        |
| zu 1 | EK                        | Einkäufer gibt Artikelnummer ein                                                                                                                                                                         |
| zu 1 | VK                        | Verkäufer gibt Artikelnummer ein                                                                                                                                                                         |
|      | **Erweiterung**           |                                                                                                                                                                                                          |
| zu 1 | LV / EK / VK              | Es wird der Artikelname eingegeben; <br>Es wird eine Liste mit den wahrscheinlichsten Treffern und deren Artikelnummern angezeigt; <br>Durch Auswahl eines Eintrags wird diese Artikelnummer eingegeben. |
|      | **Fehlersituationen**     |                                                                                                                                                                                                          |
| zu 1 | LV                        | Artikelnummer existiert nicht; Vorgang wird abgebrochen                                                                                                                                                  |
| zu 2 | S                         | System kann Zentralsystem nicht erreichen;<br>Es wird der zuletzt bekannte Wert für globale Bestände, mit einem Warnhinweis, ausgegeben. Oder keine Werte wenn nichts lokal gebuffert.                   |

### Artikel auslagern

|      | Anwendungsfall            | Artikel auslagern                                                                                                                                                                                                  |
| ---- | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
|      | Kurzbeschreibung          | Der Lagerverwalter kann Artikel auslagern. Dabei kann er entscheiden, welche Position im Lager ausgelagert wird.                                                                                                   |
|      | Beteiligte Akteure        | Lagerverwalter, System, Zentralsystem                                                                                                                                                                              |
|      | Vorbedingung              | Artikelnummer bekannt, Artikelbestand > 0                                                                                                                                                                          |
|      | Nachbedingung             | Bestand an Lagerposition aktualisiert, Änderung protokolliert, Zentrallagerbestand aktualisiert                                                                                                                    |
|      | Auslöser                  | Artikel muss ausgelagert werden.<br>- Verkauf getätigt und Ware muss für den Versand aus dem Lager.<br>- Ware ist abgelaufen und muss entsorgt.<br>- Ware muss zur Weiterverarbeitung in die Produktion.<br>- etc. |
|      | **Standardszenario**      |                                                                                                                                                                                                                    |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                              |
| 2    | S                         | System zeigt alle Im lokalen Standort vorhandenen Lagerpositionen und deren Verfallsdaten an                                                                                                                       |
| 3    | LV                        | Lagerverwalter wählt Position aus und gibt auszulagernde Menge an                                                                                                                                                  |
| 4    | S                         | System aktualisiert die Lagerposition                                                                                                                                                                              |
| 5    | S                         | System protokolliert den Vorgang mit Personal-ID, Datum, Uhrzeit, Lagerposition und Menge                                                                                                                          |
| 6    | S, Z                      | System sendet Bestandsaktualisierung, mit Artikelnummer und entnommener Stückzahl an Zentralsystem                                                                                                                 |
| 7    | Z                         | Zentralsystem aktualisiert Gesamtbestand und erstellt eigens Protokoll zu: Mengenänderung und Standort der Änderung                                                                                                |
|      | **Alternative Szenarien** |                                                                                                                                                                                                                    |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                                  |
|      | **Erweiterungen**         |                                                                                                                                                                                                                    |
| zu 6 | S, Z                      | System erkennt markierte Änderungen, die noch gesendet werden müssen;<br>System sendet iterativ alle unsynchronisierten Änderungen;<br>System bestätigt Zentralsystem, dass aktueller Stand wieder Synchron ist    |
|      | **Fehlersituationen**     |                                                                                                                                                                                                                    |
| zu 1 | LV                        | eingetragene Artikelnummer nicht vorhanden; Anwendungsfall wird abgebrochen                                                                                                                                        |
| zu 3 | LV                        | auszulagernde Menge größer als Position; Anwendungsfall wird abgebrochen                                                                                                                                           |
| zu 6 | S, Z                      | Zentralsystem nicht erreichbar;<br>Änderungen bleiben lokal gespeichert und für spätere Synchronisierung markiert                                                                                                  |

### Artikel auswerten

|      | Anwendungsfall            | Artikel auswerten                                                                                                                                                                                                                                                          |
| ---- | ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|      | Kurzbeschreibung          | Jeder Akteur kann Auswertungen zu einem Artikel erstellen lassen                                                                                                                                                                                                           |
|      | Beteiligte Akteure        | Lagerverwalter / Einkäufer / Verkäufer, System, Zentralsystem                                                                                                                                                                                                              |
|      | Vorbedingung              | Artikelnummer bekannt                                                                                                                                                                                                                                                      |
|      | Nachbedingung             | globale Menge und die Verteilung dieser über die Standorte werden angezeigt.<br>Statistiken zu globalen und lokalen Verkaufszahlen werden angezeigt                                                                                                                        |
|      | Auslöser                  | - Einkauf will indizieren, ob eine Bestellung ausgelöst werden sollte oder ob es sich überhaupt lohnt diesen Artikel weiter zu führen.<br>- Lagerverwalter will entscheiden, ob er gewisse Artikel sehr erreichbar oder eher schwer erreichbar einlagern sollte.<br>- etc. |
|      | **Standardszenario**      |                                                                                                                                                                                                                                                                            |
| 1    | LV                        | Lagerverwalter gibt Artikelnummer ein                                                                                                                                                                                                                                      |
| 2    | S, Z                      | System fordert beim Zentralsystem globale Bestände und globale Statistiken an                                                                                                                                                                                              |
| 3    | Z                         | Zentralsystem berechnet globale Statistiken zu Standortbezogenen Aus- und Einlagerungen, sowie aktuellen Beständen und gibt diese zurück                                                                                                                                   |
| 4    | S                         | System zeigt globale Bestände und ihre Verteilung über die Standorte und die Statistiken zu Standortbezogenen Aus- und Einlagerungen an.                                                                                                                                   |
|      | **Alternative Szenarien** |                                                                                                                                                                                                                                                                            |
| zu 1 | LV                        | Lagerverwalter scannt Barcode ein                                                                                                                                                                                                                                          |
| zu 1 | EK                        | Einkäufer gibt Artikelnummer ein                                                                                                                                                                                                                                           |
| zu 1 | VK                        | Verkäufer gibt Artikelnummer ein                                                                                                                                                                                                                                           |
| zu 1 | S                         | Routineauswertung vom System ruft Artikel auf                                                                                                                                                                                                                              |
| zu 3 | Z                         | Zentralsystem merkt, dass seit der letzten Statistikberechnung keine Änderung vorgenommen worden ist und gibt die letzte Berechnung zurück                                                                                                                                 |
|      | **Erweiterungen**         |                                                                                                                                                                                                                                                                            |
| zu 4 | Z                         | Zentralsystem erkennt, dass Standortbezogener Lagerbestand unter Mindestbestand liegt; <br>System informiert zuständigen Einkauf per E-Mail                                                                                                                                |
| zu 4 | Z                         | Zentralsystem erkennt, dass Standortbezogener Lagerbestand unter Mindestbestand liegt und der Artikel für automatischen Einkauf markiert ist; <br>System löst statistisch empfohlene Bestellung aus und informiert zuständigen Einkauf per E-Mail                          |
|      | **Fehlersituationen**     |                                                                                                                                                                                                                                                                            |
| zu 1 | LV                        | Artikelnummer existiert nicht; Vorgang wird abgebrochen                                                                                                                                                                                                                    |
| zu 3 | Z                         | Zentralsystem merkt, dass eine Verbindung zu einem Standort nicht herrscht und gibt Warnmeldung zu dieser Standortbezogenen Statistik zurück                                                                                                                               |
| zu 4 | S                         | Zentralsystem antwortet nicht / Es herrscht keine Verbindung; System zeigt nur lokale Statistik an                                                                                                                                                                         |

### Artikel bestellen

|     | Anwendungsfall        | Artikel bestellen                                                                                                        |
| --- | --------------------- | ------------------------------------------------------------------------------------------------------------------------ |
|     | Kurzbeschreibung      | Durch den Einkauf oder automatisch über das System können Bestellungen bei dem zugehörigen Lieferanten ausgelöst werden. |
|     | Beteiligte Akteure    | Einkauf, System, Lieferant                                                                                               |
|     | Vorbedingung          | Artikel muss bestellbar sein                                                                                             |
|     | Nachbedingung         | Bestellung wurde an den Lieferanten übermittelt                                                                          |
|     | Auslöser              | Ein Einkäufer oder das Zentralsystem entschiedet den Artikel zu bestellen.                                               |
|     | **Standardszenario**  |                                                                                                                          |
| 1   | EK                    | Einkäufer gibt Artikelnummer ein                                                                                         |
| 2   | S                     | System zeigt Allgemeine Artikelinformationen, lokale Bestände und verfügbare Lieferanten an                              |
| 3   | EK                    | Einkäufer wählt Lieferanten aus, trägt Bestellmenge und gewünschtes Lieferdatum ein                                      |
| 4   | S                     | System zeigt Vorschau zur Bestellung an und erwartet Bestätigung                                                         |
| 5   | EK                    | Einkäufer bestätigt generierte Bestellung                                                                                |
| 6   | S, L                  | System sendet Bestellung an Lieferanten und protokolliert den Vorgang                                                    |
|     | **Erweiterungen**     |                                                                                                                          |
|     |                       |                                                                                                                          |
|     | **Fehlersituationen** |                                                                                                                          |
|     |                       |                                                                                                                          |

### Artikel für automatische Verwaltung markieren


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

### Log ausgeben

# Systemdesign

# Threat Modeling

# Komponentendesign



# Eidesstattliche Erklärung

Ich erkläre hiermit an Eides statt, dass ich die vorliegende Ausarbeitung selbstständig und ohne unerlaubte fremde Hilfe angefertigt, andere als die angegebenen Quellen und Hilfsmittel nicht benutzt und die den benutzten Quellen wörtlich oder inhaltlich entnommenen Stellen als solche kenntlich gemacht habe.

………………………………………, den ………………………………

……………………………………………………………………………….
(Unterschrift)