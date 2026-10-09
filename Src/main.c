#include "main.h"
#include "uart_protocol.h"


void loop(void){
  // code run here
}


UartProtocol_RxFrame rxFrame;
HAL_StatusTypeDef receiveStatus;

void processRX(void){
  do {
    receiveStatus = UartProtocol_Receive(&rxFrame);
    if (receiveStatus == HAL_OK) {}
  } while (receiveStatus == HAL_OK);
}

UartProtocol_Telemetry telemetry;
void Feedback(void){
  // debug here
  // muốn xem giá trị nào thì gán giá trị đó vào một trong bảy data ở dưới, lưu ý biến muốn debug phải ép về kiểu int16_t
  // ví dụ:
  // float a;
  // int8_t b;
  // telemetry.data1 = (int16_t)(a);
  // telemetry.data2 = (int16_t)(b);
  telemetry.data1 = 1;
  telemetry.data2 = 2;
  telemetry.data3 = 3;
  telemetry.data4 = 4;
  telemetry.data5 = 5;
  telemetry.data6 = 6;
  telemetry.data7 = 7;
}

int main(void) {
  uint32_t lastTelemetryTick;
  
  HAL_Init();
  Config_Init();

  lastTelemetryTick = HAL_GetTick();

  while (1) {
    uint32_t currentTick;

    processRX();
    loop();

    currentTick = HAL_GetTick();
    if ((uint32_t)(currentTick - lastTelemetryTick) >= 20U) {
      Feedback();
      HAL_StatusTypeDef sendStatus = UartProtocol_SendTelemetry(&telemetry);
      if (sendStatus == HAL_OK) {lastTelemetryTick = currentTick;} 
      else if (sendStatus != HAL_BUSY) {Error_Handler();}
    }
  }
}

void Error_Handler(void) {
  while (1) {
  }
}


