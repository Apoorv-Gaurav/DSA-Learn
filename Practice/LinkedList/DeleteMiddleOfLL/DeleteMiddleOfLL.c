//One-Pass Traversal with Slow and Fast Pointers - O(n) Time and O(1) Space

//Hare and Tortoise Algorithm 
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
//createNode
//getMiddle
void deleteMiddle(){
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev;
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        return;
    }

    while(fast!=NULL && fast->next !=NULL){ //Careful  //AND
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = prev->next->next;
    free(slow);
    return;

}

void insertNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printfLL(){
    struct Node *temp = head;
    if (head==NULL){
        printf("NULL");
        return;
    }
    while(temp!= NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); //Carefull
}
int main(){
    int arr[] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        insertNode(arr[i]);
    }
    printfLL();
    deleteMiddle();
    printfLL();
}