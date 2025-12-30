#include<iostream>
#include<string>
using namespace std;

//Polymorphism Example
//Functon Overriding using Inheritance
//Virtual Function Example
class Parent{
public:
    void getInfo(){
        cout<<"I am Parent class"<<endl;
    }
    virtual void hello(){
        cout<<"Hello from Parent"<<endl;
    }
};

class Child: public Parent{
public:
    void getInfo(){
        cout<<"I am Child class"<<endl;
    }
    void hello(){
        cout<<"Hello from Child"<<endl;
    }
};

int main(){
    Parent c1;
    c1.getInfo();
    Child c2;
    c2.getInfo();

    c1.hello();
    c2.hello();


    return 0;
}
