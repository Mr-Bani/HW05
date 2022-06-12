//
// Created by Mahdi on 6/6/2022.
//

#include "Student.h"
#include "string"

using namespace std;

Student::Student(string firstName, string lastName, string id, double workHours, std::string FieldOfStudy,
                 int numOfCourses, Course *courses) : Person(firstName, lastName, id, workHours) {
    this->FieldOfStudy = FieldOfStudy;
    this->courses = new Course[numOfCourses];
    this->numOfCourses = numOfCourses;
    for (int i = 0; i < numOfCourses; i++) {
        this->courses[i] = courses[i];
    }
}

Student::Student(const Student &old_obj) : Person(old_obj) {
    this->numOfCourses = old_obj.numOfCourses;
    this->FieldOfStudy = old_obj.FieldOfStudy;
    this->courses = new Course[old_obj.numOfCourses];
    for (int i = 0; i < numOfCourses; i++) {
        this->courses[i] = old_obj.courses[i];
    }
}

Student::~Student() {
    delete[] courses;
}

std::ostream &operator<<(ostream &os, const Student student) {
    os << "Name: " << student.getFirstName() << " " << student.getLastName() << "\n id:" << student.getId();
    os << "\n Work Hours: " << student.getWorkHours() << endl;
    os << "Field of Study: " << student.FieldOfStudy << endl;
    os << "Number of Courses: " << student.numOfCourses << endl;
    os << "Courses: ";
    for (int i = 0; i < student.numOfCourses; i++) {
        cout << student.courses[i];
    }
    return os;
}

std::istream &operator>>(istream &is, Student &studnet) {
    cout << "Enter first name:\n";
    string firstName, lastName, id, fieldOfStudy;
    int numberOfCourses, workHours;
    is >> firstName;
    cout << "Enter last name:\n";
    is >> lastName;
    cout << "Enter id:\n";
    is >> id;
    cout << "Enter work hours:\n";
    is >> workHours;
    studnet.setFirstName(firstName);
    studnet.setLastName(lastName);

    cout << "Enter field of study: \n";
    cin >> fieldOfStudy;
    cout << "Enter number of courses: \n";
    cin >> numberOfCourses;
    cout << "Enter courses now:\n";
    Course *courses = new Course[numberOfCourses];
    for (int i = 0; i < numberOfCourses; i++) {
        Course tmp = *new Course();
        cin >> tmp;
        courses[i] = tmp;
    }
    studnet.setCourses(numberOfCourses, courses);

    return is;
}

void Student::setCourses(int numberOfCourses, Course *courses) {
    this->courses = new Course[numberOfCourses];
    for (int i = 0; i < numberOfCourses; i++) {
        this->courses[i] = courses[i];
    }
}

void Student::setFieldOfStudy(const string &fieldOfStudy) {
    FieldOfStudy = fieldOfStudy;
}

void Student::setNumOfCourses(int numOfCourses) {
    Student::numOfCourses = numOfCourses;
}

