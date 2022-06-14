#ifndef TAMRIN5_UNIVERSITY_H
#define TAMRIN5_UNIVERSITY_H
#include "Professor.h"
#include "Student.h"
#include "iostream"

class University {
private:
    int budget,numOfStudents,numOfProfessors;

    Professor** professors;
    Student** students;

    University(int budget,int numOfStudents,int numOfProfessors,Professor* professors,Student* students);
    ~University();
    University(const University& old_obj);

    void sort();
    std::ostream& operator << (std::ostream& os);
    std::istream& operator >> (std::istream& is);



};


#endif //TAMRIN5_UNIVERSITY_H
