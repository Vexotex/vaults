[[05aKuB-Turingmaschinen.pdf#page=9&selection=0,0,0,16|05aKuB-Turingmaschinen, page 9]]

**R**andom **A**ccess **M**aschine
- Programm
- b - Befehlszähler
- c(0) - Akkumulator

## Befehlssatz
LOAD, Store, ADD, SUB, DIV
INLOAD, INDSTORE, INADD, INDSUB, INDDIV
CLOAD, CADD, CSUB, CDIV
GOTO, IF c(0)? x THEN GOTO, END

## Erläuterung
LOAD i : c(0) := c(i), b := b+1;
STORE i : c(i) := c(0), b := b+1;
ADD i : c(0) := c(0) + c(i), b := b+1;
INDLOAD i : c(0) := c(c(i)), b := b+1; // pointer
CLOAD i : c(0) := i, b := b+1;
GOTO i : b := j

## Funktionsweise
- Der Speicher der RAM ist unbeschränkt und besteht aus den Registern c(0), c(1), c(2), c(3), . . . 
- Die Inhalte der Register sind natürliche Zahlen, die beliebig groß sein können.
- Die Eingabe sind ebenfalls natürliche Zahlen, initial in den ersten Registern abgespeichert. 
- Der Befehlszähler startet mit dem Wert 1. Ausgeführt wird jeweils der Befehl in derjenigen Zeile auf den der Befehlszähler verweist.
- Die Rechnung stoppt sobald der Befehl END erreicht ist.
- Die Ausgabe befindet sich nach dem Stoppen ebenfalls in den ersten Registern. 

## Diskussion der Registermaschine
- Auf der Registermaschine können wir offensichtlich alle Befehle wie beispielsweise Schleifen und Rekursionen, die wir von Programmiersprachen gewohnt sind, realisieren. 
- Für die Bemessung der Rechenzeit gibt es unterschiedliche Modelle, z.B. 
	- Uniformes Kostenmaß: Jeder Schritt zählt eine Zeiteinheit. 
	- Logarithmisches Kostenmaß: Die Laufzeitkosten eines Schrittes sind proportional zur binären Länge der Zahlen in den angesprochenen Registern. 
- Aus Sicht eines Programmierers mag die Registermaschine recht elementar aussehen. Aus Sicht eines mathematischen Modells ist sie relativ komplex. 
- Um das Argumentieren zu erleichtern, betrachten wir ein noch elementareres Maschinenmodell, das 1936 von Alan Turing eingeführt wurde.
