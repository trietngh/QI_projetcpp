#include <Servo.h>

Servo myservo; 

int pos = 0;

void setup() {
  // The servo control wire is connected to Arduino D2 pin.
  myservo.attach(15);
  // Servo is stationary.
  myservo.write(1);
}

void loop() {
  // Servo spins forward at full speed for 1 second.
  myservo.write(180);
  delay(500);
  // Servo is stationary for 1 second.
  myservo.write(90);
  delay(500);
  // Servo spins in reverse at full speed for 1 second.
  myservo.write(0);
  delay(500);
  // Servo is stationary for 1 second.
  myservo.write(90);
  delay(500);
}