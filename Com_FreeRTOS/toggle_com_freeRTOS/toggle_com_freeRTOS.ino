#include <FreeRTOS.h>
#include <task.h>

#define PORTA_EXPERIMENTO 42  

void blink(void *pvParameters)
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  for( ;; ) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}


void toggle(void *pvParameters)
{
  pinMode(PORTA_EXPERIMENTO, OUTPUT);
  
  for( ;; ) {
    digitalWrite(PORTA_EXPERIMENTO, HIGH);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
    digitalWrite(PORTA_EXPERIMENTO, LOW);
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

void setup() 
{
  Serial.begin(9600);

  xTaskCreate(blink, (const portCHAR *)"blink", 128, NULL, 1, NULL);
  xTaskCreate(toggle, (const portCHAR *)"toggle_gpio", 128, NULL, 2, NULL);
  vTaskStartScheduler();

  Serial.println("Failed to start FreeRTOS scheduler");
  while(1);
}

void loop()
{
}
