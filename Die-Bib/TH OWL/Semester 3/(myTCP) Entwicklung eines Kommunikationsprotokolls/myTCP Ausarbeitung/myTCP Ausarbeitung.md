# **Projektbericht: Entwurf und Implementierung des File-Transfer-Dienstes „myTCP“**

**Verfasser:** Jeremy Braun
**Datum:** 08.12.25
**Lehrveranstaltung:** Protocol-Engineering (EK 5060) / Vertiefungspraktikum Rechnernetze (VP 1270)  
**Betreuer:** Prof. Dr. Jürgen Jasperneite, Wolfgang Sonntag

# Inhaltsverzeichnis

- Glossar
- Protocol-Engineering "myTCP"
	- Aufgabenstellung
		- Benutzer-Leistungsmerkmale
		- Technische Leistungsmerkmale
	- Anforderungen
		- Analyse der Ebenenfunktionen
		- Anwendungen
		- Darstellungen
		- Transportschicht
		- Vermittlungsschicht
		- Sicherungsschicht- und Bitübertragungsschicht
		- Unsere Kommunikationsschicht
		- Genereller Aufbau einer Protokollinstanz
- Lösungskonzept

---
# 1. Glossar

| Abkürzung | Bedeutung                                         |
| --------- | ------------------------------------------------- |
| FTD       | **F**ile **T**ransfer **D**ienst                  |
| OSI       | **O**pen **S**ystem **I**nterconnection           |
| PC        | **p**ersonal **C**omputer                         |
| MAC       | **M**edia **A**ccess **C**ontrol                  |
| NIC       | **N**etwork **I**nterface **C**ard/**C**ontroller |
| GUI       | **G**raphical **U**ser **I**nterface              |
| IDE       | **I**ntegrated **D**evelopment **E**nviorment     |
| SAP       | **S**ervice **A**ccess **P**oint                  |
| RX        | **R**ecieve / Empfangen                           |
| TX        | **T**ransmit / Senden                             |
| PDU       | **p**rotokoll **d**ata **u**nit                   |
| PCI       | **p**rotokoll **c**ontroll **i**nformation        |

---

# 2. Aufgabenstellung:  

Entwurf und Realisierung eines Dienstes für die zuverlässige Dateiübertragung zwischen zwei PCs. Randbedingung: Grundsätze des OSI- Schichtenmodell berücksichtigen.


# 3. Anforderungen
## 3.1 Benutzer-Leistungsmerkmale

- „.. die Leistungsmerkmale der Datei-Übertragung stichwortartig zusammengestellt, wie sie sich aus der Sicht des PC-Benutzers darstellen sollen. ..“
- Es sollen nur Textdateien übertragen werden können.
- Mit dem Kommunikationssystem erhält der PC-Benutzer einen Dienst, eigene Dateien zu einem der n PCs zu senden, oder aber von einem der n PCs eine Datei zu empfangen. 
- Dieser Anwendungsdienst wird im folgenden File-Transfer-Dienst, kurz FTD, genannt. 
- Der FTD soll alternativ, aber nur zeitlich nacheinander zum Senden oder zum Empfangen von Textdateien aufrufbar sein (Halbduplex).
- Das Empfangen ist passiv, d.h. ohne Benutzereingaben möglich.
- Das Senden erfordert Eingaben vom Benutzer:
	- Ziel-PC, zu dem eine Datei übertragen werden soll
	- Name der Datei, die übertragen werden soll
	- Ziel-Dateiname, unter dem der übertragene Inhalt auf dem Ziel-PC abgelegt werden soll. 
- Die Forderung nach Übertragung von Dateien in einem Netz bedingt eine einheitliche und widerspruchsfreie Adressierung.
	- Hierzu sind eindeutige MAC-Adressen und logische Adressen (PC- Namen) der Quell- und Ziel-PCs vorzusehen.
- Der Benutzer soll während der Kommunikation durch Meldungen über den Ablauf der Übertragung informiert werden.
- Der Ziel-PC könnte besetzt oder gar nicht empfangsbereit sein und die Übertragung könnte stark gestört sein, so dass ein Abbruch erforderlich wird. 


## 3.2 Technische Leistungsmerkmale

- Auf der Grundlage der bisherigen Festlegungen sollen folgende für die Entwicklung wichtigen Merkmale erfüllt werden:
	- Benutzung der Ethernet-Schnittstelle der PCs
	- Einstellbarkeit notwendiger Kommunikationsparameter
	- Frei wählbare, alphanumerische Namenswahl (logische Adresse) für den PC
	- Herstellen, Halten und Abbauen von temporären Datenverbindungen zwischen je zwei PCs
	- Zuverlässige Übertragung von Telegrammen zwischen den Stationen
	- Übertragung der Dateien in sinnvollen Blöcken (zeilenweise)
	- Korrekte Übertragung von Dateien hinsichtlich Vollständigkeit, Bestätigung an den Benutzer, Wiederaufsetzen bei Übertragungsfehlern.

	- **Rahmenbedingung:**
	  Bei dieser Aufgabenstellung wird auf das Framing (Schicht-2) der Ethernet-Schnittstelle zurückgegriffen. Die Ethernet-Schnittstelle führt auch die Bildung und Auswertung einer Prüfsumme durch. 

## 3.3 Analyse der Ebenenfunktionen

- Welche Funktion gehört in welche Schicht?
- Wieviele Schichten hat unser Kommunikationssystem?

![[Einfuehrung zur Lehrveranstaltung.pdf#page=9&selection=40,0,40,6|Einfuehrung zur Lehrveranstaltung, page 9]]
### 3.3.1 Anwendungsschicht

- Stellt SAP für den File-Transfer-Dienst bereit 
- die Anwendungsschicht benötigt Funktionen, um
	- Dateien öffnen, lesen, schreiben,
	- Senden und Empfangen zeilenweise durchzuführen.
- Verantwortlich für Vollständigkeit der Dateiübertragung
- Zählerstände RX/TX
- Wiederholung bei Ungleichheit (n-mal) 


### 3.3.2 Darstellungsschicht

- Alle PCs
	- INTEL x86 , WIN XP SP2 .
	- Dateien bestehen aus ASCII-Zeichen (Codierung/Dekodierung macht Betriebssystem)
	- homogener Rechnerverbund.
- Darstellungsschicht kann entfallen. 


### 3.3.3 Transportschicht

- Unzulänglichkeiten des Kommunikationsnetzes ausgleichen.
- Segmentbildung, Flußkontrolle sind nicht notwendig. Daher ist die Transportschicht im vorliegenden Beispiel leer.
- Transportschicht kann **entfallen**.


### 3.3.4 Vermittlungsschicht

- Eine Wegewahl (Routing) ist in unserem Beispiel nicht erforderlich.
- Die logische Adressierung (N-Adressen) der Endsysteme soll in alphanumerischer Schreibweise erfolgen. 


### 3.3.5 Sicherungs- und Bitübertragungsschicht

- hier IEEE802.3
- Steuerung des Buszugriffs auf das Übertragungsmedium,
- die Framebildung, Fehler-Sicherung.
- Projektvorgabe: Nutzung NIC
	- Steuerung des Buszugriffs
	- Fehlersicherung mit Hilfe eines CRC-32
- Die logische Adressierung (N-Adressen) der Endsysteme soll in alphanumerischer Schreibweise erfolgen.
	- Abbildungsfunktion zwischen den logischen Adressen und den physikalischen Adressen (MAC-Adressen) ist vorzusehen.
	- vgl. ARP S

![[Einfuehrung zur Lehrveranstaltung.pdf#page=15&selection=8,0,8,26|Einfuehrung zur Lehrveranstaltung, page 15]]

![[Einfuehrung zur Lehrveranstaltung.pdf#page=16&selection=8,0,10,7|Einfuehrung zur Lehrveranstaltung, page 16]]


- i_COM beschreibt das zustandsabhängige Verhalten einer Instanz. (dynamische Protokollspezifikation)
- i_CODEX dient dem Codieren und Dekodieren von PDUs der i-Schicht von und zu Dienstdateneinheiten der i-1 Schicht 

---

# 4. Lösungskonzept

## 4.1 Umsetzung der Anforderungen

Als zentrales Werkzeug dieser Umsetzung wurde dir Software "IBM Engineering Systems Design Rhapsody" verwendet. 
Rhapsody ermöglicht es uns unser komplexes Systeme durch Nutzung von UML-Standards zu entwerfen, zu analysieren und simulieren. Wobei aus den graphisch erstellten Diagrammen code mit hohem Qualitätsstandard generiert wird. 


## 4.2 Abbildung der Anforderungen auf das OSI-Schichtenmodell

In diesem Kapitel wird erläutert, wie die Anforderungen dieses Projekts auf das siebenschichtige OSI-Referenzmodell abgebildet wurden. Dieses Modell diente als konzeptionelle Grundlage für die zuverlässigen Dateiübertragung zwischen zwei PCs, da allerdings nicht alle Schichten für das gegebene Szenario notwendig sind, wurde eine reduzierte, anwendungsorientierte Schichtenarchitektur entworfen.

### 4.2.1 Grundlegende Überlegungen zur Schichtenauswahl
#### Anwendungsschicht
Die Bereitstellung für den Nutzer wurde in Form von aufrufbaren Funktionen realisiert.

#### Darstellungsschicht
Es wurde keine Form der Datenkomprimierung oder Datenformatierung implementiert. Die Kodierung wurde in stark vereinfachter Form implementiert.

#### Sitzungsschicht
Im A-Layer wurde eine Halbduplex-Steuerung in vereinfachter Form integriert.

#### Transportschicht
Bei der Übertragung wird die .txt - Datei in Zeilenweise aufgeteilten Strings übertragen und Anschließend wird geprüft ob die Anzahl der Übertragenen Zeilen mit der Anzahl der Empfangenen übereinstimmt.

#### Vermittlungsschicht
Die logische Addressierung wird durch Eingabe der PC-Namen realisiert, aber kein Routing in andere Netzwerke. Somit kann die Kommunikation mit einem anderen PC nur erfolgen, wenn sie sich im selben Netzwerk befinden. 

#### Sicherungsschicht
Nach einem Initialen Broadcast wird anschließend auch die MAC-Adresse des Übertragungspartners dokumentiert und in den darauffolgenden Frames genutzt. Allerdings wird hier weder eine zuverlässige noch eine fehlerfreie Datenübertrargung gesorgt.

#### Bitübertragung
Durch Funktionen, die von Herr Wolfgang Sonntag gestellt worden sind, können wir die Ethernet-Harware der Netzwerkkarte nutzen und Frames zum senden weitergeben und prüfen ob neue Frames angekommen sind. 


### 4.2.2 Eigenes Schichtenmodell für "myTCP"

Auf Basis dieser Analyse wurde ein dreischtigter Protokoll-Stack entworfen, der die OSI-Funktionalitäten bündelt:

#### A_Layer
Das A_Layer ist eine grobe Zusammenfassung der Schichten 7-4 (Anwendung, Darstellung, Sitzung, Transport) und:
- stellt einen SAP für den FTD
- öffnet liest und schreibt Dateien
- steuert die Halbduplex-Verbindung 
- kontrolliert die Vollständigkeit der Übertragung mittels RX- / TX-Zählern
- löst Timeouts aus, bei fehlenden Antworten

#### Adaption_Layer
Das Adaption_Layer hat keine eigene Funktionalität und reicht die ankommenden Signale des A_Layer an das DL-Layer durch und andersherum. 
Dieses Layer dient als Platzhalter, um dieses Modell erweitern zu können ohne die SAPs des A_Layers oder DL_Layers anpassen zu müssen.

#### DL-Layer
Das DL_Layer fasst die übrigen Schichten 3-1 Zusammen (Vermittlung, Sicherung, Bitübertragung) und:
- verwaltet die Aufschlüsselung der PC-Namen
- Abbildung der PC-Namen auf MAC-Adressen
- gibt Frames an die NIC des PCs weiter
- prüft regelmäßig ob neue Frames angekommen sind 


## 4.3 Dienst- und Protokollspezifikationen der realisierten Funktionen


### 4.3.1 A_Layer 

Um die Funktionen des A_layer übersichtlicher Strukturieren zu können wurde er logisch in ACodex und ACom getrennt. Der ACodex übernimmt die En- und Decodierung der Nachrichten und der ACom stellt den Gesamtablauf und Behandlung der Sonderfälle in einem Zustandsautomaten dar.


#### ACom
Der Zustandsautomat und beginnt im "Idle" von hier aus kann er entweder in den Send-mode oder über eine Connect-Indication in den receiving-Pfad übergehen.

Im Send-mode wartet der Automat nun auf einen sendFile Befehl mit den notwendigen Informationen zum Empfänger, dem Namen der Datei, die versendet werden soll und unter welchem Namen die Datei ankommen soll. Nach dem erhalt wird ein Connect-Request zur Encodierung an den ACodex weitergegeben. Sollte dieser nicht innerhalb von 3 Sekunden bestätigt werden, geht der Automat wieder in den Idle. Nach Bestätigung der Verbindung sendet der Automat als erstes Dateinamen an Adaption und anschließend wird die Text-Datei Zeile für Zeile übertragen. Sobald die letzte Zeile Übertragen wurde wird ein Disconnect-Request, mit der Anzahl übertragenen Zeilen, an ACodex weitergegeben. Nun erwarten Wir eine Bestätigung des Verbindungsabbaus zusammen mit der Bestätigung, dass alle Zeilen angekommen sind. Nach 3 Sekunden gibt es einen TimeOut und der Automat kehrt zurück in den Idle. Sollte die gesendete Zeilenanzahl nicht mit der empfangenen Zeilenanzahl übereinstimmen, erhalten wir in der Bestätigung des Verbindungsabbaus ein "-" statt eines "+", kehren aber immer in den Idle zurück.  

Erhält der Automat im Idle eine Connect-Indication, so erwiedern wir den Verbindungsversuch mit einem Connect-Response und warten auf den Dateinamen und die Folgenden Zeilen der Text-Datei. Dabei zählen wir die empfangenen Zeilen und schreiben die Datei. Sobald die Disconnect-Indication empfangen wurde prüfen wir ob die Anzahl empfangender Zeilen mit der mitgegebenen Zahl der Disconnect-Indication und senden einen Disconnect-Response mit einem "+" bei identischer Zeilenanzahl und einem "-" bei einem Unterschied.  


#### ACodex
Hier wird jede Anfrage und Antwort des ACom in einer PDU encodiert, in einem PDataReq verpackt und an den Adaption Layer weitergegeben.
Sollte eine PData-Indication empfangen werden, so wird der Inhalt decodiert und der zugehörige Befehl im ACom ausgelöst.


### 4.3.2 Adaption

Der Adaption-Layer besteht aus einem Zustand "Idle" und kann auf zwei Aktionen reagieren.
Erstens kann der A_Layer die Funktion "PDataReq" aufrufen und darauf hin wird der Payload des "PDataReq" neu in einem "DLDataReq" neu verpackt und im DL_Layer oder genauer dem DLCom aufgerufen.
Zweitens kann der DL_Layer die Funktion "DLDataInd" aufrufen und folgend wird der Payload der "DLDataInd" neu in einer "PDataInd" neu verpackt und im A_Layer oder genauer dem ACodex aufgerufen.


### 4.3.3 DL_Layer

#### DLCom
Dieser Zustandsautomat beginnt wie der ACom und kann ebenfalls logisch in "empfangen" und "senden" getrennt werden.

Bekommt der Automat einen DLData-Request vom DLCodex, so wird geprüft, ob es sich um einen Verbindungsaufbau handelt. In diesem Fall wird ein Transmit im DLCodex als Broadcast versendet.
Andernfalls gab es zumindest eine Bestätigung des Verbindungsaufbaus und somit kann ein Single cast mit der zugehörigen MAC-Adresse ausgelöst werden.

Bei einem Eingangssignal wird zuerst geprüft für wen das Paket vorgesehen war und die empfangene MAC-Addresse mit unserer verglichen. Ist es für jemand anderen spezifiziert, so wird das Paket verworfen und in den Idle zurückgekehrt. Ist es an uns addressiert, so wird der Payload der Empfangenden Nachricht in einer DLData-Indication neu verpackt und an Adaption weitergeleitet. 
Handelt es sich um einen Broadcast, so decodieren wir den Payload der PDU und prüfen, ob jemand versucht mit uns eine Verbindung einzugehen. Versucht jemand mit uns eine Verbindung aufzubauen, so speichern wir seine MAC-Addresse zwischen und geben die DLData-Indication an Adaption weiter.



#### DLCodex




## 4.4 Sequenzdiagramme zum Nachweis der wichtigsten Funktionen


[[Diagramme.pdf]]