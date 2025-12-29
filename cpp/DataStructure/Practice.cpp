#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data=data1;
        next = next1;
    }
};

int main(){
    Node y = Node(4,NULL);
    cout << y.data;
    return 0;
}