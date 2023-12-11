/**
 * @file Driver_Application_IQ.h
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer l'application de jeu IQ
 * @version 0.1
 * @date 2023-12-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef Driver_AppplicationIQ_h
#define Driver_AppplicationIQ_h

#include <Arduino.h>
#include "Driver_ecran.h"
#include "Driver_Palette_Commande.h"
#include "Driver_servo_motor.h"
#include "Driver_Liste_Questions.h"
#include "Driver_Haut_Parleur.h"

class ApplicationIQ
{
private:
    int mode_app;
    Liste_questions liste_questions_jeu;
    Palette_Commande palette_jeu;
    Haut_Parleur haut_parleur_jeu;
    Servomotor servo_cadeau;
    Servomotor servo_punition;
    Ecran ecran_jeu;

    void Calibrer_Servo(Servomotor myservo);//done
    void Demande_Remplissage(void); // done

    bool Quitter_Jeu (void); //done 

    void Acceuil_Jeu(void); // done
    void Lancement_Jeu(void); // done
    void Reglage_Servo_Jeu(void);//done 
    void Envoyer_Punition (void); //done
    void Envoyer_Cadeau (void); //done


public:


    //constructeur de l'application 
    ApplicationIQ();
    void Roulement_Application(void); //done



};
#endif  
