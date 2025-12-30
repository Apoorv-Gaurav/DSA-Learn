#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    // properties
    string name;
    string dept;
    string subject;

    Teacher()
    { // constructor //Called automatically when object is created
        dept = "CSE";
    }

    Teacher(string dept)
    { // parameterized constructor
        this->dept = dept; // t1.dept = dept;
        /*
        this is a pointer that stores the address of the current object.
            In simple words:
                this points to the object that is calling the function.
        this->dept → class variable
        dept → parameter variable
        */
    }

    Teacher(Teacher &orgobj)
    { // copy constructor //Pass by reference
        this->name = orgobj.name;
        this->dept = orgobj.dept;
        this->subject = orgobj.subject;
        this->salary = orgobj.salary;
    }

    // method
    void chageDept(string newDept)
    {
        dept = newDept;
    }

    // setter
    void setSalary(double s)
    {
        salary = s;
    }
    // getter
    double getSalary()
    {
        return salary;
    }
};

class Student
{
public:
    // properties
    string name;
    double* cgpaPtr;

    Student(string n, double c)
    {
        name = n;
        //cgpa = c;
        cgpaPtr = new double; // dynamic memory allocation
        *cgpaPtr = c;
    }
    //Default copy constructor performs shallow copy
    // Student(Student &obj){
    //     name = obj.name;
    //     cgpaPtr = obj.cgpaPtr; //shallow copy
    // }

    // Construnctor for deep copy
    Student(Student &obj)
    { 
        name = obj.name;
        cgpaPtr = new double;          // allocate new memory
        *cgpaPtr = *(obj.cgpaPtr);    // copy the value
    }

    //Destructor
    ~Student() //No need to call explicitly, called automatically when object goes out of scope
    {
        cout << "Destructor called for " << name << endl;
        delete cgpaPtr; // free the allocated memory preventing memory leak
    }

    void getinfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
        cout << endl;
    }
};

int main()
{
    Teacher t1; // constructor call
    t1.name = "ABCD";
    t1.subject = "Maths";
    t1.dept = "Science";
    // t1.salary = 50000.00; //private member cannot be accessed directly

    // Teacher t2(t1); // DEFAULT copy constructor call

    Teacher t2(t1); // custom copy constructor call (if defined)

    cout << "Name: " << t1.name << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Department: " << t1.dept << endl;

    Student s1("XYZ", 3.75);
    Student s2(s1); // default copy constructor
    *(s2.cgpaPtr) = 3.85; // modifying s2's cgpa
    s2.name = "PQR";
    s1.getinfo();
    s2.getinfo();

    return 0;
}
