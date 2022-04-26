#include "GPIO.h"

GPIO::GPIO(int port, int pin_mode) : port(port), pin_mode(pin_mode) {
  pinMode(port, pin_mode);
}

void GPIO::toggle() {

  const int sleep = 1000/4; // ms

  digitalWrite(this->port, HIGH);
  delay(sleep);
  digitalWrite(this->port, LOW);
  delay(sleep);
}

void GPIO::toogle(uint32_t time_hight, uint32_t time_low) {
  digitalWrite(this->port, HIGH);
  delay(time_hight);
  digitalWrite(this->port, LOW);
  delay(time_low);
}

void GPIO::toogle(uint32_t pulse_period) {
  digitalWrite(this->port, HIGH);
  delay(pulse_period);
  digitalWrite(this->port, LOW);
  delay(pulse_period);
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
