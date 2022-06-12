#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"

using namespace std;

int main() {
    //Person p("ali","ahmadi","99dd33333",22);
    Course a[2];
    Course b;
    Course c;
    a[0] = b;
    a[1] = c;

    //Student f = s;
    double* ab = new double;
    double* bb = new double();
    *ab = 3.2;
    *bb = 3.5;
    cout<<ab<<*ab<<endl;
    cout<<bb<<*bb<<endl;
    //Person p("ali","ahmadi","99dd33333",22);
    Student s("ali", "akbari", "99dd33333", 33, "akbari", 2, &b);

}
