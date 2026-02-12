// Uses curr, prev, nxt head

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *temp = NULL;

void reverseLL(){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *nxt = NULL;

    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    
    /*
    while(curr->next != NULL){  
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    curr->next = prev;
    head = curr;
    */
}



void insertNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void printfLL(){
    if(head == NULL){
        printf("NULL");
        return;
    }
    temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        insertNode(arr[i]);
    }
    printfLL();
    reverseLL();
    printfLL();
    return 0;
}