
# (55 Punkte)

## Beschreibung
## code
```c
long DIGI_OUT 0xFFFA0000 // Addresse von Warnlampe

int state = 0;
int nextState = 0;
long int aktuell = 0;
long int prev = 0;
long int timeAlt = 0;
long int timeNeu = 0;
float velocity = 0;
int counter = 0;

int position = 0;
int max = 0;
float step = 0.2; // Schrittgroesse

void * oPtr = (void*) DIGI_OUT; 


// --- StateTask--- (wird vom Callback Resumed)
while (1) {
	vTaskSuspend(NULL);
	
	timeAlt = timeNeu;
	timeNeu = (long int) clock();
	prev = aktuell;
	aktuell = timeNeu - timeAlt;
	
	switch (state){
		case 0: // Warte auf erste Referenz	
			if ( aktuell <= 0.5 * prev ){ // 50% Fehlertoleranz zum vorgänger 
				nextState = 1;
				counter = 0;
			}
			if ( counter > 8 ){
				nextState = 3;
			}
			counter++;
			break;
		
		case 1: // Warte auf zweite Referenz
			if ( aktuell <= 0.5 * prev ){ 
				nextState = 2;
				position = counter * step;
				max = counter * step;
			}
			break;
		
		case 2: // laufender Betrieb
			if ( diretion = 1 ){ // Richtung + 
				position += step;
			} else {
				position -= step;
			}
			velocity = step / (aktuell * 1000) // m/s
			
			if ( position > max || pos < 0 ){ // ausserhalb des Arbeitsbereichs
				*oPtr = 0x0001; // Licht an
			} else {
				*oPtr = 0x0000; // Licht aus
			}
			break;
			
		case 3: // Error, wenn aus Ruhezone mehr als 8 Schritte
			
		
	}
	state = nextState;
}
```