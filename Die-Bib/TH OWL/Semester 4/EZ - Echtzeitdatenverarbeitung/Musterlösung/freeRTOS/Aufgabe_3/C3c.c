#include "C3b.h"

#define LEDMASK 0x000000FF

static int kanal_a = 0;
static int kanal_b = 0;

static TaskHandle_t simu_Handle    = NULL;
static TaskHandle_t doppel_Handle  = NULL;
static TaskHandle_t ausgabe_Handle = NULL;

static uint16_t state = 0;
static int32_t pos    = 0;
static int32_t error  = 0;

static void sensor_simu(){
	               // 0  1  2  3  4  5  6  7  8  9 10  9  8  7  6  5  4  3  2  1  E  E
	int sensor_a[] = {0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
	int sensor_b[] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0};
	int index;
	while(1){
		for (index = 0; index < (sizeof(sensor_a)/sizeof(sensor_a[0])); index++){
			kanal_a = sensor_a[index];
			kanal_b = sensor_b[index];
			vTaskDelay(1000);
		}
	}
}

static void doppelpuls(){
	for(;;){
		int input = (kanal_a + (kanal_b << 1));
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
		vTaskDelay(1);
	}
}


static void ausgabe(){
	char* 	dirstring = "Unbekannt";
	int32_t    old_err      = 0;
	TickType_t LastWakeTime = xTaskGetTickCount();
	TickType_t xFrequency   = pdMS_TO_TICKS(500);
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
		if      (pos<=0){ledposval = (1 << 0  );}
		else if (pos>=7){ledposval = (1 << 7  );}
		else            {ledposval = (1 << pos);}

		long int ledval = ((ledposval << 8) + (1 << state)) ^ LEDMASK;

		GPIOC->ODR = ledval;

		vTaskDelayUntil(&LastWakeTime, xFrequency);
	}
}

void start_C3c(){
	printf("Start Aufgabe C3c\n\n");
	xTaskCreate(doppelpuls	, "", 256, NULL, 30, &doppel_Handle		);
	xTaskCreate(sensor_simu	, "", 256, NULL, 30, &simu_Handle		);
	xTaskCreate(ausgabe		, "", 256, NULL, 30, &ausgabe_Handle	);
	vTaskDelete(NULL);
}
