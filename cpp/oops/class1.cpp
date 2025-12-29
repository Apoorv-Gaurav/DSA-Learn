#include <iostream>
#include <string>
using namespace std;

class Teacher{
private:
double salary;
public:
    //properties
    string name;
    string dept;
    string subject;
    

    //method
    void chageDept(string newDept){
        dept = newDept;
    }

    //setter
    void setSalary(double s){
        salary = s;
    }
    //getter
    double getSalary(){
        return salary;
    }

};

class Student{
public:
    //properties
    string name;
    string subject;
    int rollNo;

};

int main(){
    Teacher t1;
    t1.name = "ABCD";
    t1.subject = "Maths";
    t1.dept = "Science";
    //t1.salary = 50000.00; //private member cannot be accessed directly

    cout<<"Name: "<<t1.name<<endl;
    cout<<"Subject: "<<t1.subject<<endl;
    return 0;
}
