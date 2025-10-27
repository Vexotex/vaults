- Übersicht UI
	- Main menu
	- Platzierungsphase (im Level)
	- Revisionsphase (nach dem Level)
	- Highscores / Lowscores
	- Levelauswahl
	- (setting)
- Szenarien
	- wechsel ins main menu
	- wechsel in level Ansicht
	- level auswahl
	- level start
	- level neustart
	- level-Ansicht nach level ende
		- (carvane maschiert weiter)
	- wechsel in Einstellungen
	- Einstellungen speichern
	- wechsel in die Highscore-Ansicht
	- Szenarien während des Levels
		- Personen nach Bedürfnissen fragen
		- Person an unbesetzten Platz setzen
			- alt Person an besetzten Platz setzten
		- vom Platz entfernen
		- level-ende (Berechnung vom score / wechsel Revisionsphase)
		- Personen in revision inspizieren




| Anwendungsfall        | Person an unbesetzten Platz setzen                                                                                                                           |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Kurzbeschreibung      | Der Spieler kann eine beliebige Person vom Bahnsteig oder einem Platz auf einen beliebigen Platz setzen. dies kann über "Drag and Drop" funktionieren        |
| Beteiligte Akteure    | Spieler                                                                                                                                                      |
| Vorbedingung          | Spieler muss im level sein<br>Startplatz nicht leer                                                                                                          |
| Nachbedingung         | Person sitzt auf neuem Platz.<br>alter Platz ist frei, wenn ungleich neuem Platz.                                                                            |
| Auslöser              | Spieler drückt auf Person und zieht                                                                                                                          |
| Standardszenario      | 1. Spieler drückt auf Person und zieht<br>2. Spieler hovert über dem neuen freien Platz<br>3. Spieler lässt los<br>4. Person setzt sich auf neuen Platz      |
| Alternative Szenarien | zu 2. Zielplatz ist besetzt <br>-> 4. Personen tauschen Plätze<br>zu 2. Spieler hovert nicht über einem Platz<br>-> 4. Person setzt sich auf alten Platz<br> |
| Erweiterungen         |                                                                                                                                                              |
| Fehlersituationen     | zu 2. Spieler verlässt Spielfläche <br>-> Abbruch und Person setzt sich auf den alten Platz                                                                  |

| Anwendungsfall        | wechsel in level Ansicht                                                                                                                                                                   |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Kurzbeschreibung      | der Spieler kann aus dem Level, aus der Revisionsphase und dem Hauptmenu in die Level Ansicht wechseln und hat dort eine Übersicht über alle Level.                                        |
| Beteiligte Akteure    | Spieler                                                                                                                                                                                    |
| Vorbedingung          | nicht in Levelansicht                                                                                                                                                                      |
| Nachbedingung         | in Levelansicht                                                                                                                                                                            |
| Auslöser              | klick auf "Levelansicht"                                                                                                                                                                   |
| Standardszenario      | der Spieler drückt auf den Button "Levelansicht" und wechselt in diese                                                                                                                     |
| Alternative Szenarien | Spieler kommt aus der Revisionsphase mit Qualifikation fürs nächste Level<br>-> nächstes Level wird freigeschaltet und ausgewählt                                                          |
| Erweiterungen         | zu alt: kein "nächstes Level" verfügbar also letztes Level geschafft<br>-> Victory screen & credits. Anschließend wird in die Levelansicht gewechselt und das letzte Level wird ausgewählt |
| Fehlersituationen     |                                                                                                                                                                                            |