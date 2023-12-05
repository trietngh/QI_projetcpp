#ifndef Driver_Servo_h
#define Driver_Servo_h

#include <Arduino.h>
#include <Servo.h>
#include "Driver_Palette_Commande.h"
#include "Driver_ecran.h"


#define vitesse_marchee_servo_1 1613
#define vitesse_marchee_servo_2 1607
#define vitesse_arretee_servo_1 1500
#define vitesse_arretee_servo_2 1480

#define temps_un_tour 1200
#define temps_60_deg 200
#define temps_attent 1000

class Servomotor{
    private:
    Servo myservo; 
    int servo_pin;
    int vitesse_marchee;
    int vitesse_arretee;

    public:
    Servomotor(int pin_servomotor, int v_marchee, int v_arretee);
    void Tourner_Angle_60_deg(void);
    void Calibrer_Vitesse_Marchee(Ecran ecran, Palette_Commande palette);
    void Calibrer_Vitesse_Arretee(Ecran ecran, Palette_Commande palette);
    int Get_Vitesse_Arretee(void);
    int Get_Vitesse_Marchee(void);
    int Get_Pin_Servo(void);
};

#endif 