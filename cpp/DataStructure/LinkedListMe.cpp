#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    
    
    Node(int val){
        data = val;
        next = NULL;
    }
        
};

class List{
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); //dynamic memory allocation
        //Node newNode(val); //static memory allocation
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        } 
        else {
            newNode->next = head; //(*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            return;
        }
        else{
            
        }
    }
    
    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
//push-front
//push-back
//pop-front
//pop-back

int main(){
    List ll;

    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);

    ll.printLL();
    return 0;
}

