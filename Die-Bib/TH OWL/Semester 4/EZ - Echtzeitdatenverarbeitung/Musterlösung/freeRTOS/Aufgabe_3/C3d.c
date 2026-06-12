#include "C3d.h"

#define LEDMASK 0x000000FF
#define PIN_MASK 0x3

static TaskHandle_t ausgabe_Handle    = NULL;
static TaskHandle_t doppelpuls_Handle = NULL;

static uint16_t state = 0;
static int32_t  pos   = 0;
static int32_t  error = 0;

static void doppelpuls(void*){
	for(;;){
		long input = (((GPIOA->IDR) & PIN_MASK));
		switch(state){
			case 0:	// 0 0 R  -->  0 1 R | 1 0 L
				switch (input){
    				case 1:
    					state = 1;	pos++;		break;
    				case 2:
    					state = 7;	pos--;		break;
    				case 3:
    					state = 3;	error++;	break;
					}break;

			case 1:	// 0 1 R  -->  1 1 R | 0 0 L
	    		switch (input){
	          	  	case 0:
	          	  		state = 4;	pos--;		break;
	          	  	case 2:
	          	  		state = 2;	error++;	break;
	          	  	case 3:
	          	  		state = 2;	pos++;		break;
	    		}break;

	    	case 2: // 1 1 R  -->  1 0 R | 0 1 L
	    		switch (input){
	          	  	case 0:
	          	  		state = 0;	error++;	break;
	          	  	case 1:
	          	  		state = 5;	pos--;		break;
	          	  	case 2:
	          	  		state = 3;	pos++;		break;
	    		}break;

	    	case 3: // 1 0 R  -->  0 0 R | 1 1 L
	    		switch (input){
	    	  	  	case 0:
	    	  	  		state = 0;	pos++;		break;
	    	  	  	case 1:
	    	  	  		state = 1;	error++;	break;
	    	  	  	case 3:
	    	  	  		state = 6;	pos--;		break;
	    		}break;

	    	case 4: // 0 0 L  --> 1 0 L | 0 1 R
	    		switch (input){
					case 1:
						state = 1;	pos++;		break;
					case 2:
						state = 7;	pos--;		break;
					case 3:
						state = 6;	error++;	break;
	    		}break;

	    	case 5: // 0 1 L  --> 0 0 L | 1 1 R
	    		switch (input){
	      	  		case 0:
	      	  			state = 4;	pos--;		break;
	      	  		case 2:
	      	  			state = 7;	error++;	break;
	      	  		case 3:
	      	  			state = 2;	pos++;		break;
	    		}break;

	    	case 6: // 1 1 L  --> 0 1 L | 1 0 R
	    		switch (input){
	      	  		case 0:
	      	  			state = 4;	error++;	break;
	      	  		case 1:
	      	  			state = 5;	pos--;		break;
	      	  		case 2:
	      	  			state = 3;	pos++;		break;
	    		}break;

	    	case 7: // 1 0 L  --> 1 1 L | 0 0 R
	    		switch (input){
	    			case 0:
	    				state = 0;	pos++;		break;
	    			case 1:
	    				state = 5;	error++;	break;
	    			case 3:
	    				state = 6;	pos--;		break;
	    		}break;
	    	default:
		    						error++;	break;
		}
		if(pos <  0){pos =  0;}
		if(pos > 31){pos = 31;}
		vTaskDelay(1);
	}
}


static void ausgabe(){
	char* 	dirstring = "Unbekannt";
	int32_t    old_err      = 0;
	TickType_t LastWakeTime = xTaskGetTickCount();
	TickType_t xFrequency   = pdMS_TO_TICKS(50);
	for(;;){
		//Konsolenausgabe
		if(error > old_err){
			dirstring = "Unbekannt";
			old_err = error;
		}else if(state >= 4){
			dirstring = "Links";
		}else{
			dirstring = "Rechts";
		}
		printf("State: %d \t Position: %d \t Richtung: %s \t Fehler: %d                    \r", (int)state, (int)pos, dirstring, (int)error);

		// LED-Ausgabe
		long int ledposval = 0;
		if      (pos <=0  ){ledposval = (1 << 0        );}
		else if (pos >= 31){ledposval = (1 << 7        );}
		// Geteilt durch 4 da eine Raste 4 Positionswechsel bewirkt
		else               {ledposval = (1 << (pos / 4));}

		long int ledval = ((ledposval << 8) + (1 << state)) ^ LEDMASK;

		GPIOC->ODR = ledval;

		vTaskDelayUntil(&LastWakeTime, xFrequency);
	}
}

void start_C3d(){
	printf("Aufgabe C3d\n\n");
	xTaskCreate(doppelpuls, "", 128, NULL, 40, &doppelpuls_Handle);
	xTaskCreate(ausgabe, "", 128, NULL, 35, &ausgabe_Handle);
	vTaskDelete(NULL);
}
