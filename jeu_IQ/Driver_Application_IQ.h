/**
 * @file Driver_Application_IQ.h
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Header du Driver pour gérer l'application de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*-----------Include-------------*/
#ifndef Driver_AppplicationIQ_h
#define Driver_AppplicationIQ_h

#include <Arduino.h>
#include "Driver_ecran.h"
#include "Driver_Palette_Commande.h"
#include "Driver_servo_motor.h"
#include "Driver_Liste_Questions.h"
#include "Driver_Haut_Parleur.h"

/*-----------Exported Class----------*/

class ApplicationIQ
{
private:

    /*-----------Private Class ApplicationIQ Attributs Declaration----------*/
    int mode_app;
    Liste_questions liste_questions_jeu;
    Palette_Commande palette_jeu;
    Haut_Parleur haut_parleur_jeu;
    Servomotor servo_cadeau;
    Servomotor servo_punition;
    Ecran ecran_jeu;

    /*-----------Private Class ApplicationIQ Functions Definition----------*/

    /**
     * @brief Calibrer la position de servo
     * 
     * @param myservo 
     */
    void Calibrer_Servo(Servomotor myservo);

    /**
     * @brief Attendre le joueur remplir les disques de cadeau et de punition
     * 
     * @param None 
     */
    void Demande_Remplissage(void); 

    /**
     * @brief Verifier si le joueur quitte le jeu
     * 
     * @return true : joueur quitte le jeu
     * @return false : joueur reste en jeu
     */
    bool Quitter_Jeu (void); 

    /**
     * @brief Lancer l'écran d'acceuil de jeu IQ
     * 
     * @param None
     * 
     */
    void Acceuil_Jeu(void); 

    /**
     * @brief Lancer le jeu IQ
     * 
     * @param None
     */
    void Lancement_Jeu(void); 

    /**
     * @brief Lancer l'écran de réglage de servo
     * 
     * @param None
     */
    void Reglage_Servo_Jeu(void);

    /**
     * @brief Touner le disque de punition
     * 
     * @param None
     */
    void Envoyer_Punition (void); 

    /**
     * @brief Touner le disque de cadeau
     * 
     * @param None
     */
    void Envoyer_Cadeau (void); 



public:
    /*-----------Public Class ApplicationIQ Functions Definition----------*/

    /**
     * @brief Construct a new Application IQ object
     * 
     */
    ApplicationIQ();

    /**
     * @brief 
     * 
     */
    void Roulement_Application(void); 


};
#endif  
