//
// Created by Mahdi on 6/6/2022.
//

#ifndef TAMRIN5_COURSE_H
#define TAMRIN5_COURSE_H

#include <string.h>
#include <iostream>

class Course {
private:
std::string name;
int unit;
double* mark;
public:
Course(std::string name,int unit=0,double mark=0);
Course();
Course(const Course& old_obj);
~Course();
friend std::ostream& operator << (std::ostream& os, const Course course);
friend std::istream& operator >> (std::istream& is, Course& course);

    const std::string &getName() const;

    int getUnit() const;

    double *getMark() const;

    void setName(const std::string &name);

    void setUnit(int unit);

    void setMark(double mark);
};


#endif //TAMRIN5_COURSE_H
