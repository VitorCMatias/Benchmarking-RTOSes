#include "GPIO.h"

const byte interruptPin = 50;
const byte Porta_analise = 42;
volatile byte state = LOW;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Porta_analise, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  digitalWrite(LED_BUILTIN, state);
  digitalWrite(Porta_analise, state);
}

void blink() {
  state = !state;
}
