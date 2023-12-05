#include "Driver_Palette_Commande.h"
#include "Arduino.h"
#include "Arduino.h"


Palette_Commande::Palette_Commande(){
        pinMode(buttonPinA, INPUT);
        pinMode(ledPinA, OUTPUT);
        pinMode(buttonPinB, INPUT);
        pinMode(ledPinB, OUTPUT);
        pinMode(buttonPinC, INPUT);
        pinMode(ledPinC, OUTPUT);
        digitalWrite(ledPinA, LOW);
        digitalWrite(ledPinB, LOW);
        digitalWrite(ledPinC, LOW);
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
            digitalWrite(ledPinA, HIGH);
            delay(500);
            digitalWrite(ledPinA, LOW);
            return 'A';
        } 
        else if (readingB == LOW) 
        {  //button B is pressed
            digitalWrite(ledPinB, HIGH);
            delay(500);
            digitalWrite(ledPinB, LOW);
            return 'B';
        } 
        else if (readingC == LOW) 
        {  //button C is pressed
            digitalWrite(ledPinC, HIGH);
            delay(500);
            digitalWrite(ledPinC, LOW);
            return 'C';
        }
        current_time = millis();
        yield();
    } while (current_time < (beginning_time + waiting_time));
    return 'F';

}


void Palette_Commande::Attendre_Demarrage(){
    do {
        yield();
    } while ( Palette_Commande::Recevoir_Reponse(3000) != 'A');
}

void Palette_Commande::Attendre_Remplissage_Cadeau(){
    do {
        yield();
    } while ( Palette_Commande::Recevoir_Reponse(3000) != 'B');


}