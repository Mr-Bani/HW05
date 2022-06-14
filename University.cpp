#include "University.h"
#include "Professor.h"
#include "Student.h"
#include <string>
#include "Person.h"
#include "vector"
#include <algorithm>
#include "fstream"

using namespace std;

University::University(int budget, int numOfStudents, int numOfProfessors, Professor *&professors, Student *&students) {
    this->budget = budget;
    this->numOfStudents = numOfStudents;
    this->numOfProfessors = numOfProfessors;
    this->professors = new Professor *[numOfProfessors];
    for (int i = 0; i < numOfProfessors; i++) {
        this->professors[i] = &(professors[i]);
    }
    this->students = new Student *[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        this->students[i] = &(students[i]);
    }

}

University::~University() {
    delete[] professors;
    delete[] students;
}

University::University(const University &old_obj) {
    this->budget = old_obj.budget;
    this->numOfStudents = old_obj.numOfStudents;
    this->numOfProfessors = old_obj.numOfProfessors;
    this->professors = new Professor *[numOfProfessors];
    for (int i = 0; i < numOfProfessors; i++) {
        this->professors[i] = old_obj.professors[i];
    }
    this->students = new Student *[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        this->students[i] = old_obj.students[i];
    }

}

void University::sort() {
    for (int i = 0; i < numOfProfessors; i++) {
        int sal1 = stoi(professors[i]->getId().substr(0, 2));
        if (sal1 == 0) { sal1 = 100; }

        for (int j = i + 1; j < numOfProfessors; j++) {
            int sal2 = stoi(professors[j]->getId().substr(0, 2));
            if (sal2 == 0) { sal2 = 100; }
            if (sal1 > sal2) {
                swap(professors[i], professors[j]);
            } else if (sal1 == sal2) {
                if (professors[i]->getLastName() > professors[j]->getLastName()) {
                    swap(professors[i], professors[j]);
                }
            }

        }
    }

    for (int i = 0; i < numOfStudents-1; i++) {



        for (int j = 0; j < numOfStudents-i-1; j++) {
            int sal1 = stoi(students[j]->getId().substr(0, 2));
            if (sal1 == 0) { sal1 = 100; }
            int sal2 = stoi(students[j+1]->getId().substr(0, 2));
            if (sal2 == 0) { sal2 = 100; }
            if (sal1 > sal2) {
                swap(students[j], students[j+1]);
            } else if (sal1 == sal2) {
                if (students[j]->getLastName() > students[j+1]->getLastName()) {
                    swap(students[j], students[j+1]);
                }
            }

        }
    }
}


double University::averageGpa() {
    double totalMarks = 0;
    for (int i = 0; i < numOfStudents; i++) {
        totalMarks += students[i]->gpa();
    }
    return totalMarks / numOfStudents;
}

double University::averageGpaOfField(std::string field) {
    double totalMark = 0;
    double number = 0;
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i]->getFieldOfStudy() == field) {
            totalMark += students[i]->gpa();
            number++;
        }
    }
    if (number == 0) {
        cout << "No student with this field";
        return -1;
    }
    return totalMark / number;

}

double University::averageMarkOfCourse(std::string courseName) {
    double totalMark = 0;
    double number = 0;
    for (int i = 0; i < numOfStudents; i++) {
        Course *courses = students[i]->getCourses();
        for (int j = 0; j < students[i]->getNumOfCourses(); j++) {
            if (courses[j].getName() == courseName) {
                totalMark += *(courses[j].getMark());
                number++;
            }
        }
    }
    if (number == 0) {
        cout << "No student has this course!" << " " << courseName << endl;
        return -1;
    }
    return totalMark / number;

}

void University::printCourses() {
    vector<string> allCourses;
    vector<double> courseAverages;
    for (int i = 0; i < numOfStudents; i++) {
        Student student = *students[i];
        Course *courses = student.getCourses();
        for (int j = 0; j < student.getNumOfCourses(); j++) {
            if (!(count(allCourses.begin(), allCourses.end(), courses[j].getName()))) {
                allCourses.push_back(courses[j].getName());
                courseAverages.push_back(averageMarkOfCourse(courses[j].getName()));
            }
        }
    }
    for (int i = 0; i < allCourses.size(); i++) {
        for (int j = i; j < allCourses.size(); j++) {
            if (courseAverages[i] > courseAverages[j]) {
                swap(allCourses[i], allCourses[j]);
                swap(courseAverages[i], courseAverages[j]);
            }
        }
    }
    printf("%-20s %-10s\n", "Course name", "Average");
    for (int i = 0; i < allCourses.size(); i++) {
        printf("%-20s %-10.4f\n", allCourses[i].c_str(), courseAverages[i]);
    }


}

bool University::isEnoughBudget() {
    double totalSalary = 0;
    for (int i = 0; i < numOfStudents; i++) {
        totalSalary += students[i]->calculateSalary();
    }
    for (int i = 0; i < numOfProfessors; i++) {
        totalSalary += professors[i]->calculateSalary();
    }
    if (totalSalary >= budget) {
        return true;
    }
    return false;
}

void University::saveToFile() {
    ofstream res("Top_Students.txt");
    vector<string> handlefFields;
    vector<Student> tops;
    for (int i = 0; i < numOfStudents; i++) {
        if (!(count(handlefFields.begin(), handlefFields.end(), students[i]->getFieldOfStudy()))) {
            Student top = *students[i];
            for (int j = i; j < numOfStudents; j++) {
                if (students[j]->getFieldOfStudy() == top.getFieldOfStudy()) {
                    if (students[j]->gpa() > top.gpa()) {
                        top = *students[j];
                    }
                }
            }
            handlefFields.push_back(top.getFieldOfStudy());
            tops.push_back(top);
        }
    }
    res.fill();
    res << "-Top students-\n";
    for (int i = 0; i < handlefFields.size(); i++) {
        Student top = tops[i];
        res << top.getFirstName() << " " << top.getLastName() << " GPA: " << to_string(top.gpa()) << " Field of Study: "
            << top.getFieldOfStudy() << "\n";
    }
}

std::ostream &operator<<(ostream &os, University &university) {
    university.sort();
    cout << "Number of students: " << university.numOfStudents << endl;
    cout << "Number of professors: " << university.numOfProfessors << endl;
    cout << "Budget: " << university.budget << endl;
    cout << "-Students-" << endl;
    printf("%-12s  %-12s \n", "First name", "Last name");

    for (int i = 0; i < university.numOfStudents; i++) {
        printf("%-12s   %-12s \n", university.students[i]->getFirstName().c_str(),
               university.students[i]->getLastName().c_str());
    }
    cout << "-Professors-" << endl;
    printf("%-12s %-12s %-12s \n", "Title", "First name", "Last name");
    for (int i = 0; i < university.numOfProfessors; i++) {
        printf("%-12s  %-12s  %-12s \n", university.professors[i]->getTitle().c_str(),
               university.professors[i]->getFirstName().c_str(),
               university.professors[i]->getLastName().c_str());
    }
    return os;
}

std::istream &operator>>(istream &is, University &university) {
    cout << "Enter number of students: " << endl;
    cin >> university.numOfStudents;
    cout << "Enter number of professors: " << endl;
    cin >> university.numOfProfessors;
    cout << "Enter budget: " << endl;
    cin >> university.budget;
    cout << "Enter studnets>>>" << endl;
    university.students = new Student *[university.numOfStudents];
    for (int i = 0; i < university.numOfStudents; i++) {
        cin >> *university.students[i];
    }
    cout << "Now Enter professors>>>" << endl;
    university.professors = new Professor *[university.numOfProfessors];
    for (int i = 0; i < university.numOfProfessors; i++) {
        cin >> *university.professors[i];
    }
    cout << "input done !" << endl;
    return is;

}




