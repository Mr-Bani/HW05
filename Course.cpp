//
// Created by Mahdi on 6/6/2022.
//

#include "Course.h"
using namespace std;
Course::Course() {
    this->mark = new double();
}

Course::Course(std::string name, int unit, double mark) {
    this->name = name;
    this->unit = unit;
    this->mark = new double (mark);
}

Course::Course(const Course &old_obj) {
    this->mark = new double (*old_obj.mark);
    this->unit = old_obj.unit;
    this->name = old_obj.name;
}

Course::~Course() {
    delete[] this->mark;
}

std::ostream& operator << (std::ostream& os, const Course course){
os<<"Name: "<<course.name<<"  units: "<<course.unit<<"  mark:"<<*course.mark<<endl;
    return os;
}

std::istream &operator>>(istream &is, Course &course) {
    cout<<"Enter name: \n";
    is>>course.name;
    cout<<"Enter mark: \n";
    is>>*course.mark;
    cout<<"Enter units: \n";
    is>>course.unit;
    return is;
}

const string &Course::getName() const {
    return name;
}

int Course::getUnit() const {
    return unit;
}

double *Course::getMark() const {
    return mark;
}

void Course::setName(const string &name) {
    this->name = name;
}

void Course::setUnit(int unit) {
    this->unit = unit;
}

void Course::setMark(double mark) {
    *this->mark = mark;
}

Course &Course::operator=(const Course &old_obj) {
    this->mark = new double (*old_obj.mark);
    this->name = old_obj.name;
    this->unit = old_obj.unit;
    return *this;
}

