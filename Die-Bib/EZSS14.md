# code SS14
```c

long int maske0 = 1 << 0;
long int maske1 = 1 << 1;
long int maske2 = 1 << 2;

void* DIGI_OUT_ptr = (void*) DIGI_OUT;

// --- Bedingung --- | von ISR aufgerufen | Prio = 10
for (;;) { 
	vTaskSusend(NULL);
	
	timeNeu = clock();
	diffNeu = timeNeu - timeAlt;
	
	if (diffNeu < diffAlt 205 / 360) { // faelschlich ausgelöst
		continue;
	} else if (diffNeu > diffAlt * 5) { // 4-mal verasst
		*DIGI_OUT_ptr |= maske2;
	} else {
		vTaskDelete(ScedulerHandel);
		xTaskCreate(Sceduler, "Sceduler", 256, NULL, 30, &ScedulerHandel);
		
		diffAlt = diffNeu;
		timeAlt = timeNeu;
	}
}

// --- Licht --- | Prio = 20
for (;;) {
	vTasktSuspend(NULL);
	vTaskDelay(pdMS_TO_TICKS(diffAlt / 8));
	*DIGI_OUT_ptr &= ~maske1;
	vTaskDelay(pdMS_TO_TICKS(diffAlt / 8));
	*DIGI_OUT_ptr |= maske1;
}

// --- DIGI --- | Prio = 20
for (;;){
	vTasktSuspend(NULL);
	vTaskDelay(pdMS_TO_TICKS(diffAlt * 30 / 360));
	*DIGI_OUT_ptr |= maske0;
	vTaskDelay(pdMS_TO_TICKS(5));
	*DIGI_OUT_ptr &= ~maske0;
}

// --- Sceduler --- | Prio = 30
for (;;) {
	vTaskResume(DIGIHandel);
	vTaskResume(LichtHandel);
	vTaskDelay(pdMS_TO_TICKS(diffAlt));
}
```