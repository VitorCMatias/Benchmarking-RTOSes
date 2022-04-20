#include "FreeRTOS.h"
#include "task.h"

#include "GPIO.h"

void blink(void *pvParameters);
void toggle_GPIO(void *pvParameters);

void setup() {
  // put your setup code here, to run once:
  
  xTaskCreate(blink, (const portCHAR *)"blink", 128, NULL, 1, NULL);
  xTaskCreate(toggle_GPIO, (const portCHAR *)"toggle GPIO", 128, NULL, 1, NULL);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //////////////Serial.println("loop");
}

void blink(void *pvParameters)
{
  GPIO LED_interno(LED_BUILTIN, OUTPUT);

  for ( ;; ) {
    LED_interno.toggle();    
  }
}


void toggle_GPIO(void *pvParameters)
{
  GPIO porta_experimento(42, OUTPUT);

  for ( ;; ) {
    porta_experimento.toggle(1000,1000);   
  }
}
