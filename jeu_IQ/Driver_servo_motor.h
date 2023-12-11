/**
 * @file Driver_servo_motor.cpp
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer le servomotor
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef Driver_Servo_h
#define Driver_Servo_h

/*-----------Include-------------*/
#include <Arduino.h>
#include <Servo.h>
#include "Driver_Palette_Commande.h"
#include "Driver_ecran.h"


/*-----------Exported Constants----------*/

#define vitesse_marchee_servo_1 1645
#define vitesse_marchee_servo_2 1630
#define vitesse_arretee_servo_1 1490
#define vitesse_arretee_servo_2 1480
#define vitesse_marche_ccw 900
#define SERVO1 1
#define SERVO2 2


/*-----------Exported Class----------*/

class Servomotor{
    private:
    /*-----------Private Class Servomotor Attributs Declaration----------*/
    Servo myservo; 
    int servo_pin;
    int vitesse_marchee;
    int vitesse_arretee;
    int vitesse_ccw;

    /*-----------Public Class Servomotor Functions Definition----------*/
    public:

    /**
     * @brief Tourner le servo à 60 degrée
     * 
     */
    void Tourner_Angle_60_deg(void);

    /**
     * @brief Tourner le servo à 1 degrée au sens d'horloge
     * 
     */
    void Tourner_Angle_1_deg_ccw(void);

    /**
     * @brief Tourner le servo à 1 degrée au sens d'horloge
     * 
     */
    void Tourner_Angle_1_deg_cw(void);

    /**
     * @brief Initialiser les pins pour servomotor
     * 
     * @param pin_servomotor : pin pour servomotor
     * @param no_servo : SERVO1 (cadeau) ou SERVO2 (punition)
     */
    void Set_Up_Servo(int pin_servomotor, int no_servo);
};

#endif 