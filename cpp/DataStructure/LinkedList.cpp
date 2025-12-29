#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    /*
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(){
        next = nullptr;
    } */
    
};

// Head pointer
Node* head = NULL;

/* ---------------- CREATE (Insert at end) ---------------- */
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value; //(*newNode).data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* ---------------- READ (Display) ---------------- */
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/* ---------------- UPDATE (Search & Modify) ---------------- */
void update(int oldValue, int newValue) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            cout << "Value updated successfully\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found\n";
}

/* ---------------- DELETE (By value) ---------------- */
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // If head node is to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted\n";
        return;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    cout << "Node deleted\n";
}

/* ---------------- MAIN ---------------- */
int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    update(20, 25);
    display();

    deleteNode(10);
    display();

    return 0;
}
  