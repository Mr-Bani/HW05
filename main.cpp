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
    //Person p("ali","ahmadi","99dd33333",22);
    Student s("ali", "akbari", "99*d33333", 33, "akbari", 2, &b);


}
