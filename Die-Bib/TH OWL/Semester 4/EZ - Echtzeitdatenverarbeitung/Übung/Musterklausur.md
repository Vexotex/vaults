# Aufgabe 1 - IEC61131 (30 Punkte)
## Beschreibung
Ein Automatisierungsvorhaben wird mit Hilfe von Phoenix-SPS Systemen mit dem Programmiersystem PCWORX realisiert. Die Programme sollen in 'Structured  
Text' geschrieben werden. Es wird angenommen, dass die gleichen Randbedingungen gelten wie für die in den praktischen Übungen benutzten SPS Systeme.

Als Teilproblem in einer Anlage wird ein Modul zum Ausschleusen von Werkstücken betrachtet, die auf einem Förderband transportiert werden. Das Modul ist nicht identisch mit dem Modul des Produktionsmodells. Aufgabe ist es, jedes zweite Werkstück auszuschleusen.

Mit Lichtschranke 1 können Sie feststellen, ob sich ein Werkstück vor der Weiche befindet (Werkstück vorhanden bedeutet 'kein Licht' ).

Die Weiche besteht aus einer Düse, mit der die Werkstücke angeblasen werden, um sie mit Druckluft auf die Ausschleuse-Rampe zu schieben. Von Sensor1 bis Aktor1 bewegt sich das Werkstück in 5 Sekunden. Der Druckluftimpuls soll 0,6 Sekunden dauern (true: Druckluft an, false: Druckluft aus).

Falls das Werkstück spätestens 2 Sekunden nach dem Druckluftimpuls nicht von Sensor2 erfasst wird, soll die Warnleuchte blinken.

Wenn die Ausschleuse-Rampe mit Werkstücken gefüllt ist (d.h. die Werkstücke stauen sich bis zur Lichtschranke 2), soll nicht mehr ausgeschleust werden und die Warnlampe am Digitalausgang 2 soll leuchten. Denken Sie daran, dass die Lichtschranke 2 bei jedem ausgeschleusten Werkstück unterbrochen wird, unabhängig vom Füllstand der Rampe.

Die Anzahl der ausgeschleusten Werkstücke soll in der globalen Variablen `'anzahl_werkstuecke'` für andere Tasks abgelegt werden. 

Vereinfachungen

Das Band läuft dauerhaft mit konstanter Geschwindigkeit. 

Die Werkstücke liegen in so großem Abstand auf dem Band, dass ein Ausschleusevorgang beendet ist, wenn das nächste Werkstück erfasst wird.

Der Ablauf nach dem Störfall (Warnleuchte blinkt) wird nicht betrachtet.

Falls Sie für die Steuerung weitere Zeitangaben benötigen, können Sie diese für die Klausur selbst wählen (in einem sinnvollen Verhältnis zu den gegebenen Zeiten).
## Code
```StructuredText
(* init *)
is2te := false;
counter := 0;
state := 0;

aktor1 := false;
aktor2 := false;

blinken := false;
blink := false;
leuchten := false;

anzahl_werkstuecke := 0;


(* statemachine - 100ms *)
CASE state OF
	0: (* Warte auf erste Lichtschranke. Fahre nur bei jedem 2ten fort*)
		IF sensor1 = false THEN
			is2te := not is2te;
			
			IF is2te = true
				state := 1;
		END_IF
		
	
	1: (* Warte 5 Sekunden Druckluft an *)
		IF counter >= 50 THEN
			state := 2;
			aktor1 := true;
			counter := 0;
		END_IF;
		
		counter := counter + 1;
	
	2: (* nach 0,6 sekunden wieder aus *)
		IF counter >= 6 THEN
			state := 3;
			aktor1 := false;
			counter := 0;
		END_IF;
		
		counter := counter + 1;

	3: (* Auf Lichtschranke 2 warten *)
		IF sensor2 = false THEN
			state := 4;
			blinken := false
			counter := 0;
			anzahl_werkstuecke = anzahl_werkstuecke + 1; 
		ELSEIF counter >= 20 THEN
			blinken := true;
		END_IF;
		
		counter := counter + 1;
	
	4: (* Rampe voll? Wenn Lichtschranke länger als 1 sekunde 'false' *)
		IF sensor2 = true THEN
			state := 0;
			leuchten := false
			counter := 0;
		ELSEIF counter >= 10 THEN
			leuchten := true;
			counter := 10;
		END_IF;
		
		counter := counter + 1;
	
END_CASE;


(* Warnleuchte - 100ms *)
IF blinken = true THEN
	blink := not blink;
	aktor2 := blink;
ELSEIF leuchten = true THEN
	aktor2 := true;
ELSE
	aktor2 := false;
	blink := false;
END_IF
```



# Aufgabe 2 - C-Programmierung (50 Punkte)
## Beschreibung
Ein Automatisierungsvorhaben wird mit Hilfe von Prozessrechnern und dem Betriebssystem freeRTOS realisiert. Die Programme sind in der Programmiersprache C geschrieben. Es wird angenommen, dass die gleichen Randbedingungen gelten wie für die in den Übungen benutzten Rechner.

Als Teilproblem eines Projektes zur Automatisierung von Fertigungsmaschinen sollen Winkelposition und Drehrichtung einer Welle an andere Programme gegeben werden.

Zur Positionsbestimmung wird eine Zahnscheibe abgetastet. Die Zähne 1 bis n haben gleichmäßigen Abstand voneinander, die Startposition ist durch den verlängerten 1. Zahn gekennzeichnet. Die vordere Flanke jedes Zahnes (Unterbrechung der Lichtschranken) kann als Interrupt im Rechner genutzt werden (`ZAHN_EVENT_1 an GPIO 1, ZAHN_EVENT_2 an GPIO 2, START_EVENT an GPIO 4`). Die Drehrichtung kann mit Hilfe der nebeneinanderliegenden Lichtschranken (Sensor1, Sensor2) bestimmt werden, mit Sensor3 wird eine definierte Anfangsposition auf dem Umfang festgelegt.

## Teilaufgabe 1.1  
Da das Programm für Maschinen mit unterschiedlichen Zahnscheiben eingesetzt wird, ist die Anzahl der Zähne nicht bekannt. Als Teilproblem der Automatisierung soll zunächst die Lernphase betrachtet werden, bei der die Anzahl der Zähne bestimmt wird.

Schreiben Sie ein Programm in 'C', das die Anzahl der Zähne beim Start des Programms bestimmt und in der Modulvariablen `anzahl_zaehne` für andere Tasks zur Verfügung stellt. Vereinfachung: in der gesamten Lernphase dreht sich die Welle in einer Richtung.

## Teilaufgabe 2.2

Ihr Programm soll im laufenden Betrieb die Position und die Drehrichtung erkennen. Die aktuelle Position der Welle soll als Nummer des zuletzt erkannten Zahnes in die Modulvariable `int nummer_zahn` eingetragen werden, die Drehrichtung (rechts = 0, links = 1) in die Modulvariable `int richtung`. Denken Sie daran, dass je nach Startzeitpunkt der Messung in beiden Richtungen Sensor1 zuerst und Sensor2 danach auslösen kann.

Die Programme sollen für variable Geschwindigkeit und beide Richtungen funktionieren. Zur Vereinfachung wird das Umschalten zwischen den Drehrichtungen nicht betrachtet. Es wird vorausgesetzt, dass keine beliebig großen Beschleunigungen auftreten. Außerdem ist sichergestellt, dass die Events in einem so großen Abstand ausgelöst werden, dass die interne Uhr für die Zeitbestimmung benutzt werden kann. Die aktuelle Uhrzeit in Millisekunden ab 0 Uhr wird geliefert durch die Library-Funktion `clock()` . Beispiel: Falls Sie eine Variable definiert haben als `long int time1`; erhalten Sie die Uhrzeit durch `time1 = (long int) clock();` .

## Teilaufgabe 1.3

Falls Sensor3 zur Laufzeit ausfällt, soll dies erkannt werden und die globale Variable `error` den Wert -1 als Kennzeichnung für den Fehler erhalten. 

Hinweis: Sie können für die Teile a, b und c mehrere Programme schreiben oder alle Aufgabenteile in einem Programm lösen (bitte entsprechend kommentieren).
## Code
```c
// ---Globale Variabeln---

// input Data Register (Verfügbarkeit angenommen)
int GPIO1 = 0x1 & (GPIOptr->idr << 0);
int GPIO2 = 0x1 & (GPIOptr->idr << 1);
int GPIO4 = 0x1 & (GPIOptr->idr << 3);

// laufender Betrieb
int LastState = 0;
int State = 0;
int NextState = 0;
int nummer_zahn = 0;
int richtung = 0;

// Lernphase
int LernState = 0;
int nextState = 0;
int anzahl_zaehne = 0;#

// Fehlererkennung
int error = 0;

// ---Callback---
void HAL_GPIO_EXTI_CALLBACK (uint GPIO_Pin) {
	Switch ( GPIO_Pin ){
		case 1<<0:
			ISR1()
			break;
		case 1<<1:
			ISR2()
			break;
		case 1<<3:
			ISR4()
			break;
	}
}

// ISR
void ISR1(){
	GPIO1 = 0x1 & (GPIOptr->idr << 0); // neuen Wert im Register einlesen
	
	vTaskResume(LernphaseHandel);
	vTaskResume(BetriebHandel);
}
void ISR2(){
	GPIO2 = 0x1 & (GPIOptr->idr << 1);
	
	vTaskResume(BetriebHandel);
}
void ISR4(){
	GPIO4 = 0x1 & (GPIOptr->idr << 3);
	
	vTaskResume(LernphaseHandel);
}


// ---Lernphase/Fehlererkennung---

while (1) {
	vTaskSuspend(NULL);
	switch (LernState){
		case 0: // Warte auf erste Referenz
			if (GPIO4 = 0){
				nextLernState = 1;
			}
			break;
		
		case 1: // Warte auf zweite Referenz
			if (GPIO4 = 0){
				nextLernState = 2;
				nextLernState = 2;	
			}
			anzahl_zaehne++;
			break;
		
		case 2:
			if (GPIO4 = 0 && (nummer_zahn % anzahl_zaehne) !=0){
				error = -1;
			}
			break;
	}
	LernState = nextLernState;
}


// ---laufender Betrieb---

while (1){
	vTaskSuspend(NULL);
	switch (State) {
		case 0: // 00
			if (GPIO1 = 1){
				NextState = 2;
				richtung = 0; // rechts
				nummer_zahn++;
			}
			if (GPIO2 = 1){
				NextState = 1;
				richtung = 1; // links
				nummer_zahn--;
			}
			break;
			
		case 1: // 01
			if (GPIO1 = 0){
				NextState = 0;
				richtung = 1;
				nummer_zahn++;
			}
			if (GPIO2 = 1){
				NextState = 3;
				richtung = 0;
			}
			break;
			
		case 2: // 10
			if (GPIO1 = 1){
				NextState = 3;
				richtung = 0;
			}
			if (GPIO2 = 0){
				NextState = 0;
				richtung = 1;
				nummer_zahn--;
			}
			break;
			
		case 3: // 11
			if (GPIO1 = 0){
				NextState = 2;
				richtung = 1;
			}
			if (GPIO2 = 0){
				NextState = 1;
				richtung = 0;
			}
			break;
	}
	State = NextState;
}
```

