//
// Created by Mahdi on 6/12/2022.
//

#ifndef TAMRIN5_PROFESSOR_H
#define TAMRIN5_PROFESSOR_H

#include "Person.h"
#include "string"

class Professor : public Person {

private:
    std::string title;
public:
    Professor(std::string firstName, std::string lastName, std::string id, double workHours,std::string title);
};


#endif //TAMRIN5_PROFESSOR_H
