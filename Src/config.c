#include "main.h"

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_tx;

static void Config_SystemClock_Init(void) {
  RCC_OscInitTypeDef oscInit = {0};
  RCC_ClkInitTypeDef clockInit = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  oscInit.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  oscInit.HSIState = RCC_HSI_ON;
  oscInit.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  oscInit.PLL.PLLState = RCC_PLL_ON;
  oscInit.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  oscInit.PLL.PLLM = 8;
  oscInit.PLL.PLLN = 84;
  oscInit.PLL.PLLP = RCC_PLLP_DIV2;
  oscInit.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&oscInit) != HAL_OK) {
    Error_Handler();
  }

  clockInit.ClockType =
      RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 |
      RCC_CLOCKTYPE_PCLK2;
  clockInit.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  clockInit.AHBCLKDivider = RCC_SYSCLK_DIV1;
  clockInit.APB1CLKDivider = RCC_HCLK_DIV2;
  clockInit.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&clockInit, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

static void Config_GPIO_Init(void) {
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

static void Config_USART2_Init(void) {
  huart2.Instance = USART2;
  huart2.Init.BaudRate = UART_BAUD_RATE;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK) {
    Error_Handler();
  }
}

void Config_Init(void) {
  Config_SystemClock_Init();
  Config_GPIO_Init();
  Config_USART2_Init();
}

void Config_USART2_GPIO_Init(void) {
  GPIO_InitTypeDef gpioInit = {0};

  __HAL_RCC_GPIOA_CLK_ENABLE();
  gpioInit.Pin = TX | RX;
  gpioInit.Mode = GPIO_MODE_AF_PP;
  gpioInit.Pull = GPIO_NOPULL;
  gpioInit.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  gpioInit.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(TX_Port, &gpioInit);
}

void Config_USART2_GPIO_DeInit(void) {
  HAL_GPIO_DeInit(TX_Port, TX | RX);
}
