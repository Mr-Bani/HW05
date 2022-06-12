#ifndef TAMRIN5_UNIVERSITY_H
#define TAMRIN5_UNIVERSITY_H
#include "Professor.h"
#include "Student.h"

class University {
private:
    int budget,numOfStudents,numOfProfessors;

    Professor* professors = new Professor[numOfProfessors];
    Student* students = new Student[numOfStudents];



};


#endif //TAMRIN5_UNIVERSITY_H
