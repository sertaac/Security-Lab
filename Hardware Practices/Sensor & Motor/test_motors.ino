#include <ESP32Servo.h>

Servo myservo;
const int servoPin = 18;

void setup() {
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(20);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(20);
  }
  delay(2000);
}
