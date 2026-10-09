#ifndef MICROMOUSE_CONFIG_H
#define MICROMOUSE_CONFIG_H

#include "stm32f4xx_hal.h"

#define UART_BAUD_RATE 921600U

/* UART2 pins. */
#define TX GPIO_PIN_2
#define TX_Port GPIOA
#define RX GPIO_PIN_3
#define RX_Port GPIOA

/* Board pin assignments retained for future hardware features. */
#define LED1 GPIO_PIN_13
#define LED1_Port GPIOC
#define LED2 GPIO_PIN_14
#define LED2_Port GPIOC
#define LED3 GPIO_PIN_15
#define LED3_Port GPIOC

#define BUTTON1 GPIO_PIN_0
#define BUTTON1_Port GPIOA
#define BUTTON2 GPIO_PIN_1
#define BUTTON2_Port GPIOA

#define MOTOR_RIGHT GPIO_PIN_8
#define MOTOR_RIGHT_Port GPIOA
#define MOTOR_LEFT GPIO_PIN_9
#define MOTOR_LEFT_Port GPIOB

// encoder
#define EN_RIGHT_A GPIO_PIN_12
#define EN_RIGHT_A_Port GPIOA
#define EN_RIGHT_A_EXTI_IRQn EXTI15_10_IRQn

#define EN_LEFT_A GPIO_PIN_4
#define EN_LEFT_A_Port GPIOB
#define EN_LEFT_A_EXTI_IRQn EXTI4_IRQn

#define EN_RIGHT_B GPIO_PIN_11
#define EN_RIGHT_B_Port GPIOA
#define EN_RIGHT_B_EXTI_IRQn EXTI15_10_IRQn

#define EN_LEFT_B GPIO_PIN_5
#define EN_LEFT_B_Port GPIOB
#define EN_LEFT_B_EXTI_IRQn EXTI9_5_IRQn



void Config_Init(void);
void Config_USART2_GPIO_Init(void);
void Config_USART2_GPIO_DeInit(void);

#endif /* MICROMOUSE_CONFIG_H */
