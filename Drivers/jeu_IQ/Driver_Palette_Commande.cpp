#include "Driver_Palette_Commande.h"

#define TEMPS_ATTENTE_REPONSE 3000


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
