#include "Driver_servo_motor.h"

#define GPIO_D4 2
#define GPIO_D5 14
#define GPIO_D6 12
#define GPIO_D7 13
#define GPIO_D8 15


Servomotor::Servomotor(int pin_servomotor, int v_marchee, int v_arretee)
{
    vitesse_arretee = v_arretee;
    vitesse_marchee = v_marchee;
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
        case D8:
            myservo.attach(GPIO_D8);
            servo_pin = GPIO_D8;
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

void Servomotor::Calibrer_Vitesse_Marchee()
{
    char commande = 'F';

    //Calibrage en cours
    //Appuyer C pour terminer le calibrage
    while(commande != 'C'){

        //Tourner un tour
        myservo.writeMicroseconds(vitesse_marchee);
        delay(temps_un_tour);
        //Arreter le servo
        myservo.writeMicroseconds(vitesse_arretee);
        delay(temps_attent);

        //Attendre le calibrage
        //Appuyer A pour augmenter la vitesse
        if(commande == 'A'){ // à compléter
            vitesse_marchee++;
        }
        //Appuyer B pour diminuer la vitesse
        else if(commande == 'B') // à compléter
        {
            vitesse_marchee--;
        }
    }
}

void Servomotor::Calibrer_Vitesse_Arretee()
{
    char commande = 'F';

    //Calibrage en cours
    //Appuyer C pour terminer le calibrage
    while(commande != 'C'){ 

        //Arreter le servo
        myservo.writeMicroseconds(vitesse_arretee);
        delay(temps_attent);

        //Appuyer A pour augmenter la vitesse
        if(commande == 'A'){ // à compléter
            vitesse_arretee++;
        }

        //Appuyer B pour diminuer la vitesse        
        else if(commande == 'B') // à compléter
        {
            vitesse_arretee--;
        }
    }
}


int Servomotor::Get_Vitesse_Marchee()
{
    return vitesse_marchee;
}

int Servomotor::Get_Vitesse_Arretee()
{
    return vitesse_arretee;
}

int Servomotor::Get_Pin_Servo()
{
    return servo_pin;
}