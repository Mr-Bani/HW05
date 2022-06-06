//
// Created by Mahdi on 6/6/2022.
//

#ifndef TAMRIN5_STUDENT_H
#define TAMRIN5_STUDENT_H
#include "Person.h"
#include "Course.h"
#include "string"

class Student: public Person{
private:
    Course* courses;
    std::string FieldOfStudy;
    int numOfCourses;

};


#endif //TAMRIN5_STUDENT_H
