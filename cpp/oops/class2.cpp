#include<iostream>
#include<string>
using namespace std;

//Inheritance Example with Constructor and Destructor

class Person{
public:
    string name;
    int age;

    Person(){
        cout << "Parent constructor called"<<endl; // First parent is called then child
        name="Unknown";
        age=0;
    }
    ~Person(){
        cout << "Parent destructor called"<<endl;
    }
    Person(string n, int a){
        name=n; // this->name=n;
        age=a;  // this->age=a;
    }
};

class Student: public Person{  //Inheritance of Person class
    //name, age, rollNo
public:
    int rollno;

    Student(){
        cout << "Child constructor called"<<endl;
        rollno = 0;
    }
    Student(string name, int age, int rollno) : Person(name,age){
        cout << "Child parameterized constructor called"<<endl;
        this->rollno = rollno;
    }
    ~Student(){ //First child is called then parent
        cout << "Child destructor called"<<endl;
    }
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Roll No: "<<rollno<<endl;
    }
};

int main(){
    Student s1("ABC", 20, 101);
    s1.getInfo();
    return 0;
}