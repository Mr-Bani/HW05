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
    Student();
    Student(const Student& old_obj);
    ~Student();
    friend std::ostream& operator << (std::ostream& os, const Student student);

    const std::string &getFieldOfStudy() const;

    friend std::istream& operator >> (std::istream& is, Student& studnet);

    void setFieldOfStudy(const std::string &fieldOfStudy);

    Course *getCourses() const;

    void setCourses1(Course *courses);

    int getNumOfCourses() const;

    void setNumOfCourses(int numOfCourses);

    void setCourses(int numberOfCourses,Course *courses);
    
    Student& operator = (const Student& old_obj);



    bool validate();

    double gpa();

    double calculateSalary();
};


#endif //TAMRIN5_STUDENT_H
