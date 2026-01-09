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

---

# 2. Aufgabenstellung:  

- Entwurf und Realisierung eines Dienstes für die zuverlässige Dateiübertragung zwischen zwei PCs .
- Randbedingung: Grundsätze des OSI- Schichtenmodell berücksichtigen.


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

## 4.1 Abbildung der Anforderungen auf das OSI-Schichtenmodell

In diesem Kapitel wird erläutert, wie die Anforderungen dieses Projekts auf das siebenschichtige OSI-Referenzmodell abgebildet wurden. Dieses Modell diente als konzeptionelle Grundlage für die zuverlässigen Dateiübertragung zwischen zwei PCs, da allerdings nicht alle Schichten für das gegebene Szenario notwendig sind, wurde eine reduzierte, anwendungsorientierte Schichtenarchitektur entworfen.

### 4.1.1 Grundlegende Überlegungen zur Schichtenauswahl
#### Anwendungsschicht
Die Bereitstellung für den Nutzer wurde in Form von aufrufbaren Funktionen realisiert.

#### Darstellungsschicht
Es wurde keine Form der Datenkomprimierung oder Datenformatierung implementiert. Die Kodierung wurde in stark vereinfachter Form implementiert, wie in XXX beschrieben.

#### Sitzungsschicht
Im A-Layer wurde eine Halbduplex-Steuerung in vereinfachter Form integriert.

#### Transportschicht
Bei der Übertragung wird die .txt - Datei in Zeilenweise aufgeteilten Strings übertragen und Anschließend wird geprüft ob die Anzahl der Übertragenen Zeilen mit der Anzahl der Empfangenen übereinstimmt.

#### Vermittlungsschicht
Die logische Addressierung wird durch Eingabe der PC-Namen realisiert, aber kein Routing in andere Netzwerke. Somit kann die Kommunikation mit einem anderen PC nur erfolgen, wenn sie sich im selben Netzwerk befinden. 

#### Sicherungsschicht
Nach einem Initialen Broadcast wird anschließend auch die MAC-Adresse des Übertragungspartners dokumentiert und in den darauffolgenden Frames genutzt. Allerdings wird hier weder eine zuverlässige noch eine fehlerfreie Datenübertrargung gesorgt.

#### Bitübertragung
Durch Funktionen, die von Herr Wolfgang Sonntag gestellt worden sind, nutzen wir den vollen Umfang Ethernet-Harware der Netzwerkkarte. 


### 4.1.2 Eigenes Schichtenmodell für "myTCP"

Auf Basis dieser Analyse wurde ein dreischtigter Protokoll-Stack entworfen, der die OSI-Funktionalitäten bündelt:

#### A_Layer
Das A_Layer ist eine grobe Zusammenfassung der Schichten 7-4 (Anwendung, Darstellung, Sitzung, Transport):
- Stellt einen SAP für den FTD

#### Adaption_Layer


#### DL-Layer




## 4.2 Dienst- und Protokollspezifikationen der realisierten Funktionen



## 4.3 Sequenzdiagramme zum Nachweis der wichtigsten Funktionen


