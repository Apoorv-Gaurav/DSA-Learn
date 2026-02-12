#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *temp = NULL;

// Insert at end
void insertNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print Linked List
void printfLL(){
    if(head == NULL){
        printf("NULL\n");
        return;
    }

    temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 🔁 Recursive Reverse Function
struct Node* reverseRecursive(struct Node* curr){

    // Base Case
    if(curr == NULL || curr->next == NULL){
        return curr;
    }

    // Reverse remaining list
    struct Node* newHead = reverseRecursive(curr->next); //newHead or rest

    // Reverse current link
    curr->next->next = curr;
    curr->next = NULL;

    return newHead;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        insertNode(arr[i]);
    }

    printf("Original List:\n");
    printfLL();

    // Reverse using recursion
    head = reverseRecursive(head);

    printf("Reversed List:\n");
    printfLL();

    return 0;
}
