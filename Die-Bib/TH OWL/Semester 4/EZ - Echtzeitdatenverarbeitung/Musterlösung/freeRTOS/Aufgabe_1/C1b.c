#include "C1b.h"
#include <ctype.h>

static char *eingabe_str;
static TaskHandle_t eingabe_Handle = NULL;
static TaskHandle_t ausgabe_Handle = NULL;

static int counter = 0;

static void ausgabe(void*)
{
  for(;;){
	  vTaskSuspend(NULL);
	  printf("Ihre Texteingabe lautet: %s\n\n",eingabe_str);
	  printf("Aktuelle Anzahl Schleifendurchlaeufe: %d\n",counter);
  }
}

static void eingabe(void*)
{
	for(;;){
		printf("Bitte geben Sie ihren Text ein \n");
		printf("-> ");

		scanf("%[^\r]",eingabe_str);

		if (isalpha((int)eingabe_str[0])==0){
			printf("Erneute Eingabe, bitte mit einem Buchstaben beginnen\n\n");
			printf("-> ");
			eingabe_str = "\0";
			continue;
		}
		if (eingabe_str[0] == 'X')
		{
			printf("\nAbbruch der Eingabe\n");
			printf("Vielen Dank und auf Wiedersehen!\n");
			break;
		}
		counter++;
		vTaskResume(ausgabe_Handle);
	}
	vTaskDelete(ausgabe_Handle);
	free(eingabe_str);
	vTaskDelete(NULL);
}

void start_C1b(){
	printf("Aufgabe C1b\n\n");
	eingabe_str = (char *) malloc(20*sizeof(char));
	xTaskCreate(ausgabe, "ausgabe", 128, NULL, 21, &ausgabe_Handle);
	xTaskCreate(eingabe, "eingabe", 256, NULL, 20, &eingabe_Handle);
	for(;;){

	}
}
