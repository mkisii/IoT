#include <Servo.h>
Servo myservo;

int val;//
int servoval;//servo output value
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(A0.INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  servoval = (val,0,1023,0,179);
  delay(50);
  

}
