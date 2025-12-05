# Inhaltsverzeichnis

---
$$
\text{Glossar}
$$
$$
\left[
\begin{array}\\
\text{FTD} & - & \text{File Transfere Dienst} \\
\text{FTD} & - & \text{File Transfere Dienst} \\

\end{array}
\right]
$$
---


# Aufgabenstellung: Protocol-Engineering „myTCP“ 

- Entwurf und Realisierung eines Dienstes für die zuverlässige Dateiübertragung zwischen zwei PCs .
- Randbedingung: Grundsätze des OSI- Schichtenmodell berücksichtigen.

Von: Wolfgang Sonntag & Prof. Dr. Jürgen Jasperneite


## Benutzer-Leistungsmerkmale

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
- Der Ziel-PC könnte besetzt oder gar nicht empfangsbereit sein und die Übertragung könnte stark gestört sein, so daß ein Abbruch erforderlich wird. 


## Technische Leistungsmerkmale

- Auf der Grundlage der bisherigen Festlegungen sollen folgende für die Entwicklung wichtigen Merkmale erfüllt werden: • Benutzung der Ethernet-Schnittstelle der PCs
- Einstellbarkeit notwendiger Kommunikationsparameter
- Frei wählbare, alphanumerische Namenswahl (logische Adresse) für den PC
- Herstellen, Halten und Abbauen von temporären Datenverbindungen zwischen je zwei PCs
- Zuverlässige Übertragung von Telegrammen zwischen den Stationen
- Übertragung der Dateien in sinnvollen Blöcken (zeilenweise)
- Korrekte Übertragung von Dateien hinsichtlich Vollständigkeit, Bestätigung an den Benutzer, Wiederaufsetzen bei Übertragungsfehlern.

- **Rahmenbedingung:**
  Bei dieser Aufgabenstellung wird auf das Framing (Schicht-2) der Ethernet-Schnittstelle zurückgegriffen. Die Ethernet-Schnittstelle führt auch die Bildung und Auswertung einer Prüfsumme durch. 


# Anforderungen

## Analyse der Ebenenfunktionen

- Welche Funktion gehört in welche Schicht?
- Wieviele Schichten hat unser Kommunikationssystem? 



## Anwendungsschicht

- Stellt SAP für den File-Transfer-Dienst bereit 
- die Anwendungsschicht benötigt Funktionen, um
	- Dateien öffnen, lesen, schreiben,
	- Senden und Empfangen zeilenweise durchzuführen.
- Verantwortlich für Vollständigkeit der Dateiübertragung
- Zählerstände RX/TX
- Wiederholung bei Ungleichheit (n-mal) 


## Darstellungsschicht

- Alle PCs
	- INTEL x86 , WIN XP SP2 .
	- Dateien bestehen aus ASCII-Zeichen (Codierung/Dekodierung macht Betriebssystem)
	- homogener Rechnerverbund.
- Darstellungsschicht kann entfallen. 


## Transportschicht

- Unzulänglichkeiten des Kommunikationsnetzes ausgleichen.
- Segmentbildung, Flußkontrolle sind nicht notwendig. Daher ist die Transportschicht im vorliegenden Beispiel leer.
- Transportschicht kann **entfallen**.


## Vermittlungsschicht

- Eine Wegewahl (Routing) ist in unserem Beispiel nicht erforderlich.
- Die logische Adressierung (N-Adressen) der Endsysteme soll in alphanumerischer Schreibweise erfolgen. 


## Sicherungs- und Bitübertragungsschicht

- hier IEEE802.3
- Steuerung des Buszugriffs auf das Übertragungsmedium,
- die Framebildung, Fehler-Sicherung.
- Projektvorgabe: Nutzung NIC
	- Steuerung des Buszugriffs
	- Fehlersicherung mit Hilfe eines CRC-32
- Die logische Adressierung (N-Adressen) der Endsysteme soll in alphanumerischer Schreibweise erfolgen.
	- Abbildungsfunktion zwischen den logischen Adressen und den physikalischen Adressen (MAC-Adressen) ist vorzusehen.
	- vgl. ARP S


## Unser Kommunikationssystem


## Genereller Aufbau einer Protokoll-instanz



- i_COM beschreibt das zustandsabhängige Verhalten einer Instanz. (dynamische Protokollspezifikation)
- i_CODEX dient dem Codieren und Dekodieren von PDUs der i-Schicht von und zu Dienstdateneinheiten der i-1 Schicht 

---

# Lösungskonzept


