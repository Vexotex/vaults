# Vorlesung
- 15.04.2026
- [[EZ_00_Organisation.pdf]]
- [[EZ_01_Grundlagen.pdf]]
- [[EZ_02_Asynchrone Programmierung.pdf]]
- [[EZ_03_1_C-Programmierung.pdf]]
- [[EZ_03_2_Peripherie.pdf]]
- [[EZ_03_4_Zustandsgraph Linearachse.pdf]]
- [[EZ_04_Einplanung_Teil1.pdf]]
- [[EZ_04_Einplanung_Teil2.pdf]]
- [[EZ_05_Semaphoren.pdf]]
- [[EZ_06_SPS_1_Synchrone Programmierung.pdf]]
- [[EZ_06_SPS_2_Virtueller Controller.pdf]]
- [[EZ_06_SPS_3_IEC 61131.pdf]]
- [[EZ_06_SPS_4_Beispiel Verkehrsampel.pdf]]
- [[EZ_07_I_Security Einfuehrung.pdf]]
- [[EZ_09_Ueberblick sichere Softwareentwicklung.pdf]]
- [[EZ_08_Verwaltungsschale.pdf]]


# Übung
- [[Einrichtung_EZ_Praktikum.pdf]]
- [[Aufgaben_EZ_Praktikum.pdf]]
- [[PCWorx_Konfig_und_erstes_Programm.pdf]]
- [[produktionsmodell_sensoren_aktoren_ez_sps.pdf]]

# Musterlösungen


# Referenzen
- [[161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf]]
- [[um1725-description-of-stm32f4-hal-and-lowlayer-drivers-stmicroelectronics.pdf]]
- [[Noctua_PWM_specifications_white_paper.pdf]]



# Klausur
- ein PDF zum mitnehmen
- E-Klausurpos
- ähnlich wie PE


# Musterklausur
## Aufgabe 2 - C-Prog
### Beschreibung
Ein Automatisierungsvorhaben wird mit Hilfe von Prozessrechnern und dem Betriebssystem freeRTOS realisiert. Die Programme sind in der Programmiersprache C geschrieben. Es wird angenommen, dass die gleichen Randbedingungen gelten wie für die in den Übungen benutzten Rechner.

Als Teilproblem eines Projektes zur Automatisierung von Fertigungsmaschinen sollen Winkelposition und Drehrichtung einer Welle an andere Programme gegeben werden.

Zur Positionsbestimmung wird eine Zahnscheibe abgetastet. Die Zähne 1 bis n haben gleichmäßigen Abstand voneinander, die Startposition ist durch den verlängerten 1. Zahn gekennzeichnet. Die vordere Flanke jedes Zahnes (Unterbrechung der Lichtschranken) kann als Interrupt im Rechner genutzt werden (`ZAHN_EVENT_1 an GPIO 1, ZAHN_EVENT_2 an GPIO 2, START_EVENT an GPIO 4`). Die Drehrichtung kann mit Hilfe der nebeneinanderliegenden Lichtschranken (Sensor1, Sensor2) bestimmt werden, mit Sensor3 wird eine definierte Anfangsposition auf dem Umfang festgelegt.

### Teilaufgabe 1.1  
Da das Programm für Maschinen mit unterschiedlichen Zahnscheiben eingesetzt wird, ist die Anzahl der Zähne nicht bekannt. Als Teilproblem der Automatisierung soll zunächst die Lernphase betrachtet werden, bei der die Anzahl der Zähne bestimmt wird.

Schreiben Sie ein Programm in 'C', das die Anzahl der Zähne beim Start des Programms bestimmt und in der Modulvariablen `anzahl_zaehne` für andere Tasks zur Verfügung stellt. Vereinfachung: in der gesamten Lernphase dreht sich die Welle in einer Richtung.

### Teilaufgabe 2.2

Ihr Programm soll im laufenden Betrieb die Position und die Drehrichtung erkennen. Die aktuelle Position der Welle soll als Nummer des zuletzt erkannten Zahnes in die Modulvariable `int nummer_zahn` eingetragen werden, die Drehrichtung (rechts = 0, links = 1) in die Modulvariable `int richtung`. Denken Sie daran, dass je nach Startzeitpunkt der Messung in beiden Richtungen Sensor1 zuerst und Sensor2 danach auslösen kann.

Die Programme sollen für variable Geschwindigkeit und beide Richtungen funktionieren. Zur Vereinfachung wird das Umschalten zwischen den Drehrichtungen nicht betrachtet. Es wird vorausgesetzt, dass keine beliebig großen Beschleunigungen auftreten. Außerdem ist sichergestellt, dass die Events in einem so großen Abstand ausgelöst werden, dass die interne Uhr für die Zeitbestimmung benutzt werden kann. Die aktuelle Uhrzeit in Millisekunden ab 0 Uhr wird geliefert durch die Library-Funktion `clock()` . Beispiel: Falls Sie eine Variable definiert haben als `long int time1`; erhalten Sie die Uhrzeit durch `time1 = (long int) clock();` .

### Teilaufgabe 1.3

Falls Sensor3 zur Laufzeit ausfällt, soll dies erkannt werden und die globale Variable `error` den Wert -1 als Kennzeichnung für den Fehler erhalten. 

Hinweis: Sie können für die Teile a, b und c mehrere Programme schreiben oder alle Aufgabenteile in einem Programm lösen (bitte entsprechend kommentieren).
### Code
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
				nummer_zahn--;
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
				nummer_zahn++;
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

