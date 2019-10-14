int ledpin = 13;
int state = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == LOW) {
    digitalWrite(ledpin, LOW);
    delay(5000);//The delay time when at high state.
    state = HIGH;
    Serial.println("ON");
  }
  else{
    digitalWrite(ledpin, HIGH);
    delay(5000);//delay time when state is low.
    state = LOW;
    Serial.println("OFF");
  }

}
