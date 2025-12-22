
- begrüß die Leute 
- Stell dich vor
- Das ALayer (Anwendung) 
- Zusammenschluss der oberen Schichten des OSI-Modells
- Linie nicht genau zu ziehen
- ACodex
	- Ver- und Entcodierung der Nachrichten
	- Interface, um Befehle in der anderen Instanz auszuführen
		- Charakteristik der Darstellungsschicht (Verschlüsselung)
- ACom
	- Zustandsautomat = Herzstück des ALayer
	- startet im "IDLE"
	- 1. Möglichkeit - Nachricht senden
		- wechsel in den "sending"-Zustand
		- kann jetzt nicht mehr empfangen
		- warte auf "sendFile()"
			- Charakteristik der Anwendungsschicht (Schnittstelle)
		- warte auf "CNCnf()"
			- Charakteristik der Sitzungsschicht (Auf-/ Abbau der Verbindung)
			- else TimeOut
		- senden den Filename
		- senden Datei Zeile um Zeile
			- Charakteristik der Transportschicht (Segmentierung)
		- zählen den LineCount
			- Charakteristik der Transportschicht (Flusskontrolle, wieder zusammensetzten)
		- warten auf DCNCnf() 
			- else TimeOut
			- Charakteristik der Transportschicht (Fehlerbehandlung)
		- Transportschicht nicht ganz enthalten
			- Portüberwachung der Transportschicht haben wir nicht behandelt
	- 2. Möglichkeit - Nachrichten empfangen
		- Skript von Herr Sonntag
		- Regelmäßig abtastet ob eine neue Nachricht eingetroffen
		- wenn "CNInd()" schicken "CNRes()"
		- warte auf Filename
		- generieren neue Datei 
		- schreiben die ankommenden Zeilen in die Datei
			- Charakteristik der Transportschicht (wieder Zusammensetzung)
		- bis DCNInd()
			- Charakteristik der Sitzungsschicht (Verbindungsabbau)
		- Prüfen ob die Zeilenanzahl stimmt
			- Charakteristik der Transportschicht (Flusskontrolle)
			- und schicken den DCNRes() mit +/-

Somit kümmert sich das ALayer um:
- die Delegierung
- was, wann, in welcher Reihenfolge
- reagiert mit TimeOuts wenn nötig
- und kontrolliert ob alle Zeilen der Datei angekommen sind



Darstellungsschicht
Die Darstellungsschicht (Presentation Layer) ist die
==sechste Ebene des OSI-Modells== und fungiert als "Übersetzer" für die Datenübertragung zwischen unterschiedlichen Systemen, indem sie Datenformate umwandelt

Die Transportschicht (Schicht 4 im OSI-Modell)
==sorgt für eine zuverlässige, Ende-zu-Ende-Datenübertragung zwischen Endsystemen, indem sie den Datenstrom segmentiert, den Fluss steuert, Staus vermeidet und Fehler korrigiert, wobei Protokolle wie **TCP** (zuverlässig, [verbindungsorientiert](https://www.google.com/search?q=verbindungsorientiert&client=firefox-b-d&hs=aR0o&sca_esv=dd9a3d0f2248ec6d&sxsrf=AE3TifPo1Cd_eUbS7wht6zVNeGvmEPT5RQ%3A1766151500599&ei=TFVFadSlJKqGxc8Pl_P2uQQ&ved=2ahUKEwjhqrD26MmRAxVFiP0HHTkyDrMQgK4QegQIARAC&uact=5&oq=Transportschicht&gs_lp=Egxnd3Mtd2l6LXNlcnAiEFRyYW5zcG9ydHNjaGljaHQyChAjGPAFGCcYyQIyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgAQyBBAAGB4yBBAAGB4yBBAAGB5I7SZQjARY_hBwAXgBkAEAmAGNAaABsAWqAQM4LjG4AQPIAQD4AQGYAgmgAqcFwgIKEAAYsAMY1gQYR8ICBhAAGAcYHsICChAuGIAEGLEDGA3CAg0QLhiABBjHARgNGK8BwgIJEC4YgAQYChgNwgIIEAAYBxgKGB7CAgcQABiABBgNwgIIEAAYBxgIGB7CAgoQABgHGAgYChgewgINECMY8AUYsAIYJxjJAsICBhAAGA0YHpgDAIgGAZAGCJIHAzguMaAH3kGyBwM3LjG4B5wFwgcFMi04LjHIBy6ACAA&sclient=gws-wiz-serp&mstk=AUtExfAVfW9HlNKadc3gYfhsJLlwD5_wTx6Mv022MsQ0ak68vFzeF_rnWDzm8xdcXT38r9RzflyvDelzDvtx-VM9dKFaAj2OxUKAzNj5IuR0oDI0G65veSw9DOhf6S44tV4R10Eg4hygwXN6UeZkIx9OpQyZ2IzXkYDzve9U24g1LUufpAc&csui=3)) und **UDP** (schnell, [verbindungslos](https://www.google.com/search?q=verbindungslos&client=firefox-b-d&hs=aR0o&sca_esv=dd9a3d0f2248ec6d&sxsrf=AE3TifPo1Cd_eUbS7wht6zVNeGvmEPT5RQ%3A1766151500599&ei=TFVFadSlJKqGxc8Pl_P2uQQ&ved=2ahUKEwjhqrD26MmRAxVFiP0HHTkyDrMQgK4QegQIARAD&uact=5&oq=Transportschicht&gs_lp=Egxnd3Mtd2l6LXNlcnAiEFRyYW5zcG9ydHNjaGljaHQyChAjGPAFGCcYyQIyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgAQyBBAAGB4yBBAAGB4yBBAAGB5I7SZQjARY_hBwAXgBkAEAmAGNAaABsAWqAQM4LjG4AQPIAQD4AQGYAgmgAqcFwgIKEAAYsAMY1gQYR8ICBhAAGAcYHsICChAuGIAEGLEDGA3CAg0QLhiABBjHARgNGK8BwgIJEC4YgAQYChgNwgIIEAAYBxgKGB7CAgcQABiABBgNwgIIEAAYBxgIGB7CAgoQABgHGAgYChgewgINECMY8AUYsAIYJxjJAsICBhAAGA0YHpgDAIgGAZAGCJIHAzguMaAH3kGyBwM3LjG4B5wFwgcFMi04LjHIBy6ACAA&sclient=gws-wiz-serp&mstk=AUtExfAVfW9HlNKadc3gYfhsJLlwD5_wTx6Mv022MsQ0ak68vFzeF_rnWDzm8xdcXT38r9RzflyvDelzDvtx-VM9dKFaAj2OxUKAzNj5IuR0oDI0G65veSw9DOhf6S44tV4R10Eg4hygwXN6UeZkIx9OpQyZ2IzXkYDzve9U24g1LUufpAc&csui=3)) zum Einsatz kommen==.