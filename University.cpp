#include "University.h"
#include "Professor.h"
#include "Student.h"

University::University(int budget,int numOfStudents,int numOfProfessors,Professor* professors,Student* students) {
    this->budget = budget;
    this->numOfStudents = numOfStudents;
    this->numOfProfessors = numOfProfessors;
    this->professors = new Professor*[numOfProfessors];
    this->students = new Student*[numOfStudents];
}

University::~University() {
for(int i=0;i<numOfProfessors;i++){
    delete [] this->professors[i];
}
for(int i=0;i<numOfStudents;i++){
    delete[] this->students[i];
}
}

University::University(const University& old_obj){
    this->budget = old_obj.budget;
    this->numOfStudents = old_obj.numOfStudents;
    this->numOfProfessors = old_obj.numOfProfessors;
    this->professors = new Professor*[old_obj.numOfProfessors];
    this->students = new Student*[old_obj.numOfStudents];
}
