# Main
```c
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "retarget.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart2;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM4_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */
extern void start_C1a(void *pvParameters);
extern void start_C1b(void *pvParameters);
extern void start_C2 (void *pvParameters);
extern void start_C3d(void *pvParameters);
extern void start_C3f(void *pvParameters);
extern void start_C4(void *pvParameters);
extern void start_C5(void *pvParameters);
extern void start_C6a(TIM_HandleTypeDef *htim4);
extern void start_C6b(TIM_HandleTypeDef *htim4);
extern void start_C7(void *pvParameters);
extern void ISR_ENDSTOPP_LINKS(void *pvParameters);
extern void ISR_ENDSTOPP_RECHTS(void *pvParameters);
extern void ISR_c3d(void *pvParameters);
extern void ISR_CHANNEL_A(void *pvParameters);
extern void ISR_CHANNEL_B(void *pvParameters);
extern void ISR_A5_TOGGLE(void *pvParameters);
extern void ISR_A5_START(void *pvParameters);
extern void ISR_A5_STOP(void *pvParameters);
extern void ISR_A6_FEEDBACK(void *pvParameters);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	switch(GPIO_Pin){
	case 1 << 0:
			ISR_c3d(NULL);
			break;
	case 1 << 1:
			ISR_c3d(NULL);
			break;
	case 1 << 4:
			//ISR_ENDSTOPP_LINKS(NULL);
			break;
	case 1 << 5:
			//ISR_ENDSTOPP_RECHTS(NULL);
			break;
	case 1 << 6:
			//ISR_CHANNEL_A(NULL);
			break;
	case 1 << 7:
			//ISR_CHANNEL_B(NULL);
			break;
	case 1 << 8:
			//ISR_A5_TOGGLE(NULL);
			break;
	case 1 << 9:
			//ISR_A5_START(NULL);
			break;
	case 1 << 10:
			//ISR_A5_STOP(NULL);
			break;
	case 1 << 15:
			ISR_A6_FEEDBACK(NULL);
			break;
	default:
			break;
	}
	return;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  RetargetInit(&huart2);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  printf("\e[;1H\e[2J");
  printf("Start des Boards\n\r");

  TaskHandle_t Handle = NULL;
  //xTaskCreate(start_C1a, "C1a", 256, NULL, 10, &Handle);
  //xTaskCreate(start_C1b, "C1b", 256, NULL, 10, &Handle);
  //xTaskCreate(start_C2, "C2", 128, NULL, 10, &Handle);
  //xTaskCreate(start_C3d, "C3d", 128, NULL, 10, &Handle);
  //xTaskCreate(start_C3f, "C3f", 128, NULL, 10, &Handle);
  //xTaskCreate(start_C4, "C4", 128, NULL, 10, &Handle);
  //xTaskCreate(start_C5, "C5", 128, NULL, 10, &Handle);
  //xTaskCreate(start_C6a, "C6a", 128, &htim4, 10, &Handle);
  xTaskCreate(start_C6b, "C6b", 256, &htim4, 10, &Handle);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 65535;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 PC0
                           PC1 PC2 PC3 PC4
                           PC5 PC6 PC7 PC8
                           PC9 PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA6 PA7
                           PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB4 PB5 PB8
                           PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_8
                          |GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB11 PB12 PB13 PB14
                           PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
```

# Aufgabe 1
```c
#include <stdio.h>
#include <ctype.h>

void start_C1b(void *pvParameters) {
	char eingabe[20];
	printf("->");


		for (;;) {

			scanf("%s", eingabe);

			if (isalpha(eingabe[0])) {
				printf("Eingabe: %s\n", eingabe);
				if(eingabe[0] == 'X'){
					break;
				}
			}
			printf("\n\rneue Eingabe ->");
		}


	vTaskDelete(NULL);
}
```

# Aufgabe 2
```c
#include <stdio.h>
#include "cmsis_os.h"

TaskHandle_t Handle1 = NULL;
TaskHandle_t Handle2 = NULL;
TaskHandle_t Handle3 = NULL;
TaskHandle_t Handle4 = NULL;
TaskHandle_t Handle5 = NULL;
TaskHandle_t HandleStart = NULL;

void t1(void *pvParameters){
	vTaskSuspend(NULL);
	printf("1\r\n");
	vTaskDelete(NULL);
}
void t2(void *pvParameters){
	vTaskSuspend(NULL);
	printf("2\r\n");
	vTaskDelete(NULL);
}
void t3(void *pvParameters){
	vTaskSuspend(NULL);
	printf("3\r\n");
	vTaskDelete(NULL);
}
void t4(void *pvParameters){
	vTaskSuspend(NULL);
	printf("4\r\n");
	vTaskDelete(NULL);
}
void t5(void *pvParameters){
	vTaskSuspend(NULL);
	printf("5\r\n");
	vTaskDelete(NULL);
}
void start(void *pvParameters){

	vTaskResume(Handle1);
	vTaskResume(Handle3);
	vTaskResume(Handle2);
	vTaskResume(Handle5);
	vTaskResume(Handle4);
	vTaskDelete(NULL);
}


void start_C2(void *pvParameters) {
	printf("Creating\r\n");

	xTaskCreate(t1, "Task1", 128, NULL, 25, &Handle1);
	xTaskCreate(t2, "Task2", 128, NULL, 24, &Handle2);
	xTaskCreate(t3, "Task3", 128, NULL, 23, &Handle3);
	xTaskCreate(t4, "Task4", 128, NULL, 22, &Handle4);
	xTaskCreate(t5, "Task5", 128, NULL, 21, &Handle5);
	xTaskCreate(start, "Start", 128, NULL, 30, &HandleStart);
	printf("Created\r\n");

	while(1);
}
```

# Aufgabe 3
```c
#include <stdio.h>
#include "cmsis_os.h"

#define OUTPUT_MASK 0x00FF

TaskHandle_t DoppelHandle = NULL;
TaskHandle_t SensorHandle = NULL;
TaskHandle_t AusgabeHandle = NULL;
TaskHandle_t IncHandle = NULL;
TaskHandle_t DecHandle = NULL;
TaskHandle_t KaliHandle = NULL;

typedef struct{
	long moder ; // 0
	long otyper ; // 4
	long ospeedr ; // 8
	long pupdr ; // C
	long idr ; // 10
	long odr ; // 14
	long bsrr ; // 18
	long lckr ; // 1 C
	long afrl ; // 20
	long afrh ; // 24
	long brr ; // 28
	long ascr ; // 2 C
} GPIO_X ;

int GPIO_A = 0x48000000;
int GPIO_B = 0x48000400;
int GPIO_C = 0x48000800;
int GPIO_D = 0x48000C00;
int GPIO_E = 0x00001000;
int GPIO_F = 0x00001400;
int GPIO_G = 0x00001800;
int GPIO_H = 0x00001C00;

int MINPOSITION = 0;
int MAXPOSITION = 300000;

enum States{
	STATE0,
	STATE1,
	STATE2,
	STATE3
};

enum Channel{
	LOW,
	HIGH
};

enum Channel channel_a = LOW;
enum Channel channel_b = LOW;
enum States State = STATE0;
int Position = 0;

extern void ISR_ENDSTOPP_LINKS(void *pvParameters){
	xTaskResumeFromISR(KaliHandle);
}

extern void ISR_ENDSTOPP_RECHTS(void *pvParameters){
	xTaskResumeFromISR(KaliHandle);
}

void ISR_CHANNEL_A(void *pvParameters){
	xTaskResumeFromISR(SensorHandle);
	return;
}

void ISR_CHANNEL_B(void *pvParameters){
	xTaskResumeFromISR(SensorHandle);
	return;
}


void Kalibrierung(void *pvParameter){
	vTaskSuspend(NULL);
	vTaskSuspend(NULL);
	MAXPOSITION = Position;
	while(1){
		vTaskSuspend(NULL);
	}
}


void doppelplus(void *pvParameters){
	while(1){
		switch(State){
			case STATE0:
				switch(channel){
					case 1:
						State = STATE1;
						Position++;
						break;

					case 2:
						State = STATE2;
						error++;
						break;

					case 3:
						State = STATE3;
						Position--;
						break;
				}
				break;

			case STATE1:
				switch(channel){
					case 0:
						State = STATE0;
						Position--;
						break;

					case 2:
						State = STATE2;
						error++;
						break;

					case 3:
						State = STATE3;
						Position++;
						break;
				}
				break;

			case STATE2:
				switch(channel){
					case 0:
						State = STATE0;
						error++;
						break;

					case 1:
						State = STATE1;
						Position--;
						break;

					case 3:
						State = STATE3;
						Position++;
						break;
				}
				break;

			case STATE3:
				switch(channel){
					case 0:
						State = STATE0;
						Position++;
						break;

					case 1:
						State = STATE1;
						error++;
						break;

					case 2:
						State = STATE2;
						Position--;
						break;
				}
				break;

			default:
				break;
		}
		if(Position < 0) Position = 0;
		if(Position > MAXPOSITION) Position = MAXPOSITION;
	}
}

void sensor(void *pvParameters){
	GPIO_X* GPIO_A_ptr = (GPIO_X*) GPIO_A;
	while(1){
		vTaskSuspend(NULL);
		channel_a = 0x1 & (GPIO_A_ptr->idr >> 6);
		channel_b = 0x1 & (GPIO_A_ptr->idr >> 7);
	}
}

void ausgabe(void *pvParameters){

	GPIO_X* ptr_GPIOC = (GPIO_X*) GPIO_C;

	long Wo = 0;
	long Status = 0;
	long temp = 0;
	int LPosition = 0;
	while(1){
		LPosition = round((Position / MAXPOSITION) * 8);
		Wo = 0x80 >> LPosition;
		Status = 0x80 >> State;
		temp = Wo + (Status << 8);
		temp ^= OUTPUT_MASK;
		ptr_GPIOC->odr = temp;
		vTaskSuspend(NULL);
	}
}

void start_C3f(void *pvParameters) {

	xTaskCreate(Kalibrierung, "Kal", 128, NULL, 20, &KaliHandle);
	xTaskCreate(sensor, "sensor", 128, NULL, 30, &SensorHandle);
	xTaskCreate(ausgabe, "ausgabe", 128, NULL, 25, &AusgabeHandle);
	xTaskCreate(incrementPosition, "inc", 128, NULL, 30, &IncHandle);
	xTaskCreate(decrementPosition, "dec", 128, NULL, 30, &DecHandle);
	xTaskCreate(doppelplus, "doppelplus", 128, NULL, 20, &DoppelHandle);
	while(1);
}

```

# Aufgabe 4
```c
#include <stdio.h>
#include "cmsis_os.h"

#define OUTPUT_MASK 0x00FF

TaskHandle_t ProduktHandle = NULL;
TaskHandle_t KartonHandle = NULL;
TaskHandle_t VerpackerHandle = NULL;
TaskHandle_t WachHandle = NULL;
TaskHandle_t ListHandle = NULL;

int Gefuellte_Verpackungen = 0;
int Queue_produkt = 0;
int Queue_karton = 0;


void produkt(void *pvParameters){
	while(1){
		Queue_produkt++;
		vTaskDelay(20);
	}
}

void karton(void *pvParameters){
	while(1){
		Queue_karton++;
		vTaskDelay(250);
	}
}


void verpackung(void *pvParameters){
	while(1){
		if((Queue_karton > 0 ) && (Queue_produkt > 9)){
			Queue_karton--;
			Queue_produkt -= 10;
			Gefuellte_Verpackungen++;
		}
		vTaskDelay(311);
	}
}

void wach(void *pvParameters){
	while(1){
		if(Queue_produkt > 50) vTaskSuspend(ProduktHandle);
		if(Queue_karton > 7) vTaskSuspend(KartonHandle);
		if(Queue_produkt < 20) vTaskResume(ProduktHandle);
		if(Queue_karton < 3) vTaskResume(KartonHandle);
		vTaskDelay(210);
	}
}

void list(void *pvParameters){

	while(1){
		printf("Anzahl gefüllter Verpackungen: %i	Produkte Q: %i	Karton Q: %i \r\n", Gefuellte_Verpackungen, Queue_produkt, Queue_karton);
		vTaskDelay(500);
	}
}

void start_C4(void *pvParameters) {

	xTaskCreate(produkt, "produkt", 128, NULL, 20, &ProduktHandle);
	xTaskCreate(karton, "karton", 128, NULL, 20, &KartonHandle);
	xTaskCreate(verpackung, "verpackung", 128, NULL, 20, &VerpackerHandle);
	xTaskCreate(wach, "wach", 128, NULL, 20, &WachHandle);
	xTaskCreate(list, "ausgabe", 128, NULL, 20, &ListHandle);
	while(1);
}
```

# Aufgabe 5
```c
#include <stdio.h>
#include "cmsis_os.h"

#define OUTPUT_MASK 0x00FF

TaskHandle_t RolltorBewegungsHandle = NULL;
TaskHandle_t WarnleuchteHandle = NULL;

typedef struct{
	long moder ; // 0
	long otyper ; // 4
	long ospeedr ; // 8
	long pupdr ; // C
	long idr ; // 10
	long odr ; // 14
	long bsrr ; // 18
	long lckr ; // 1 C
	long afrl ; // 20
	long afrh ; // 24
	long brr ; // 28
	long ascr ; // 2 C
} GPIO_X ;

const int GPIO_A = 0x48000000;
int GPIO_B = 0x48000400;
const int GPIO_C = 0x48000800;
int GPIO_D = 0x48000C00;
int GPIO_E = 0x00001000;
int GPIO_F = 0x00001400;
int GPIO_G = 0x00001800;
int GPIO_H = 0x00001C00;


enum Warnleuchte{
	AUS,
	BLINKEN,
	AN
};

enum Richtung{
	HOCH,
	RUNTER
};

enum Arretierung{
	FIXIERT,
	LOSE
};

char RolltorState = 7;
char WarnAusgabe = 0;
enum Warnleuchte WarnleuchteState = AUS;
enum Richtung RolltorRichtung = RUNTER;
enum Arretierung STOPPPPP = LOSE;
GPIO_X* ptr_GPIOC = (GPIO_X*) GPIO_C;

void RolltorBewegung(void *pvParameter){
	while(1){
		vTaskDelay(pdMS_TO_TICKS(500));
		if(STOPPPPP == FIXIERT) continue;
		if(RolltorRichtung == RUNTER){
			if(RolltorState >= 7){
				WarnleuchteState = AUS;
			}
			else{
				RolltorState += 1;
				WarnleuchteState = BLINKEN;
			}
		}
		else if(RolltorRichtung == HOCH){
			if(RolltorState <= 0){
				WarnleuchteState = AN;
			}
			else{
				RolltorState -= 1;
				WarnleuchteState = BLINKEN;
			}
		}
	}
}

void Ausgabe(void *pvParameter){
	long temp;
	temp = (long)WarnAusgabe;
	temp = temp + ( 0xFF00 << (7 - RolltorState));
	ptr_GPIOC->odr = temp ^ OUTPUT_MASK;
	return;
}

void Warnleuchte(void *pvParameter){
	while(1){
		switch(WarnleuchteState){
			case AUS:
				WarnAusgabe = 0;
				break;
			case AN:
				WarnAusgabe = 255;
				break;
			case BLINKEN:
				WarnAusgabe ^= 255;
				break;
		}
		Ausgabe(NULL);
		vTaskDelay(pdMS_TO_TICKS(400));
	}
}


extern void ISR_A5_TOGGLE(void *pvParameters){
	RolltorRichtung ^= 1;
}

extern void ISR_A5_START(void *pvParameters){
	STOPPPPP = LOSE;
}

extern void ISR_A5_STOP(void *pvParameters){
	STOPPPPP = FIXIERT;
}

void start_C5(void *pvParameters) {


	xTaskCreate(RolltorBewegung, "RolltorBewegung", 128, NULL, 20, &RolltorBewegungsHandle);
	xTaskCreate(Warnleuchte, "Warnleuchte", 128, NULL, 20, &WarnleuchteHandle);

	while(1);
}
```

# Aufgabe 6
```c
#include <stdio.h>
#include "retarget.h"
#include "cmsis_os.h"
#include "stm32l4xx_hal.h"
#include "stm32l4xx_hal_tim.h"

#define OUTPUT_MASK 0x00FF

TaskHandle_t PulsHandle = NULL;
TaskHandle_t AusHandle = NULL;

typedef struct{
	long moder ; // 0
	long otyper ; // 4
	long ospeedr ; // 8
	long pupdr ; // C
	long idr ; // 10
	long odr ; // 14
	long bsrr ; // 18
	long lckr ; // 1 C
	long afrl ; // 20
	long afrh ; // 24
	long brr ; // 28
	long ascr ; // 2 C
} GPIO_X ;

const int GPIO_A = 0x48000000;
int GPIO_B = 0x48000400;
const int GPIO_C = 0x48000800;
int GPIO_D = 0x48000C00;
int GPIO_E = 0x00001000;
int GPIO_F = 0x00001400;
int GPIO_G = 0x00001800;
int GPIO_H = 0x00001C00;

// fanspeed[rpm] = frequency[hz] / 2 * 60

int feedback_count = 0;

enum States{
	VIERTEL,
	HALB,
	DREIV
}States;


extern void ISR_A6_FEEDBACK(void *pvParameters){
	feedback_count++;
}

void Pulsweite(void *pvParameters){
	enum States state = HALB;
	enum States next_state;
	while(1){
		vTaskDelay(pdMS_TO_TICKS(2000));
		switch(state){
			case VIERTEL:
				next_state = HALB;
				TIM4->CCR2 = 799;
				break;
			case HALB:
				next_state = DREIV;
				TIM4->CCR2 = 1599;
				break;
			case DREIV:
				next_state = VIERTEL;
				TIM4->CCR2 = 2399;
				break;
		}
		state=next_state;
	}
}


void RPM_Ausgabe(void *pvParameters){

	int current_rpm = 0;

	while(1){
		vTaskDelay(pdMS_TO_TICKS(1000));
		
		current_rpm = feedback_count * 30;
		
		printf("Current RPM : %6i | count: %5i \n\r", current_rpm, feedback_count);
		feedback_count = 0;
	}

}

void start_C6b(TIM_HandleTypeDef *htim4){
	TIM4->PSC = 0;
	TIM4->ARR = 3199;
	TIM4->CCR2 = 1599;
	
	HAL_TIM_PWM_Start(htim4,TIM_CHANNEL_2);
	
	xTaskCreate(RPM_Ausgabe, "Ausgabe", 128, NULL, 21, &AusHandle);
	xTaskCreate(Pulsweite, "Pulsweitenmodulation", 128, NULL, 20, &PulsHandle);
	
	while(1);
}
```

