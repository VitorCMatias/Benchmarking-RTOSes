#define PORTA_SAIDA 42
#define SINAL_ENTRADA 50

bool estado_entrada = LOW;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(PORTA_SAIDA, OUTPUT);
  pinMode(SINAL_ENTRADA, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  estado_entrada = digitalRead(SINAL_ENTRADA);
  estado_entrada == HIGH?digitalWrite(PORTA_SAIDA, HIGH):digitalWrite(PORTA_SAIDA, LOW);
}
