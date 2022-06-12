#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    //Person p("ali","ahmadi","99dd33333",22);
    Course a[3];
    Course b("ali",3,20);
    Course c("akbar",2,15);
    Course d("asghar",1,18);
    a[0] = b;
    a[1] = c;
    a[2] = d;

    //Student f = s;
    double* ab = new double;
    double* bb = new double();
    //Person p("ali","ahmadi","99dd33333",22);
    Student s("ali", "akbari", "99*d33333", 33, "akbari", 3, a);
    cout<<s.calculateSalary();



}
