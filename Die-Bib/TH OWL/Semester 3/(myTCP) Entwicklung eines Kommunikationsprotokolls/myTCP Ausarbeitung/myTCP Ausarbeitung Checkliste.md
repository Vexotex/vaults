
Lösungskonzept:
- [ ] Benutzer-Leistungsmerkmale
	- [ ] „.. die Leistungsmerkmale der Datei-Übertragung stichwortartig zusammengestellt, wie sie sich aus der Sicht des PC-Benutzers darstellen sollen. ..“
	- [ ] Es sollen nur Textdateien übertragen werden können.
	- [ ] Mit dem Kommunikationssystem erhält der PC-Benutzer einen Dienst, eigene Dateien zu einem der n PCs zu senden, oder aber von einem der n PCs eine Datei zu empfangen. 
	- [ ] Dieser Anwendungsdienst wird im folgenden File-Transfer-Dienst, kurz FTD, genannt. 
	- [ ] Der FTD soll alternativ, aber nur zeitlich nacheinander zum Senden oder zum Empfangen von Textdateien aufrufbar sein (Halbduplex).
	- [ ] Das Empfangen ist passiv, d.h. ohne Benutzereingaben möglich.
	- [ ] Das Senden erfordert Eingaben vom Benutzer:
		- [ ] Ziel-PC, zu dem eine Datei übertragen werden soll
		- [ ] Name der Datei, die übertragen werden soll
		- [ ] Ziel-Dateiname, unter dem der übertragene Inhalt auf dem Ziel-PC abgelegt werden soll. 
	- [ ] Die Forderung nach Übertragung von Dateien in einem Netz bedingt eine einheitliche und widerspruchsfreie Adressierung.
		- [ ] Hierzu sind eindeutige MAC-Adressen und logische Adressen (PC- Namen) der Quell- und Ziel-PCs vorzusehen.
	- [ ] Der Benutzer soll während der Kommunikation durch Meldungen über den Ablauf der Übertragung informiert werden.
	- [ ] Der Ziel-PC könnte besetzt oder gar nicht empfangsbereit sein und die Übertragung könnte stark gestört sein, so dass ein Abbruch erforderlich wird.

- [ ] Technische Leistungsmerkmale
	- [ ] Auf der Grundlage der bisherigen Festlegungen sollen folgende für die Entwicklung wichtigen Merkmale erfüllt werden:
		- [ ] Benutzung der Ethernet-Schnittstelle der PCs
		- [ ] Einstellbarkeit notwendiger Kommunikationsparameter
		- [ ] Frei wählbare, alphanumerische Namenswahl (logische Adresse) für den PC
		- [ ] Herstellen, Halten und Abbauen von temporären Datenverbindungen zwischen je zwei PCs
		- [ ] Zuverlässige Übertragung von Telegrammen zwischen den Stationen
		- [ ] Übertragung der Dateien in sinnvollen Blöcken (zeilenweise)
		- [ ] Korrekte Übertragung von Dateien hinsichtlich Vollständigkeit, Bestätigung an den Benutzer, Wiederaufsetzen bei Übertragungsfehlern.

		- [ ] **Rahmenbedingung:**
		  Bei dieser Aufgabenstellung wird auf das Framing (Schicht-2) der Ethernet-Schnittstelle zurückgegriffen. Die Ethernet-Schnittstelle führt auch die Bildung und Auswertung einer Prüfsumme durch. V

- [ ] Abbildung der Anforderungen auf das OSI-Schichtenmodell
- [ ] Dienst- und Protokollspezifikationen der realisierten Funktionen
- [ ] Sequenzdiagramme zum Nachweis der wichtigsten Funktionen


