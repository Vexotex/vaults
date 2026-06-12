#include "C1a.h"
#include <ctype.h>

static char *eingabe_str;
static TaskHandle_t eingabe_Handle = NULL;
static TaskHandle_t ausgabe_Handle = NULL;

static void ausgabe()
{
  vTaskSuspend(NULL);
  printf("\nIhre Texteingabe lautet: %s\n",eingabe_str);
  printf("\nVielen Dank und auf Wiedersehen!\n");
  vTaskDelete(NULL);
}

static void eingabe()
{
	printf("Bitte geben Sie ihren Text ein \n");
	printf("-> ");

	for(;;)
	{
		scanf("%s",eingabe_str);

		if (isalpha((int)eingabe_str[0]))
		{
			vTaskResume(ausgabe_Handle);
			break;
		}
		else
		{
			printf("Erneute Eingabe, bitte mit einem Buchstaben beginnen\n");
			printf("-> ");
			eingabe_str = "\0";
		}
	}

	free(eingabe_str);
	vTaskDelete(NULL);
}

void start_C1a(){
	printf("Aufgabe C1a\n\n");
	eingabe_str = (char *) malloc(20*sizeof(char));
	xTaskCreate(ausgabe, "ausgabe", 128, NULL, 21, &ausgabe_Handle);
	// scanf() verbraucht viel Speicher, deshalb wird mehr Heap zugewiesen
	xTaskCreate(eingabe, "eingabe", 256, NULL, 20, &eingabe_Handle);
	for(;;);
}
