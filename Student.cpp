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
    if (!validate()) {
        cout << "id is not valid as a student." << endl;
        exit(0);
    };
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
    os << "Name: " << student.getFirstName() << " " << student.getLastName() << "\nID:" << student.getId() << endl;
    os << "Work Hours: " << student.getWorkHours() << endl;
    os << "Field of Study: " << student.FieldOfStudy << endl;
    os << "Number of Courses: " << student.numOfCourses << endl;
    os << "Courses: \n";
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
    studnet.setId(id);
    studnet.setWorkHours(workHours);

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
    studnet.setFieldOfStudy(fieldOfStudy);
    studnet.setNumOfCourses(numberOfCourses);
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

bool Student::validate() {
    if (Person::validate()) {
        if (this->getId()[2] == '*') {
            return true;
        } else {}
        return false;
    } else {
        return false;
    }
}

double Student::gpa() {
    double totalUnits = 0;
    double totalMark = 0;

    for (int i = 0; i < this->numOfCourses; i++) {
        totalUnits += courses[i].getUnit();
        totalMark += (*courses[i].getMark()) * courses[i].getUnit();
    }
    return totalMark / totalUnits;
}

double Student::calculateSalary() {
    double salary = 20000 * (getWorkHours());
    if (gpa() > 17) {
        salary += salary / 10;
    }
    return salary;


}

Student::Student() : Person() {
}

const string &Student::getFieldOfStudy() const {
    return FieldOfStudy;
}

Course *Student::getCourses() const {
    return courses;
}

void Student::setCourses1(Course *courses) {
    Student::courses = courses;
}

int Student::getNumOfCourses() const {
    return numOfCourses;
}

Student &Student::operator=(const Student &old_obj) {
    this->setFirstName(old_obj.getFirstName());
    this->setLastName(old_obj.getLastName());
    this->setWorkHours(old_obj.getWorkHours());
    this->setId(old_obj.getId());
    this->setFieldOfStudy(old_obj.FieldOfStudy);
    this->setCourses(old_obj.getNumOfCourses(), old_obj.getCourses());
    this->setNumOfCourses(old_obj.numOfCourses);
}


