#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "University.h"

using namespace std;


int main() {


    Course AlirezaCourse[5] = {
            Course("Math", 3, 18),
            Course("AP", 3, 19),
            Course("Physics", 3, 14),
            Course("Differential Equations", 3, 17),
            Course("Discrete Mathematics", 3, 19)
    };
    Course MahdiCourse[7] = {
            Course("Math", 3, 19),
            Course("AP", 3, 20),
            Course("Physics", 3, 18),
            Course("Differential Equations", 3, 17),
            Course("Discrete Mathematics", 3, 20),
            Course("Islamic Republic", 2, 20),
            Course("Analytical History", 2, 18),
    };
    Course AmirCourse[7] = {
            Course("Math", 3, 18),
            Course("AP", 3, 17),
            Course("Physics", 3, 20),
            Course("Differential Equations", 3, 19),
            Course("Discrete Mathematics", 3, 18),
            Course("Islamic Republic", 2, 19),
            Course("Analytical History", 2, 20),
    };
    Course ZeinabCourse[7] = {
            Course("Math", 3, 18),
            Course("AP", 3, 20),
            Course("Physics", 3, 18),
            Course("Differential Equations", 3, 19),
            Course("Discrete Mathematics", 3, 20),
            Course("Islamic Republic", 2, 20),
            Course("Analytical History", 2, 20),
    };
    Course KavehCourse[5] = {
            Course("Math", 3, 17),
            Course("AP", 3, 20),
            Course("Physics", 3, 19),
            Course("Differential Equations", 3, 17),
            Course("Discrete Mathematics", 3, 17),
    };

    Course AmirHosseinCourse[5] = {
            Course("Math", 3, 14),
            Course("AP", 3, 16),
            Course("Physics", 3, 17),
            Course("Differential Equations", 3, 15),
            Course("Discrete Mathematics", 3, 12),
    };


    Course FatemeCourse[6]{
            Course("Static", 3, 19),
            Course("Theology", 2, 20),
            Course("Physical Education", 1, 18),
            Course("Literature", 3, 19),
            Course("English language", 3, 18),
            Course("Chemistry", 3, 20),
    };
    Course HosseinCourse[6]{
            Course("Static", 3, 14),
            Course("Theology", 2, 18),
            Course("Physical Education", 1, 12),
            Course("Literature", 3, 16),
            Course("English language", 3, 20),
            Course("Chemistry", 3, 15),
    };
    Course AkbarCourse[6]{
            Course("Static", 3, 20),
            Course("Theology", 2, 15),
            Course("Physical Education", 1, 15),
            Course("Literature", 3, 17),
            Course("English language", 3, 19),
            Course("Chemistry", 3, 15),
    };

    Course HadiCourse[4]{
            Course("Static", 3, 18),
            Course("Theology", 2, 13),
            Course("Physical Education", 1, 15),
            Course("Literature", 3, 20),
    };

    Course SajjadCourse[3]{
            Course("Static", 3, 10),
            Course("Theology", 2, 10),
            Course("Physical Education", 1, 14),
    };

    Course AhmadCourse[4]{
            Course("Physics", 3, 18),
            Course("Differential Equations", 3, 15),
            Course("Static", 3, 13),
            Course("Theology", 2, 16),

    };

    Course ImanCourse[4]{
            Course("Static", 3, 14),
            Course("Theology", 2, 18),
            Course("Literature", 3, 16),
            Course("Chemistry", 3, 15),
    };

    Student Mahdi("Mahdi", "Bani", "00*zz11077", 30, "Computer Engineering", 7, MahdiCourse);
    Student Kaveh("Kaveh", "Moradian", "85*kk22222", 25, "Computer Engineering", 5, KavehCourse);
    Student Amir("Amir", "Mehrzad", "98*mm11111", 24, "Computer Engineering", 7, AmirCourse);
    Student Zeinab("Zeinab", "Dehghani", "00*mm22000", 35, "Computer Engineering", 7, ZeinabCourse);
    Student AmirHossein("AmirHossein", "Barati", "86*li23233", 5, "Computer Engineering", 5, AmirHosseinCourse);
    Student Alireza("Alireza", "Zarinfar", "99*li23233", 20, "Computer Engineering", 5, AlirezaCourse);

    Student Fateme("Fateme", "Moghimi", "97**a77777", 29, "Chemistry", 6, FatemeCourse);
    Student Hossein("Hossein", "Ahmadi", "95**a77727", 28, "Chemistry", 6, HosseinCourse);
    Student Akbar("Akbar", "Hosseini", "93**a77777", 22, "Chemistry", 6, AkbarCourse);

    Student Hadi("Hadi", "Mohammadi", "99*bb88888", 22, "Mechanic", 4, HadiCourse);
    Student Sajjad("Sajjad", "Eghbali", "87*ee88888", 29, "Mechanic", 3, SajjadCourse);

    Student Iman("Iman", "Hadi", "95*bb88888", 24, "Math", 4, ImanCourse);
    Student Ahmad("Ahmad", "Noori", "94*aa88888", 14, "Math", 4, AhmadCourse);


    Professor Azade("Azade", "Mansoori", "84#99999", 40, "Professor");
    Professor Zavar("Sajjad", "Zavar", "00#88888", 2, "Instructor");
    Professor Salar("Alireza", "Salarian", "87#77777", 20, "Associate Professor");
    Professor Jalalian("Zahra", "Jalalian", "90#99999", 15, "Instructor");

    Student students[13] = {Mahdi, Kaveh, Zeinab, Alireza, Hossein, Amir, AmirHossein, Fateme, Hadi, Iman
    ,Ahmad,Akbar,Sajjad};

    Professor professors [] = {Salar,Zavar,Jalalian,Azade};
    Professor* pp = professors;
    Student* sp = students;

    University Kharazmi(300*1000,13,4,pp,sp);
    cout<<Kharazmi;



}
