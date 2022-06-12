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
    std::string titles[4] = {"Instructor" ,"Assistant Professor", "Associate Professor", "Professor"};

    Professor(std::string firstName, std::string lastName, std::string id, double workHours,std::string title);
    Professor();

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    friend std::ostream& operator << (std::ostream& os, const Professor professor);
    friend std::istream& operator >> (std::istream& is, Professor& professor);

    bool validate();

    double calculateSalary();
};


#endif //TAMRIN5_PROFESSOR_H
