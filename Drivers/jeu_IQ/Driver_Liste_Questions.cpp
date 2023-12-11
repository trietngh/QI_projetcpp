#include "Driver_Liste_Questions.h"
#include <time.h> 

#define NB_QUESTIONS 21 // lien avec le constructeur liste_questions
int tableau_questions_posees[6] = {-1};

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