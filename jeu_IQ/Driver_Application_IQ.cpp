/**
 * @file Driver_Application_IQ.cpp
 * @author Huong Cam TANG (hctang@insa-toulouse.fr)
 * @brief Driver pour gérer l'application de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*-----------Include-------------*/
#include "Driver_Application_IQ.h"


/*-----------Private Constants----------*/
#define MESSAGE_WELCOME "     Welcome    "
#define MESSAGE_ACCEUIL_DEMARRAGE "A: Demarrer jeu"
#define MESSAGE_ACCEUIL_REGLAGE "B: Regler jeu"

#define MESSAGE_REGLE1 "3s pour repondre"
#define MESSAGE_REGLE2 "Quitter=Punition"

#define MESSAGE_PRET "ARE YOU READY ?"
#define MESSAGE_DEMARRAGE "LET'S GO ..."
#define MESSAGE_NOM_DE_JEU "     IQ GAME    "

#define MESSAGE_ATTENTE_REMPLISSAGE "B : finir rempli"
#define MESSAGE_REMPLISSAGE_FINI "Remplissage fini"


#define MESSAGE_CHOISIR_SERVO_1 "A:servo cadeau"
#define MESSAGE_CHOISIR_SERVO_2 "B:servo punition"
#define MESSAGE_CALIBRE_INDICATION_1 "A: hor B: anti-h"
#define MESSAGE_CALIBRE_INDICATION_2 "C: finir reglage"
#define MESSAGE_CALIBRE_FINI "Reglage fini"

#define MESSAGE_CONTINUER_INDICATION "A : Continuer"
#define MESSAGE_QUITTER_INDICATION "B : Quitter"


#define PIN_SERVO1 D3
#define PIN_SERVO2 D4


#define BOUTON_A 'A'
#define BOUTON_B 'B'
#define BOUTON_C 'C'


#define NB_MAX_QUESTION 6
#define MESSAGE_ECOUTER_BIEN " Ecoutez bien ! "
#define MESSAGE_FINI_JEU "    JEU FINI    "
#define MESSAGE_BIEN_JOUE "    BIEN JOUE   "
#define MESSAGE_PUNITION_QUITTER "Quitter=Punition"
#define TEMPS_REPONSE 3000

#define MODE_JEU 2
#define MODE_REGLAGE 3
#define MODE_ACCEUIL 1
#define MODE_VERI_PERIF 0

/*-----------Class ApplicationIQ Functions Definition----------*/

ApplicationIQ::ApplicationIQ(){
    mode_app = MODE_ACCEUIL;
    servo_cadeau.Set_Up_Servo(PIN_SERVO1,SERVO1);
    servo_punition.Set_Up_Servo(PIN_SERVO2,SERVO2);
}

void ApplicationIQ::Acceuil_Jeu(){
    int commande = 'F';

    haut_parleur_jeu.Mettre_musique_jeu();
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_WELCOME,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_NOM_DE_JEU,LCD_LIGNE_2);

    delay(2000);

    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_ACCEUIL_DEMARRAGE,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_ACCEUIL_REGLAGE,LCD_LIGNE_2);

    do
    {
        commande = palette_jeu.Recevoir_Reponse();
    }while (commande != BOUTON_A && commande != BOUTON_B);

    if(commande == BOUTON_A)
    {
        mode_app = MODE_JEU;
    }
    else if(commande == BOUTON_B)
    {
        mode_app = MODE_REGLAGE;

    }

}

void ApplicationIQ::Demande_Remplissage(){

    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_ATTENTE_REMPLISSAGE,LCD_LIGNE_1);
    palette_jeu.Attendre_Bouton(BOUTON_B);

    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_REMPLISSAGE_FINI,LCD_LIGNE_1);
    delay(2000);
}


void ApplicationIQ::Calibrer_Servo(Servomotor myservo){

    char commande = 'F';
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_CALIBRE_INDICATION_1,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_CALIBRE_INDICATION_2,LCD_LIGNE_2);

    //Appuyer C pour terminer le calibrage
    while(commande != BOUTON_C){
        //Attendre le calibrage
        commande = palette_jeu.Recevoir_Reponse();
        //Appuyer A pour tourner sens horloge
        if(commande == BOUTON_A){ 
            myservo.Tourner_Angle_1_deg_ccw();
        }
        //Appuyer B pour tourner sens anti horloge
        else if(commande == BOUTON_B) 
        {
            myservo.Tourner_Angle_1_deg_cw();
        }
    }
}


void ApplicationIQ::Reglage_Servo_Jeu()
{
    char commande = 'F';
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_CHOISIR_SERVO_1,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_CHOISIR_SERVO_2,LCD_LIGNE_2);
    delay(1000);

    do
    {
        commande = palette_jeu.Recevoir_Reponse();
    }while (commande != BOUTON_A && commande != BOUTON_B);

    //Calibrer servo cadeau
    if(commande == BOUTON_A){
        //Calibrage en cours
        Calibrer_Servo(servo_cadeau);
    }
    else if (commande == BOUTON_B)
    {
        Calibrer_Servo(servo_punition);
    }

    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_CALIBRE_FINI,LCD_LIGNE_1);

    
}

void ApplicationIQ::Envoyer_Cadeau()
{
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message("Felicitation !",LCD_LIGNE_1);
    servo_cadeau.Tourner_Angle_60_deg();
}


void ApplicationIQ::Envoyer_Punition()
{
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message("Dommage !",LCD_LIGNE_1);
    servo_punition.Tourner_Angle_60_deg();
}


bool ApplicationIQ::Quitter_Jeu()
{
    char commande;
    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_CONTINUER_INDICATION,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_QUITTER_INDICATION,LCD_LIGNE_2);

    do
    {
        commande = palette_jeu.Recevoir_Reponse();
    } while (commande != BOUTON_A && commande != BOUTON_B);

    if(commande == BOUTON_A){
        return false;
    }
    else if (commande == BOUTON_B)
    {
        return true;
    }
    
    return false;
}

void ApplicationIQ::Lancement_Jeu(void){
    int no_question = 1;
    int id_question_courant;
    char reponse_question_courant;


    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_REGLE1,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_REGLE2,LCD_LIGNE_2);
    delay(2000);


    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_PRET,LCD_LIGNE_1);
    delay(2000);

    ecran_jeu.Effacer_Ecran();
    ecran_jeu.Afficher_Message(MESSAGE_DEMARRAGE,LCD_LIGNE_1);
    ecran_jeu.Afficher_Message(MESSAGE_NOM_DE_JEU,LCD_LIGNE_2);
    delay(2000);


    do 
    {
        delay(500);

        ecran_jeu.Effacer_Ecran();
        ecran_jeu.Afficher_Message("   Question "+String(no_question)+"  ",LCD_LIGNE_1);
        ecran_jeu.Afficher_Message(MESSAGE_ECOUTER_BIEN,LCD_LIGNE_2);

        id_question_courant = liste_questions_jeu.random_question(no_question-1);
        reponse_question_courant = liste_questions_jeu.recevoir_reponse(id_question_courant);
        haut_parleur_jeu.Eteindre_musique_jeu();

        haut_parleur_jeu.Lire_question(id_question_courant);

        haut_parleur_jeu.Lancer_horloge();

        if(reponse_question_courant == palette_jeu.Recevoir_Reponse(TEMPS_REPONSE)){
            Envoyer_Cadeau();
            haut_parleur_jeu.Mettre_felicitation();            

        }
        else
        {
            Envoyer_Punition();
            haut_parleur_jeu.Mettre_dommage();

        }
        no_question++;
        haut_parleur_jeu.Mettre_musique_jeu();

        delay(2000);

    } while((no_question <= NB_MAX_QUESTION) && !(Quitter_Jeu()));

    ecran_jeu.Effacer_Ecran();

    if(no_question > NB_MAX_QUESTION)
    {
        ecran_jeu.Afficher_Message(MESSAGE_BIEN_JOUE,LCD_LIGNE_1);
    }

    else if(Quitter_Jeu())
    {
        Envoyer_Punition();
        ecran_jeu.Afficher_Message(MESSAGE_PUNITION_QUITTER,LCD_LIGNE_1);
    }

    ecran_jeu.Afficher_Message(MESSAGE_FINI_JEU,LCD_LIGNE_2);
    haut_parleur_jeu.Mettre_merci();

}



void ApplicationIQ::Roulement_Application()
{
    if(mode_app == MODE_ACCEUIL)
    {
        Acceuil_Jeu();
    }
    if (mode_app == MODE_JEU)
    {
        Lancement_Jeu();
        Demande_Remplissage();
        mode_app = MODE_ACCEUIL;

    }
    if (mode_app == MODE_REGLAGE)
    {
        Reglage_Servo_Jeu();
        mode_app = MODE_ACCEUIL;

    }

}