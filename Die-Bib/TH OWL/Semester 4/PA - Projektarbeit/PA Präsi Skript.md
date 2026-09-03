# Skript: AAS, BaSyx und Integration Layer

## Folie 1 — Einordnung

- Übergabe von Stefan: „Das NodeSet lebt jetzt im OPC-UA-Server der Steuerung."
- Mein Teil: dasselbe NodeSet nutzen, um automatisiert eine Verwaltungsschale zu erzeugen
- Zwei getrennte Programme, unterschiedliche Lebensdauer:
    - `nodeset_to_aas.py` → läuft einmal, erzeugt Struktur
    - `integration_layer.py` → läuft dauerhaft, hält Werte synchron
- Betonen: beide nutzen denselben Parser, keine zweite Datenquelle → Konsistenz ist strukturell garantiert, nicht nur "gepflegt"

---

## Folie 2 — Parser: Vom NodeSet zum generischen Baum

- Kernidee vorab: Parser soll nicht wissen, was eine Anlage "ist" – nur wie ein NodeSet aufgebaut ist
- Nur ein einziger Codewert ist hart verankert: der Name „ProductionModule" als Root
- Alles darunter ergibt sich rein aus der Struktur, nicht aus Namenslisten
- Praktischer Nutzen, den man erwähnen kann: Wenn Sait im Modell eine neue Gruppe oder Kategorie einführt, muss am Parser nichts geändert werden
- Kurzer Kontrast zur Vorversion: früher waren Kategorienamen wie „Sensors" fest im Code verankert – das war fragil bei Umbenennungen

---

## Folie 3 — Mapping NodeSet → AAS

- Bewusste Trennung in zwei Dateien – kein Zufall, sondern Architekturentscheidung
- Analogie, die gut ankommt: „Der Parser ist der Übersetzer vom NodeSet in eine neutrale Sprache. Der Builder übersetzt diese neutrale Sprache erst in AAS-Vokabular."
- Vorteil in eigenen Worten: Wenn sich später die AAS-Bibliothek ändert oder ein anderes Zielformat gebraucht wird, muss nur der Builder angepasst werden
- Rekursion kurz erklären: eine Funktion ruft sich für verschachtelte Gruppen selbst wieder auf – dadurch ist die Tiefe der Verschachtelung nicht im Code begrenzt, sondern folgt einfach dem NodeSet

---

## Folie 4 — AAS-JSON-Struktur

- **basyx-python-sdk** : eine Python-Bibliothek, die den AAS-Standard als Klassen bereitstellt
	- man muss also nicht selbst JSON von Hand bauen
- Am Beispiel HeightMeasurement zeigen (falls Folie/Code sichtbar): eine Operation (ReadHeight) und zwei Properties mit unterschiedlichen Typen
- Typtabelle erwähnen: OPC-UA-Typen wie `Boolean`, `Double` werden über eine feste Tabelle in AAS-kompatible `xs:`-Typen übersetzt – bei unbekannten/strukturierten Typen wird bewusst ein Fehler geworfen statt stillschweigend falsch zu konvertieren
- ID-Schema kurz begründen: IDs werden aus den Namen im NodeSet abgeleitet, dadurch bleiben sie bei wiederholten Läufen stabil – wichtig für Wiederholbarkeit
    - Beispiel griffbereit haben: „Band1" → „HeightMeasurement" wird immer zu `urn:th-owl:festo-productionmodule:sm:band1:heightmeasurement`
    - Grund: macht die Idempotenz auf Folie 5 überhaupt erst möglich – gleicher Name, gleiche ID, bei jedem Lauf

---

## Folie 5 — Eclipse BaSyx

- Kurz sagen, was BaSyx ist: Referenzimplementierung der Verwaltungsschale, komplett über REST ansprechbar, läuft als Docker-Stack
    - REST kurz erklären, falls gefragt: ganz normale HTTP-Endpunkte (GET zum Lesen, POST zum Anlegen, PATCH zum Ändern einzelner Werte) – kein Spezialprotokoll, jede Ressource hat eine eigene URL
- Die vier Dienste kurz benennen und wozu sie da sind: Ablage der eigentlichen Objekte vs. zwei Registries nur für die Auffindbarkeit vs. GUI zur Kontrolle
- Wichtige Einschränkung hervorheben: Registries sind speicherresident – bei Neustart der Container sind Registrierungen weg, nicht aber die eigentlichen Objekte im Repository
- Konsequenz erklären: Weil BaSyx bei bereits existierenden Objekten mit „409 Conflict" antwortet statt einem echten Fehler, überspringt das Skript diese einfach – das macht mehrfaches Ausführen sicher (idempotent), aber auch: Änderungen am NodeSet wirken sich erst nach einem vollständigen Neustart des Stacks aus

---

## Folie 6 — Integration Layer: Zwei Richtungen

- Abgrenzung zum vorherigen Teil klarmachen: `nodeset_to_aas.py` baut nur einmal die Struktur, der Integration Layer hält sie zur Laufzeit lebendig
- Betonen, dass er dieselben Bausteine (Parser, ID-Schema) wiederverwendet – keine zweite Liste von Pfaden, die man getrennt pflegen müsste
- Auf das Diagramm verweisen und die beiden Pfeile kurz benennen, bevor man ins Detail geht

---

## Folie 7 — Richtung 1: Monitoring

- Erklären, was eine „Subscription" in OPC UA ist: statt ständig abzufragen, meldet sich der Server von selbst bei Änderungen
- Publish-Intervall von 500 ms erwähnen als Kompromiss zwischen Aktualität und Last
- Warum eine Queue dazwischen: falls BaSyx gerade langsam ist oder kurz nicht antwortet, blockiert das nicht die Anlagenverbindung – Änderungen stauen sich in der Queue statt verloren zu gehen oder die Subscription zu blockieren
- Kurzes Beispiel für die Typumwandlung: ein OPC-UA-Boolean wird zum String "true"/"false", weil BaSyx über PATCH textuelle Werte erwartet

---

## Folie 8 — Richtung 2: Skill-Invoke-Proxy

- Das Problem zuerst erklären, bevor man die Lösung zeigt: Ein Klick in der AAS-GUI auf einen Skill sendet ein POST an BaSyx – aber BaSyx selbst hat keine Verbindung zur SPS
- Lösung: ein eigener kleiner Server dazwischen, der genau diesen einen Aufruf abfängt und alles andere unverändert durchreicht (transparenter Proxy)
- Kurz den Trick erwähnen, wie sichergestellt wird, dass der Proxy überhaupt erreicht wird: die Registry wird beim Start so umgeschrieben, dass ihre Endpunkte auf den Proxy statt direkt auf BaSyx zeigen
- Optional: kurz erwähnen, dass Argumente dabei in beide Richtungen typkonvertiert werden (Python ↔ OPC-UA-Variant ↔ AAS-JSON)

---

## Folie 9 — Robustheit: Namespace-Remapping & Fehlerbehandlung

- Kurz erklären, warum das überhaupt ein Problem ist: OPC-UA-Namespaces bekommen beim Laden in CODESYS nicht zwangsläufig dieselbe Nummer wie beim Export aus SiOME
- Erste Lösung (Namespace-Mapping) als "rechnerische" Lösung beschreiben: Namen vergleichen, Nummern neu zuordnen
- Zweite Lösung (Browse-Map) als robusteren Fallback beschreiben: der tatsächliche Adressraum wird durchsucht und über lesbare Pfade wie „Band1.SignalTower.Commands.Green" identifiziert – funktioniert auch, wenn CODESYS intern andere Strukturen erzeugt
- Fehlerverhalten als bewusste Designentscheidung framen: lieber robust weiterlaufen (Retry, loggen) als bei jedem kleinen Problem abzustürzen – wichtig für einen Prozess, der dauerhaft laufen soll

---

## Folie 10 — Ergebnis / Demo

- Kurze Zusammenfassung in einem Satz: eine zentrale Änderung im NodeSet reicht, der Rest der Kette folgt automatisiert
- Falls Live-Demo: kurz ankündigen, was gezeigt wird (z. B. ein Sensorwert ändert sich in UaExpert und taucht in der BaSyx-GUI auf, oder ein Skill wird über die GUI ausgelöst)
- Falls kein Live-Demo möglich: auf Screenshot verweisen und kurz erklären, was zu sehen ist
- Guter Übergang zum Fazit/Abschluss der Gruppe, falls das direkt danach folgt