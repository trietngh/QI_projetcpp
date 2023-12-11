#ifndef MYPALETTE_H
#define MYPALETTE_H
#include <Arduino.h>


class Palette_Commande{
    private: 
    const int buttonPinA = D5;   // the number of the pushbutton pin, D4
    const int buttonPinB = D6;   // the number of the pushbutton pin, D7
    const int buttonPinC = D7;   // the number of the pushbutton pin, D4

    public:
    Palette_Commande(void);

    void Attendre_Bouton(char bouton);
    char Recevoir_Reponse(int waiting_time);
    char Recevoir_Reponse(void);


};


#endif