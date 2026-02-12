#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *temp = NULL;

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
    return 0;
}