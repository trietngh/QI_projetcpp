/**
 * @file jeu_IQ.ino
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Main du programme de lancement de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Driver_Application_IQ.h"

ApplicationIQ monapp;

void setup() {
  //Set up serial for USART to Raspberry
  Serial.begin(9600);
}

void loop() {
  try{
    //Lancer l'application de jeu IQ
    monapp.Roulement_Application();
  }
  //Attrapper les exceptions
  catch (int e)
  {
    cout << e << '\n';
  }

}
