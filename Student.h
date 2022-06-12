//
// Created by Mahdi on 6/6/2022.
//

#ifndef TAMRIN5_STUDENT_H
#define TAMRIN5_STUDENT_H

#include "Person.h"
#include "Course.h"
#include "string"

class Student : public Person {
private:
    Course *courses;
    std::string FieldOfStudy;
    int numOfCourses;

public:
    Student(std::string firstName, std::string lastName , std::string id ,double workHours,std::string FieldOfStudy,int numOfCourses,Course* courses);
    Student(const Student& old_obj);
    ~Student();
    friend std::ostream& operator << (std::ostream& os, const Student student);

    void setFieldOfStudy(const std::string &fieldOfStudy);

    void setNumOfCourses(int numOfCourses);

    void setCourses(int numberOfCourses,Course *courses);

    friend std::istream& operator >> (std::istream& is, Student& studnet);

    bool validate(){
        if(Person::validate()){
            if(this->getId()[2]=='*'){
                return true;
            }
            else{}
            return false;
        }
        else{
            return false;
        }
    }

};


#endif //TAMRIN5_STUDENT_H
