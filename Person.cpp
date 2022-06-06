//
// Created by Mahdi on 6/6/2022.
//

#include "Person.h"
#include <iostream>
#include <regex>

using namespace std;

Person::Person(std::string firstName, std::string lastName, std::string id, double workHours) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    if(!validate()){
        cout<<"id is not valid"<<endl;
        exit(0);
    };
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

std::ostream &operator<<(std::ostream &os, const Person person) {
    os<<"Name: "<<person.firstName<<" "<<person.lastName<<"\n id:"<<person.id;
    os<<"\n Work Hours: "<<*person.workHours;
    return os;
}

std::istream &operator>>(std::istream &is, Person &person) {
    cout<<"Enter first name:\n";
    is>>person.firstName;
    cout<<"Enter last name:\n";
    is>>person.lastName;
    cout<<"Enter id:\n";
    is>>person.id;
    cout<<"Enter work hours:\n";
    is>>*person.workHours;
    return is;
}

const string &Person::getFirstName() const {
    return firstName;
}

const string &Person::getLastName() const {
    return lastName;
}

const string &Person::getId() const {
    return id;
}

double *Person::getWorkHours() const {
    return workHours;
}

void Person::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const string &lastName) {
    this->lastName = lastName;
}

void Person::setId(const string &id) {
    this->id = id;
}

void Person::setWorkHours(double workHours) {
    *this->workHours = workHours;
}

void Person::operator=(Person old_obj){
    this->workHours = new double (*old_obj.workHours);
    this->firstName = old_obj.firstName;
    this->lastName = old_obj.lastName;
    this->id = old_obj.id;
}

bool Person::validate() {
string reg = "^([86-99]{0,2}|00)\\D{1,3}([0-4]{1,5}|[6-9]{1,5})$";

    if(regex_match(this->id,regex(reg))){
        return true;
    }
    return false;
}

double Person::calculateSalary() {
    return 10*1000*(*workHours);
}



