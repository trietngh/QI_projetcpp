#include "Driver_Application_IQ.h"

ApplicationIQ monapp;

void setup() {
  Serial.begin(9600);

}

void loop() {


  try{
      monapp.Roulement_Application();
  }
  catch (int e)
  {
      cout << e << '\n';
  }

}
