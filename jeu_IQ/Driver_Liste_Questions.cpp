/**
 * @file Driver_Liste_Questions.cpp
 * @author TANG Huong Cam (hctang@insa-toulouse.fr)
 * @brief Driver pour gérer la liste des questions de jeu IQ
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*-----------Include-------------*/

#include "Driver_Liste_Questions.h"
#include <time.h> 

/*-----------Private Constants----------*/

#define NB_QUESTIONS 21 // lien avec le constructeur liste_questions
int tableau_questions_posees[6] = {-1};


/**
 * @brief Vérifier si la question était posée
 * 
 * @param no_question 
 * @return true 
 * @return false 
 */
bool Verifier_questions_posee(int no_question){
    for (auto i:tableau_questions_posees)
    {
        if(no_question == tableau_questions_posees[i])
        {
            return true;
        }
    }
    return false;
    
}


/*-----------Class Liste_questions Functions Definition----------*/

Liste_questions::Liste_questions(){    
    liste_des_question[0] = 'A';
    liste_des_question[1] = 'A';
    liste_des_question[2] = 'B';
    liste_des_question[3] = 'C';
    liste_des_question[4] = 'B';
    liste_des_question[5] = 'A';
    liste_des_question[6] = 'B';
    liste_des_question[7] = 'B';
    liste_des_question[8] = 'B';
    liste_des_question[9] = 'A';
    liste_des_question[10] = 'C';
    liste_des_question[11] = 'A';
    liste_des_question[12] = 'B';
    liste_des_question[13] = 'A';
    liste_des_question[14] = 'C';
    liste_des_question[15] = 'A';
    liste_des_question[16] = 'B';
    liste_des_question[17] = 'C';
    liste_des_question[18] = 'B';
    liste_des_question[19] = 'B';
    liste_des_question[20] = 'A';
}


int Liste_questions::random_question(int nb_questions_posees){
    int question_renvoyee;
    srand(time(0)); 

    do{
    question_renvoyee = std::rand() % NB_QUESTIONS;
    } while(Verifier_questions_posee(question_renvoyee));

    tableau_questions_posees[nb_questions_posees] = question_renvoyee;
    return question_renvoyee;
}

char Liste_questions::recevoir_reponse(int no_question){
    return liste_des_question[no_question];
}