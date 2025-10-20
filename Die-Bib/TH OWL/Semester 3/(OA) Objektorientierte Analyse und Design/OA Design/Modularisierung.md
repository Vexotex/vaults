Am Anfang wollen wir die Software in verschiedene Teile unterteilen, die Unabhängig voneinander funktionieren. Diese Teilstücke nennen wir Module.

Einzelne Module sollten hierbei klar definierte Schnittstellen besitzen, über die sie Informationen austauschen.

Es sollte hierbei beachtet werden, dass zwei Module in fast jedem Projekt vorkommen: ‘common’ und ‘[[UI]]’ oder ‘[[API]]’

## Auswahl
Die Auswahl des Frontends (UI/API) ergibt sich normalerweise natürlich aus dem Anwendungsfall.

In dem Beispiel von Adas Blumenladen benötigen wir eine GUI, welche von allen Akteuren bedient werden kann, und automatisch alle möglichen Aktionen bereitstellt.

Dies kann in Form von Bildern geschehen. Heute ist es auch oft üblich, ein nicht-funktionales, aber interaktives GUI-Mock bereit zu stellen.
[[Main menu Adas Blumenladen]]

