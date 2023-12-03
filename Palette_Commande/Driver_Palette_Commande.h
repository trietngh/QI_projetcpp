#ifndef MYPALETTE_H
#define MYPALETTE_H
#include "Arduino.h"


class Palette_Commande{
    private: 
    const int ledPinA = D3;      // the number of the LED pin, D3
    const int buttonPinA = D5;   // the number of the pushbutton pin, D4
    const int ledPinB = D6;      // the number of the LED pin, D6
    const int buttonPinB = D7;   // the number of the pushbutton pin, D7
    const int ledPinC = D8;      // the number of the LED pin, D8
    const int buttonPinC = D4;   // the number of the pushbutton pin, D4

    public:
    Palette_Commande();

    void Attendre_Demarrage();
    void Attendre_Remplissage_Cadeau();
    char Recevoir_Reponse(int waiting_time);

};


#endif