#include "ecran.h"
#include <string.h>

Ecran ecranLCD;
void setup() 
{
}


void loop() 
{
  //string msg1 = "Bienvenue";
  ecranLCD.Afficher_Message("Bienvenue", LCD_LIGNE_1);
  //string msg2 = "Appuyer sur A pour démarrer.";
  ecranLCD.Defiler_Message("Appuyer sur A pour démarrer.", LCD_LIGNE_1);
}