#include <iostream>
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "regex"


using namespace std;

bool validate(string id) {
    string reg = "(^[8][4-9]|[9][0-9]| [0][0])\\D{1,3}([0-3]|[7-9]){5}$";

    if(regex_match(id,regex(reg))){
        return true;
    }
    return false;
}
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
  //  Student s("ali", "akbari", "99*d33333", 33, "akbari", 3, a);
    //Student f = s;
    //cout<<f.calculateSalary();
//    cout<<f.validate();

    //printf("%20s %20s","alialia ali","ali");
string aaa="99";
string bbb = "98";
string ccc = "999aoierh";
ccc = ccc.substr(2);
cout<<ccc;




}
