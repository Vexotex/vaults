#include "C3b.h"

enum Richtung {
	Rechts = 0,
	Links = 1,
	Unbekannt = 2
};

static int kanal_a;
static int kanal_b;

static TaskHandle_t simu_Handle = NULL;
static TaskHandle_t doppel_Handle = NULL;
static TaskHandle_t ausgabe_Handle = NULL;

static uint16_t state = 0;
static int32_t pos = 0;
static enum Richtung dir = 2;
static int32_t error = 0;

static void sensor_simu()
{
	//0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0 E 0
	int sensor_a[] = {0,1,1,0,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0};
	int sensor_b[] = {0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,0};
	int index;
	while(1){
	for (index = 0; index < 20; index++)
	{
		kanal_a = sensor_a[index];
		kanal_b = sensor_b[index];
		vTaskDelay(1000);
	}
}}

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
	char* dirstring = "Unbekannt";

	for(;;){
	switch (dir){
		case 0:
			dirstring = "Rechts   ";
			break;
		case 1:
			dirstring = "Links    ";
			break;
		case 2:
			dirstring = "Unbekannt";
			break;
	}
	printf("State: %d \t Position: %d \t Richtung: %s \t Fehler: %d                    \r", (int)state, (int)pos, dirstring, (int)error);
	vTaskDelay(500);
}}

void start_C3b(){
	printf("Start Aufgabe C3b");
	xTaskCreate(doppelpuls	, "", 256, NULL, 30, &doppel_Handle		);
	xTaskCreate(sensor_simu	, "", 256, NULL, 30, &simu_Handle		);
	xTaskCreate(ausgabe		, "", 256, NULL, 30, &ausgabe_Handle	);
	for(;;){

	}
}
