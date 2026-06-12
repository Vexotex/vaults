#include "C3a.h"

static int kanal_a;
static int kanal_b;

static uint16_t state = 0;
static int32_t 	pos   = 0;
static int32_t 	error = 0;

static TaskHandle_t doppel_Handle = NULL;

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

void start_C3a(){
	printf("Aufgabe C3a\n\n");
	xTaskCreate(doppelpuls, "", 256, NULL, 30, &doppel_Handle);
	vTaskDelete(NULL);
}
