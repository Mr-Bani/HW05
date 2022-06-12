//
// Created by Mahdi on 6/12/2022.
//

#include "Professor.h"
#include <iostream>


using namespace std;

Professor::Professor(std::string firstName, std::string lastName, std::string id, double workHours, std::string title) :
        Person(firstName, lastName, id, workHours) {
    this->title = title;
}

std::ostream &operator<<(std::ostream &os, const Professor professor) {
    os << "Title:" << professor.title << endl << "Name: " << professor.getFirstName() << " " << professor.getLastName()
       << "\n id:" << professor.getId() << endl;
    os << "Work Hours: " << professor.getWorkHours() << endl;

}

std::istream &operator>>(istream &is, Professor &professor) {
    string firstName, lastName, id;
    int workHours, titleId;
    cout << "Enter title:\n 1-Instructor 2-Assistant Professor 3-Associate Professor 4-Professor \n";
    cin >> titleId;
    while (titleId > 4 or titleId < 1) {
        cout << "Enter valid number\n";
        cin >> titleId;
    }
    string title = professor.titles[titleId - 1];
    cout << "Enter first name:\n";
    is >> firstName;
    cout << "Enter last name:\n";
    is >> lastName;
    cout << "Enter id:\n";
    is >> id;
    cout << "Enter work hours:\n";
    cin >> workHours;
    professor.setFirstName(firstName);
    professor.setLastName(lastName);
    professor.setId(id);
    professor.setTitle(title);
    professor.setWorkHours(workHours);
}

const string &Professor::getTitle() const {
    return title;
}

void Professor::setTitle(const string &title) {
    Professor::title = title;
}

bool Professor::validate() {
    if (Person::validate()) {
        if (this->getId()[2] == '#' && this->getId().length()==8) {
            return true;
        }
        else {
            return false;
        }
    } else {
        return false;
    }
}
