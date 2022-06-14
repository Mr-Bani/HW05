#include "University.h"
#include "Professor.h"
#include "Student.h"
#include <string>
#include "Person.h"
#include "vector"
#include <algorithm>

using namespace std;

University::University(int budget, int numOfStudents, int numOfProfessors, Professor *professors, Student *students) {
    this->budget = budget;
    this->numOfStudents = numOfStudents;
    this->numOfProfessors = numOfProfessors;
    this->professors = new Professor *[numOfProfessors];
    this->students = new Student *[numOfStudents];
}

University::~University() {
    for (int i = 0; i < numOfProfessors; i++) {
        delete[] this->professors[i];
    }
    for (int i = 0; i < numOfStudents; i++) {
        delete[] this->students[i];
    }
}

University::University(const University &old_obj) {
    this->budget = old_obj.budget;
    this->numOfStudents = old_obj.numOfStudents;
    this->numOfProfessors = old_obj.numOfProfessors;
    this->professors = new Professor *[old_obj.numOfProfessors];
    this->students = new Student *[old_obj.numOfStudents];
}

std::ostream &University::operator<<(std::ostream &os) {
    sort();
    cout << "Number of students: " << numOfStudents << endl;
    cout << "Number of professors: " << numOfProfessors << endl;
    cout << "Budget: " << budget << endl;
    cout << "-Students-" << endl;
    printf("%-12s  %-12s \n", "First name", "Last name");
    for (int i = 0; i < numOfStudents; i++) {
        printf("%-12s   %-12s \n", students[i]->getFirstName().c_str(), students[i]->getLastName().c_str());
    }
    cout << "-Professors-" << endl;
    printf("%-12s %-12s %-12s \n", "Title", "First name", "Last name");
    for (int i = 0; i < numOfProfessors; i++) {
        printf("%-12s  %-12s  %-12s \n", professors[i]->getTitle().c_str(), professors[i]->getFirstName().c_str(),
               professors[i]->getLastName().c_str());
    }
}


void University::sort() {
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = i + 1; j < numOfStudents; j++)
            if (students[i]->getId() > students[j]->getId()) {
                if (students[j]->getId()[0] != '0') {
                    swap(students[i], students[j]);
                } else {
                    string tmp_id = "999" + students[j]->getId().substr(2);
                    if (students[i]->getId() > tmp_id) {
                        swap(students[i], students[j]);
                    }
                }
            }
    }

    for (int i = 0; i < numOfProfessors; i++) {
        for (int j = i + 1; j < numOfProfessors; j++)
            if (stoi(professors[i]->getId().substr(0, 2)) > stoi(professors[j]->getId().substr(0, 2))) {
                swap(professors[i], professors[j]);
            }
    }
}

std::istream &University::operator>>(istream &is) {
    cout << "Enter number of students: " << endl;
    cin >> numOfStudents;
    cout << "Enter number of professord: " << endl;
    cin >> numOfProfessors;
    cout << "Enter budget: " << endl;
    cin >> budget;
    cout << "Enter studnets>>>" << endl;
    students = new Student *[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        cin >> *students[i];
    }
    cout << "Now Enter professors>>>" << endl;
    professors = new Professor *[numOfProfessors];
    for (int i = 0; i < numOfProfessors; i++) {
        cin >> *professors[i];
    }
    cout << "input done !" << endl;


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
    for(int i=0;i<numOfStudents;i++){
        Course* courses = students[i]->getCourses();
        for(int j=0;j<students[i]->getNumOfCourses();j++){
            if(courses[j].getName() == courseName){
                totalMark+=*courses[j].getMark();
                number++;
                break;
            }
        }
        if(number==0){
            cout<<"No student has this course!";
            return -1;
        }
        return totalMark/number;
    }
}

void University::printCourses() {
    vector<string> allCourses;
    vector<double> courseAverages;
    for(int i=0;i<numOfStudents;i++){
        Student student = *students[i];
        Course* courses = student.getCourses();
        for(int j=0;j<student.getNumOfCourses();j++){
            if(!(count(allCourses.begin(),allCourses.end(),courses[j].getName()))){
                allCourses.push_back(courses[j].getName());
                courseAverages.push_back(averageMarkOfCourse(courses[j].getName()));
            }
        }
    }
    for(int i=0;i<allCourses.size();i++){
        for(int j=i;j<allCourses.size();j++){
            if(courseAverages[i]>courseAverages[j]){
                swap(allCourses[i],allCourses[j]);
                swap(courseAverages[i],courseAverages[j]);
            }
        }
    }
    printf("%-20s %-10s","Course name","Average");
    for(int i=0;i<allCourses.size();i++){
        printf("%-20s %-10.4f",allCourses[i].c_str(),courseAverages[i]);
    }


}



