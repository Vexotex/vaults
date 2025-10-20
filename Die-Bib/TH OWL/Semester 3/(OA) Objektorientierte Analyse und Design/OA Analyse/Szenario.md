Wir nennen eine einzelne Abfolge von Aktionen, d. h. einen Ablaufpfad in einem Anwendungsfall, ein Szenario.

Ein Szenario, das die Sicht der Anwender wiedergibt, fasst das zu entwickelnde System als Blackbox auf. Die innere Arbeitsweise des Systems bleibt den Anwendern verborgen, von Interesse ist allein das externe Verhalten. Das Augenmerk liegt bei dieser Perspektive auf typischen Interaktionen zwischen Benutzern und dem Anwendungssystem.

- Szenarien sind die wichtigsten Hilfsmittel bei Design und Implementation eines Systems 
- Sie helfen dem Entwickler, die erwartete Funktionsweise des Systems zu verstehen
- Es sollten immer **eher zu viele** als zu wenige Szenarien beschrieben werden.
- Wir beschreiben ein Szenario in einer Tabelle, deren Felder wir im Folgenden herausarbeiten wollen
- Jeder Anwendungsfall braucht mindestens ein Szenario, kann aber mehrere enthalten

## Vor- und Nachbedingungen
- Vorbedingungen geben an, welcher Systemzustand für erfolgreiche Ausführung vorhanden sein muss. 
- Nachbedingungen geben an, welcher Systemzustand nach der Ausführung gelten muss.

## Auslöser
Wir geben einen Auslöser an, also was passieren muss, damit dieses Szenario aufgerufen wird.

## Ablauf
- Der wichtigste Teil der Tabelle ist der Ablauf
- Wir beginnen mit dem Standardszenario, und geben anschließend Alternativen und Erweiterungen an
- Der Ablauf wird linear in Schritten angegeben, wobei die jeweiligen Akteure genannt werden

## Alternative Szenarien
- Alternative Szenarien können Abweichungen angeben
- Hierbei wird jeweils in einem Schritt abgewichen
- Vor- und Nachbedingung dürfen sich nicht ändern (siehe Fehlersituationen)

## Erweiterungen
- Erweiterungen können zusätzliche Abläufe beschreiben
- Sie ändern ebenfalls die Nachbedingung nicht

## Fehlersituationen
- Fehler können den erfolgreichen Ablauf verhindern
- Die Nachbedingungen werden nicht erfüllt
- Eine Fehlersituation beschreibt daher nicht nur den Fehler, sondern auch den neuen Status des Systems

## Übersicht
 
| Anwendungsfall        |
| --------------------- |
| Kurzbeschreibung      |
| Beteiligte Akteure    |
| Vorbedingungen        |
| Nachbedingungen       |
| Auslöser              |
| Standardszenario      |
| Alternative Szenarien |
| Erweiterungen         |
| Fehlersituationen     |
## Was ist zu fragen?
- Warum benutzt der Akteur das System?
- Welche Art von Antwort erwartet der Akteur von der Aktion?
- Was muss der Akteur tun, um das System benutzen zu können?
- Welche Informationen muss der Akteur dem System übermitteln?
- Welche Informationen erwartet der Akteur als Antwort vom System?

## Diagramm
[[Szenario Diagramm.excalidraw]]
- In der Darstellung als Diagramm kann man Alternativen direkt einbauen
- Diese Darstellung sollte **ergänzend gewählt werden, nicht ausschließlich**
- Die Form kann UML folgen, wichtig ist jedoch, dass Informationen korrekt transportiert werden
- Wenn nicht gerade externe Firmen ohne weitere Kommunikation während der Implementation beauftragt werden sollen, ist Kommunikation oft wichtiger als korrektes UML

---
- Wir geben dem Anwendungsfall einen Namen, und beschreiben ihn kurz.
- Anschließend führen wir die Akteure ein, und geben ihnen Kürzel zur späteren Referenz.

| Anwendungsfall     | Bezeichnung                                             |
| ------------------ | ------------------------------------------------------- |
| Kurzbeschreibung   | Wesentliche Funktionen sowie Bedeutung für den Anwender |
| Beteiligte Akteure | Kürzel und Bezeichnung                                  |
 
| Vorbedingung    | Systemzustand, der für erfolgreiche Ausführung<br>erforderlich ist |
| --------------- | ------------------------------------------------------------------ |
| Nachbedingungen | Systemzustand, der nach erfolgreicher<br>Ausführung vorliegt       |

| Auslöser | Ereignisse oder Aktionen, die den<br>Anwendungsfall auslösen, z. B. zeitliche<br>Ereignisse oder auch Ausnahmefälle in<br>anderen Anwendungsfällen |
| -------- | -------------------------------------------------------------------------------------------------------------------------------------------------- |
 
| Standardszenario<br><br>  <br><br>Schrittnr, Akteur | Kurzbeschreibung der einzelnen Schritte eines<br><br>erfolgreichen Ablaufs, der entweder mit der<br><br>auslösenden Aktion oder dem Eintreten der<br><br>Vorbedingung beginnt und mit dem<br><br>gewünschten Ergebnis oder dem Eintritt der<br><br>erwarteten Nachbedingung endet |
| --------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
 
| Alternative Szenarien<br><br>Schrittnr, Akteur | z. B. Redefinition oder Alternativen für Schritte<br>im Standardszenario |
| ---------------------------------------------- | ------------------------------------------------------------------------ |

| Erweiterungen<br><br>Schrittnr, Akteur | Erweiterung von Schritten im Standardablauf |
| -------------------------------------- | ------------------------------------------- |

| Fehlersituation<br><br>Schrittnr, Akteur | Situationen, die bei diesem Schritt zu einer nicht erfolgreichen Ausführung führen.<br>Beschreibung des Systemzustands nach einer<br>nicht erfolgreichen Ausführung |
| ---------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- |


---
Beispiel Adas Blumenladen:

| Anwendungsfall     | Bestellung eines Premiumkunden                                                                                                                                                                                                                                       |
| ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Kurzbeschreibung   | Ein Premiumkunde kann ein Bestellung<br>aufgeben und diese dann kostenlos nach<br>Hause liefern lassen. Die Bestellung kann<br>telefonisch oder persönlich erfolgen. Es sind<br>sowohl Barbezahlung als auch Bezahlung mit<br>Kreditkarte oder per Rechnung möglich. |
| Beteiligte Akteure | Vk         Verkäufer<br>Pk         Premiumkunde<br>Ku         Kurier                                                                                                                                                                                                 |
 
| Vorbedingung  | Der bestellte Artikel muss auf Lager oder<br>rechtzeitig bestellbar sein. Der Kunde ist ein<br>Premiumkunde. |
| ------------- | ------------------------------------------------------------------------------------------------------------ |
| Nachbedingung | Der Artikel wurde an den Kunden geliefert und<br>der entsprechende Betrag bezahlt.                           |

| Auslöser | Anruf eines Kunden oder Besuch des Kunden<br>im Laden |
| -------- | ----------------------------------------------------- |
 
| 1.  | Pk  | Der Kunde nennt die gewünschten Artikel<br><br>persönlich im Laden.                        |
| --- | --- | ------------------------------------------------------------------------------------------ |
| 2.  | Vk  | Der Verkäufer stellt fest, dass die Artikel in<br><br>ausreichender Menge auf Lager sind.  |
| 3.  | Pk  | Der Premiumkunde nennt gültige<br><br>Kundennummer, einen Liefertermin und<br><br>Adresse. |
| 4.  | Vk  | Verkäufer erfasst die Daten und berechnet den<br><br>Preis.                                |
| 5.  | Pk  | Der Kunde bezahlt bar (Anwendungsfall<br><br>Barbezahlung).                                |
| 6.  | Ku  | Der Kurier liefert die gewünschten Artikel am<br><br>definierten Datum.                    |

| Zu 1. | Pk  | Der Kunde nennt die gewünschten Artikel<br>telefonisch.                                        |
| ----- | --- | ---------------------------------------------------------------------------------------------- |
| Zu 5. | Vk  | Der Kunde nennt seine Kreditkartennummer an Telefon (Anwendungsfall Bezahlung mit Kreditkarte) |
| Zu 5. | Vk  | Der Kunde legt seine Kreditkarte vor (Anwendungsfall Bezahlung mit Kreditkarte)                |
| Zu 5. | Vk  | Der Kunde zahlt beim Eintreffen der Ware (Anwendungsfall Barzahlung)                           |

| Zu 5. | Vk  | Artikel sind nicht in ausreichender Menge vorhanden, können aber rechtzeitig geliefert werden. Die Chefin muss eine Bestellung veranlassen (Anwendungsfall Bestellung beim Lieferanten) |
| ----- | --- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |

|   |   |   |
|---|---|---|
|Zu 2.|Vk|Artikel ist nicht in ausreichender Menge<br><br>vorhanden, kann auch nicht rechtzeitig geliefert<br><br>werden; Anwendungsfall wird abgebrochen,<br><br>aber Bestellung trotzdem vorgenommen (Anwendungsfall Bestellung beim Lieferanten)|
|Zu 3.|Pk|Kunde nennt ungültige Kundennummer;<br><br>Anwendungsfall wird abgebrochen|
|Zu 5.|Pk|Der Kunde bezahlt nicht rechtzeitig; Lieferung<br><br>findet nicht statt bzw. wird im Falle einer<br><br>fehlgeschlagenen Bezahlung vor Ort wieder<br><br>mitgenommen|