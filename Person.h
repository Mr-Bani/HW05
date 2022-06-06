
#ifndef TAMRIN5_PERSON_H
#define TAMRIN5_PERSON_H

#include <string.h>
#include <iostream>

class Person {

private:
    std::string firstName,lastName,id;
    double* workHours;

public:
    Person();
    Person(std::string firstName,std::string lastName,std::string id, double workHours);
    ~Person();
    Person(const Person& old_obj);
    friend std::ostream& operator << (std::ostream& os, const Person person);
    friend std::istream& operator >> (std::istream& is, Person& person);


};


#endif //TAMRIN5_PERSON_H
