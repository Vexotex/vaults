#include "C2a.h"

static TaskHandle_t start_Handle = NULL;
static TaskHandle_t t1_Handle = NULL;
static TaskHandle_t t2_Handle = NULL;
static TaskHandle_t t3_Handle = NULL;
static TaskHandle_t t4_Handle = NULL;
static TaskHandle_t t5_Handle = NULL;

// Verändern der Reihenfolge ändert Ausgabe
static void start(){
	vTaskResume(t1_Handle);
	vTaskResume(t2_Handle);
	vTaskResume(t3_Handle);
	vTaskResume(t4_Handle);
	vTaskResume(t5_Handle);
	vTaskDelete(NULL);
}

static void t1(){
	vTaskSuspend(NULL);
	printf("Task 1 \n");
	vTaskDelete(NULL);
}

static void t2(){
	vTaskSuspend(NULL);
	printf("Task 2 \n");
	vTaskDelete(NULL);
}

static void t3(){
	vTaskSuspend(NULL);
	printf("Task 3 \n");
	vTaskDelete(NULL);
}

static void t4(){
	vTaskSuspend(NULL);
	printf("Task 4 \n");
	vTaskDelete(NULL);
}

static void t5(){
	vTaskSuspend(NULL);
	printf("Task 5 \n");
	vTaskDelete(NULL);
}

void start_C2a(){
	printf("Aufgabe C2a\n\n");
	xTaskCreate(t1, "", 128, NULL, 30, &t1_Handle);
	xTaskCreate(t2, "", 128, NULL, 30, &t2_Handle);
	xTaskCreate(t3, "", 128, NULL, 30, &t3_Handle);
	xTaskCreate(t4, "", 128, NULL, 30, &t4_Handle);
	xTaskCreate(t5, "", 128, NULL, 30, &t5_Handle);
	xTaskCreate(start, "", 128, NULL, 30, &start_Handle);

	for(;;){}
}
