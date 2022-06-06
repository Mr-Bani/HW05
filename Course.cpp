//
// Created by Mahdi on 6/6/2022.
//

#include "Course.h"

Course::Course() {
    this->mark = new double ;
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
    delete this->mark;
}

