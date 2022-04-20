#define PORTA_EXPERIMENTO 42

void setup() {
  // put your setup code here, to run once:
  pinMode(PORTA_EXPERIMENTO, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PORTA_EXPERIMENTO, HIGH);
  delay(1000);
  digitalWrite(PORTA_EXPERIMENTO, LOW);
  delay(1000);

}
