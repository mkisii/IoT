#define input_pin A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(input_pin,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int input_value = analogRead(input_pin);
  Serial.println(input_value);
  delay(2000);

}
