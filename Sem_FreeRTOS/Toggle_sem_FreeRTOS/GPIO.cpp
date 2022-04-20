#include "GPIO.h"
#include "FreeRTOS.h"
#include "task.h"

GPIO::GPIO(int port, int pin_mode) : port(port), pin_mode(pin_mode) {
  pinMode(port, pin_mode);
}

void GPIO::toggle() {

  const int delay = 1000; // ms

  digitalWrite(this->port, HIGH);
  vTaskDelay(delay / portTICK_PERIOD_MS);
  digitalWrite(this->port, LOW);
  vTaskDelay(delay / portTICK_PERIOD_MS);
}

void GPIO::toogle(uint32_t time_hight, uint32_t time_low) {
  digitalWrite(this->port, HIGH);
  vTaskDelay(time_hight / portTICK_PERIOD_MS);
  digitalWrite(this->port, LOW);
  vTaskDelay(time_low / portTICK_PERIOD_MS);
}

void GPIO::toogle(uint32_t pulse_period) {
  digitalWrite(this->port, HIGH);
  vTaskDelay(pulse_period / portTICK_PERIOD_MS);
  digitalWrite(this->port, LOW);
  vTaskDelay(pulse_period / portTICK_PERIOD_MS);
}

void GPIO::analog_write(float local_escrita) {
  analogWrite(this->port, local_escrita);
}

int GPIO::analog_read() {
  return analogRead(this->port);
}

bool GPIO::digital_read() {
  return digitalRead(this->port);
}

void GPIO::digital_write(int port_state) {
  digitalWrite(this->port, port_state);
}
