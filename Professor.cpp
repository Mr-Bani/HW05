//
// Created by Mahdi on 6/12/2022.
//

#include "Professor.h"

Professor::Professor(std::string firstName, std::string lastName, std::string id, double workHours, std::string title) :
        Person(firstName, lastName, id, workHours) {
    this->title = title;
}
