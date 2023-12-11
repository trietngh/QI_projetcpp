#ifndef Driver_Servo_h
#define Driver_Servo_h

#include <Arduino.h>
#include <Servo.h>
#include "Driver_Palette_Commande.h"
#include "Driver_ecran.h"


#define vitesse_marchee_servo_1 1645
#define vitesse_marchee_servo_2 1630
#define vitesse_arretee_servo_1 1490
#define vitesse_arretee_servo_2 1480
#define vitesse_marche_ccw 900
#define SERVO1 1
#define SERVO2 2



class Servomotor{
    private:
    Servo myservo; 
    int servo_pin;
    int vitesse_marchee;
    int vitesse_arretee;
    int vitesse_ccw;


    public:
    void Tourner_Angle_60_deg(void);
    void Tourner_Angle_1_deg_ccw(void);
    void Tourner_Angle_1_deg_cw(void);
    void Set_Up_Servo(int pin_servomotor, int no_servo);
};

#endif 