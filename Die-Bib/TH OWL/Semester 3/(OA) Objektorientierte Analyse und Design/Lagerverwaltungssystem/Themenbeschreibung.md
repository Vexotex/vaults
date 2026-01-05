# Projekt 3: Lagerverwaltung

Wir designen die Lagerverwaltung eines Großhändlers. Der Großhändler besitzt mehrere Lager. Wir wollen sowohl eine zentrale Bestandsaufnahme als auch eine Bestandsaufnahme an jedem Standort, so dass die Systeme autark funktionieren können.

Zentral soll nur gespeichert werden, wie viele Gegenstände von welcher Art an welchem Standort vorhanden sind.

In jedem Standort soll außerdem die Position des Gegenstandes im Lager angezeigt werden. Es kann davon ausgegangen werden, dass jedes Lager die gleiche Struktur hat.

Das System soll die Möglichkeit haben, anfragen bearbeiten zu können, es sollen also Gegenstände eingelagert, ausgelagert und angezeigt werden können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden.

Weiterhin soll jeder Zugriff und jede Entnahme von Gegenständen gespeichert werden. Weiterhin soll es die Möglichkeit geben, automatisch Auswertungen einzelner Artikel zu erstellen: Wie viele Verkäufe, etc. Das System soll dann in der Lage sein, Artikel, die nicht häufig angefragt werden, nicht mehr an allen Standorten vorzuhalten oder zu entscheiden, dass ein Artikel an mehreren Standorten vorgehalten werden soll. Hierzu soll es die passende Abteilung per Email informieren oder automatisch für andere Standorte zu bestellen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.



# Eigene Version

Ein Großhändler mit mehreren Lagerstandorten benötigt ein verteiltes Lagerverwaltungssystem, dass zu lokaler, autarker Bestandsverwaltung auch eine zusammengefasste Übersicht über alle Standorte bietet.

Die Mitarbeiter sollen in der Lage sein lokal vorhandene Artikel einzulagern, auszulagern und anzeigen zu können. Falls ein Gegenstand nicht verfügbar ist, soll an anderen Standorten angefragt werden. Jeder dieser Zugriffe soll protokolliert werden.
Das System soll Auswertungen erstellen können: Wie viele Verkäufe, etc.. Darauf hin soll das System standortübergreifend entscheiden, ob ein Artikel mehr, weniger oder gar nicht vorgehalten werden soll und die Zuständige Abteilung per E-Mail informieren oder automatisch Bestellungen tätigen.

Gegenstände können ein Verfallsdatum haben.

Weiterhin soll es die Möglichkeit geben, automatisch neue Waren zu bestellen. Hierzu muss bekannt sein, wo diese bestellt werden können, und wann dies erfolgen soll.
