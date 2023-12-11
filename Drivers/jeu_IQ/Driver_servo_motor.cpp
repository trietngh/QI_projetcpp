#include "Driver_servo_motor.h"

#define GPIO_D3 0
#define GPIO_D4 2
#define GPIO_D5 14
#define GPIO_D6 12
#define GPIO_D7 13

#define temps_un_tour 1200
#define temps_60_deg 200
#define temps_attent 1000
#define temps_1_deg 20

void Servomotor::Set_Up_Servo(int pin_servomotor, int no_servo)
{
    vitesse_ccw = vitesse_marche_ccw;
    if(no_servo == SERVO1)
    {
      vitesse_arretee = vitesse_arretee_servo_1;
      vitesse_marchee = vitesse_marchee_servo_1;
    }
    else if (no_servo == SERVO2)
    {
      vitesse_arretee = vitesse_arretee_servo_2;
      vitesse_marchee = vitesse_marchee_servo_2;
    }

    switch (pin_servomotor)
    {
        case D4:
            myservo.attach(GPIO_D4);
            servo_pin = GPIO_D4;
            break;
        case D5:
            myservo.attach(GPIO_D5);
            servo_pin = GPIO_D5;
            break;
        case D6:
            myservo.attach(GPIO_D6);
            servo_pin = GPIO_D6;
            break;
        case D7:
            myservo.attach(GPIO_D7);
            servo_pin = GPIO_D7;
            break;
        case D3:
            myservo.attach(GPIO_D3);
            servo_pin = GPIO_D3;
            break;
        default:                
            break;
    }

    // Position initiale stationnaire
    myservo.writeMicroseconds(vitesse_arretee);
}

void Servomotor::Tourner_Angle_60_deg(){

    //Tourner un angle 60 degree
    myservo.writeMicroseconds(vitesse_marchee);
    delay(temps_60_deg);

    //Arreter
    myservo.writeMicroseconds(vitesse_arretee);
    delay(temps_attent);
}


void Servomotor::Tourner_Angle_1_deg_ccw(){

    //Tourner un angle 1 degree
    myservo.writeMicroseconds(vitesse_ccw);
    delay(temps_1_deg);

    //Arreter
    myservo.writeMicroseconds(vitesse_arretee);
    delay(temps_attent);
}

void Servomotor::Tourner_Angle_1_deg_cw(){

    //Tourner un angle 1 degree
    myservo.writeMicroseconds(vitesse_marchee);
    delay(temps_1_deg);

    //Arreter
    myservo.writeMicroseconds(vitesse_arretee);
    delay(temps_attent);
}
