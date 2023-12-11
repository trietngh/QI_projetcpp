/**
 * @file Driver_Palette_Commande.cpp
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Driver pour gérer la palette de commande de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*-----------Include-------------*/
#include "Driver_Palette_Commande.h"

/*-----------Private Constants----------*/

#define TEMPS_ATTENTE_REPONSE 3000

/*-----------Class Palette_Commande Functions Definition----------*/

Palette_Commande::Palette_Commande(){
        pinMode(buttonPinA, INPUT);
        pinMode(buttonPinB, INPUT);
        pinMode(buttonPinC, INPUT);
}

char Palette_Commande::Recevoir_Reponse(int waiting_time){
    int readingA; 
    int readingB; 
    int readingC; 
    int current_time;
    int beginning_time;

    beginning_time = millis();

    do {
        readingA = digitalRead(buttonPinA);
        readingB = digitalRead(buttonPinB);
        readingC = digitalRead(buttonPinC);        
        if (readingA == LOW) 
        {  //button A is pressed
            return 'A';
        } 
        else if (readingB == LOW) 
        {  //button B is pressed
            return 'B';
        } 
        else if (readingC == LOW) 
        {  //button C is pressed
            return 'C';
        }
        current_time = millis();
        yield();
    } while (current_time < (beginning_time + waiting_time));
    return 'F';

}


char Palette_Commande::Recevoir_Reponse(){
    int readingA; 
    int readingB; 
    int readingC; 

    do {
        readingA = digitalRead(buttonPinA);
        readingB = digitalRead(buttonPinB);
        readingC = digitalRead(buttonPinC);        
        if (readingA == LOW) 
        {  //button A is pressed
            return 'A';
        } 
        else if (readingB == LOW) 
        {  //button B is pressed
            return 'B';
        } 
        else if (readingC == LOW) 
        {  //button C is pressed
            return 'C';
        }
        yield();
    } while (readingA == HIGH && readingB == HIGH && readingC == HIGH);
    return 'F';

}


void Palette_Commande::Attendre_Bouton(char bouton){
    do {
    } while ( Palette_Commande::Recevoir_Reponse() != bouton);
}
