/**
 * @file Driver_Haut_Parleur.cpp
 * @author Huong Cam TANG (hctang@insa-toulouse.fr)
 * @brief Driver pour gérer le haut-parleur connecté en USART avec Raspberry par ESP
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*-----------Include-------------*/
#include "Driver_Haut_Parleur.h"
#include <Arduino.h>

/*-----------Private Constants----------*/

#define MESSAGE_MUSIQUE_JEU 100
#define MESSAGE_ETEINDRE_MUSIQUE_JEU 101
#define MESSAFE_FELICITATION 102
#define MESSAGE_DOMMAGE 103
#define MESSAGE_MERCI 104
#define MESSAGE_ACK "ack"
#define MESSAGE_MUSIQUE_HORLOGE 105
#define MESSAGE_CONNECTION 106


/*-----------Class Haut_Parleur Functions Definition----------*/

void Haut_Parleur::Recevoir_ack_h_parleur()
{   int begin = millis();
    String r;
    do
    {
        r=Serial.readStringUntil('\n');
        if(millis() - begin > 25000) throw "ERROR: DO NOT RECEIVE AN ACK FROM RASPBERRY";
        yield();
    }while(r != MESSAGE_ACK);
}

void Haut_Parleur::Lancer_horloge()
{
    Serial.println(MESSAGE_MUSIQUE_HORLOGE);
    Recevoir_ack_h_parleur();
}


void Haut_Parleur::Lire_question(int no_question)
{
    Serial.println(no_question+1);
    //Attendre reponse de raspberry
    Recevoir_ack_h_parleur();
}


void Haut_Parleur::Mettre_musique_jeu()
{
    Serial.println(MESSAGE_MUSIQUE_JEU);
    Recevoir_ack_h_parleur();
}

void Haut_Parleur::Eteindre_musique_jeu()
{
    Serial.println(MESSAGE_ETEINDRE_MUSIQUE_JEU);
    Recevoir_ack_h_parleur();
}

void Haut_Parleur::Mettre_felicitation()
{
    Serial.println(MESSAFE_FELICITATION);
    Recevoir_ack_h_parleur();

}
void Haut_Parleur::Mettre_dommage()
{
    Serial.println(MESSAGE_DOMMAGE);
    Recevoir_ack_h_parleur();
}

void Haut_Parleur::Mettre_merci()
{
    Serial.println(MESSAGE_MERCI);
    Recevoir_ack_h_parleur();

}


