/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "retarget.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPIO_Output_LED_13_G_Pin GPIO_PIN_13
#define GPIO_Output_LED_13_G_GPIO_Port GPIOC
#define GPIO_Output_LED_14_G_Pin GPIO_PIN_14
#define GPIO_Output_LED_14_G_GPIO_Port GPIOC
#define GPIO_Output_LED_15_G_Pin GPIO_PIN_15
#define GPIO_Output_LED_15_G_GPIO_Port GPIOC
#define GPIO_Output_LED_0_R_Pin GPIO_PIN_0
#define GPIO_Output_LED_0_R_GPIO_Port GPIOC
#define GPIO_Output_LED_1_R_Pin GPIO_PIN_1
#define GPIO_Output_LED_1_R_GPIO_Port GPIOC
#define GPIO_Output_LED_2_R_Pin GPIO_PIN_2
#define GPIO_Output_LED_2_R_GPIO_Port GPIOC
#define GPIO_Output_LED_3_R_Pin GPIO_PIN_3
#define GPIO_Output_LED_3_R_GPIO_Port GPIOC
#define GPIO_EXTI1_Drehgeber_1_Pin GPIO_PIN_0
#define GPIO_EXTI1_Drehgeber_1_GPIO_Port GPIOA
#define GPIO_EXTI1_Drehgeber_1_EXTI_IRQn EXTI0_IRQn
#define GPIO_EXTI2_Drehgeber_2_Pin GPIO_PIN_1
#define GPIO_EXTI2_Drehgeber_2_GPIO_Port GPIOA
#define GPIO_EXTI2_Drehgeber_2_EXTI_IRQn EXTI1_IRQn
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define GPIO_EXTI6_Encoder_1_Pin GPIO_PIN_6
#define GPIO_EXTI6_Encoder_1_GPIO_Port GPIOA
#define GPIO_EXTI6_Encoder_1_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_EXTI7_Encoder_2_Pin GPIO_PIN_7
#define GPIO_EXTI7_Encoder_2_GPIO_Port GPIOA
#define GPIO_EXTI7_Encoder_2_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_Output_LED_4_R_Pin GPIO_PIN_4
#define GPIO_Output_LED_4_R_GPIO_Port GPIOC
#define GPIO_Output_LED_5_R_Pin GPIO_PIN_5
#define GPIO_Output_LED_5_R_GPIO_Port GPIOC
#define GPIO_EXTI10_Schalter_10_Pin GPIO_PIN_10
#define GPIO_EXTI10_Schalter_10_GPIO_Port GPIOB
#define GPIO_EXTI10_Schalter_10_EXTI_IRQn EXTI15_10_IRQn
#define GPIO_Input_Schalter_11_Pin GPIO_PIN_11
#define GPIO_Input_Schalter_11_GPIO_Port GPIOB
#define GPIO_Input_Schalter_12_Pin GPIO_PIN_12
#define GPIO_Input_Schalter_12_GPIO_Port GPIOB
#define GPIO_Input_Schalter_13_Pin GPIO_PIN_13
#define GPIO_Input_Schalter_13_GPIO_Port GPIOB
#define GPIO_Input_Schalter_14_Pin GPIO_PIN_14
#define GPIO_Input_Schalter_14_GPIO_Port GPIOB
#define GPIO_Input_Schalter_15_Pin GPIO_PIN_15
#define GPIO_Input_Schalter_15_GPIO_Port GPIOB
#define GPIO_Output_LED_6_R_Pin GPIO_PIN_6
#define GPIO_Output_LED_6_R_GPIO_Port GPIOC
#define GPIO_Output_LED_7_R_Pin GPIO_PIN_7
#define GPIO_Output_LED_7_R_GPIO_Port GPIOC
#define GPIO_Output_LED_8_G_Pin GPIO_PIN_8
#define GPIO_Output_LED_8_G_GPIO_Port GPIOC
#define GPIO_Output_LED_9_G_Pin GPIO_PIN_9
#define GPIO_Output_LED_9_G_GPIO_Port GPIOC
#define GPIO_EXTI11_CAN_TXD_Pin GPIO_PIN_11
#define GPIO_EXTI11_CAN_TXD_GPIO_Port GPIOA
#define GPIO_EXTI11_CAN_TXD_EXTI_IRQn EXTI15_10_IRQn
#define GPIO_EXTI12_CAN_RXD_Pin GPIO_PIN_12
#define GPIO_EXTI12_CAN_RXD_GPIO_Port GPIOA
#define GPIO_EXTI12_CAN_RXD_EXTI_IRQn EXTI15_10_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define GPIO_EXTI15_Tachometer_Pin GPIO_PIN_15
#define GPIO_EXTI15_Tachometer_GPIO_Port GPIOA
#define GPIO_EXTI15_Tachometer_EXTI_IRQn EXTI15_10_IRQn
#define GPIO_Output_LED_10_G_Pin GPIO_PIN_10
#define GPIO_Output_LED_10_G_GPIO_Port GPIOC
#define GPIO_Output_LED_11_G_Pin GPIO_PIN_11
#define GPIO_Output_LED_11_G_GPIO_Port GPIOC
#define GPIO_Output_LED_12_G_Pin GPIO_PIN_12
#define GPIO_Output_LED_12_G_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define GPIO_EXTI4_Endstop1_Pin GPIO_PIN_4
#define GPIO_EXTI4_Endstop1_GPIO_Port GPIOB
#define GPIO_EXTI5_Endstop2_Pin GPIO_PIN_5
#define GPIO_EXTI5_Endstop2_GPIO_Port GPIOB
#define GPIO_EXTI5_Endstop2_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_EXTI8_Schalter_8_Pin GPIO_PIN_8
#define GPIO_EXTI8_Schalter_8_GPIO_Port GPIOB
#define GPIO_EXTI8_Schalter_8_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_EXTI9_Schalter_9_Pin GPIO_PIN_9
#define GPIO_EXTI9_Schalter_9_GPIO_Port GPIOB
#define GPIO_EXTI9_Schalter_9_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
