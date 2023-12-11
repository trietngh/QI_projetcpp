#ifndef Driver_Liste_Questions_h
#define Driver_Liste_Questions_h

#include <iostream>
#include <map>
using namespace std;

class Liste_questions
{
private:
    std::map <int,char> liste_des_question;
public:
    Liste_questions();
    int random_question (int nb_questions_posees);
    char recevoir_reponse (int no_question);
};


#endif