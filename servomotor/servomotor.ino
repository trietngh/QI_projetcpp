#include "Driver_servo_motor.h"

#define vitesse_marchee_servo_1 1613
#define vitesse_marchee_servo_2 1607
#define vitesse_arretee_servo_1 1500
#define vitesse_arretee_servo_2 1480


Servomotor myservo1(D8,vitesse_marchee_servo_2,vitesse_arretee_servo_2); 


void setup() {
}

void loop() {
  myservo1.Tourner_Angle_60_deg();

}