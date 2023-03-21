#include <Servo.h>

const int pinX = A0;
const int pinY = A1;
const int servoOnePin = A2;

Servo servoOne;

void setup() {
  Serial.begin(9600);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  servoOne.attach(servoOnePin);
}

void loop() {
  int X = analogRead(pinX);
  int Y = analogRead(pinY);

  int XDegree = map(X, 0, 1023, 0, 180);

  servoOne.write(XDegree);

  Serial.print(X);
  Serial.print("\t");
  Serial.print(Y);
  Serial.print("\n");
}
