//
// Created by Mahdi on 6/6/2022.
//

#include "Person.h"

Person::Person() {
    workHours = new double;
}

Person::Person(std::string firstName, std::string lastName, std::string id, double workHours) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    this->workHours = new double(workHours);
}

Person::~Person() {
    delete workHours;
}

Person::Person(const Person &old_obj) {
    this->workHours = new double(*old_obj.workHours);
    this->firstName = old_obj.firstName;
    this->lastName = old_obj.lastName;
    this->id = old_obj.id;
}

