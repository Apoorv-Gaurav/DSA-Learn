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
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    } 

    void pop_back(){
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int pos, int val){
        if(pos < 0){
            cout<<"Invalid position"<<endl;
            return;
        }

        Node* newNode = new Node(val);
        if(pos == 0){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1 && temp!=NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Position out of bounds"<<endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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
//insert
//printLL

int main(){
    List ll;

    // ll.push_front(10);
    // ll.push_front(20);
    // ll.push_front(30);
    // ll.push_back(40);
    // ll.push_back(50);
    // ll.pop_back();
    // ll.pop_front();
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printLL();
    return 0;
}

