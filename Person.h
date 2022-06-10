
#ifndef TAMRIN5_PERSON_H
#define TAMRIN5_PERSON_H

#include <string.h>
#include <iostream>

class Person {

private:
    std::string firstName,lastName,id;
    double* workHours;

public:
    Person(std::string firstName,std::string lastName,std::string id, double workHours);
    ~Person();
    Person(const Person& old_obj);
    friend std::ostream& operator << (std::ostream& os, const Person person);
    friend std::istream& operator >> (std::istream& is, Person& person);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getId() const;

    double *getWorkHours() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setId(const std::string &id);

    void setWorkHours(double workHours);

    void operator = (Person old_obj);

    bool validate();

    double calculateSalary();


};


#endif //TAMRIN5_PERSON_H
