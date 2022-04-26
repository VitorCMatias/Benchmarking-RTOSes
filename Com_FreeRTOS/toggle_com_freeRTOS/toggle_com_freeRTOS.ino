#include "FreeRTOS.h"
#include "task.h"

#include "GPIO.h"

void setup() {
  // put your setup code here, to run once:
  xTaskCreate(blink, (const portCHAR *)"blink", 128, NULL, 2, NULL);
  vTaskStartScheduler();

}


void loop() {
  // put your main code here, to run repeatedly:

}


void blink(void *pvParameters)
{
  GPIO porta_experimento(42, OUTPUT);
  GPIO LED(LED_BUILTIN, OUTPUT);

  for ( ;; ) {
    porta_experimento.toggle();
    LED.toggle();
  }
}
