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
int getMiddle(){
    struct Node* slow = head;
    struct Node* fast = head;
    if(head==NULL){
        return -1;
    }
    while(fast!=NULL && fast->next !=NULL){ //Careful  //AND
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;

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
    while(temp->next != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d -> NULL\n",temp->data); //Carefull
}
int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        insertNode(arr[i]);
    }
    printfLL();
    printf("The middle element is: %d ",getMiddle());
}






















/*
int getMiddle(struct Node* head) {
  
    struct Node* slowptr = head;
    struct Node* fastptr = head;

    // traverse the linked list
    while (fastptr != NULL && fastptr->next != NULL) {
      
        // move the fast pointer by two nodes
        fastptr = fastptr->next->next;

        // move the slow pointer by one node
        slowptr = slowptr->next;
    }

    return slowptr->data;
}

struct Node* createNode(int x) {
    struct Node* newNode =
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printf("%d\n", getMiddle(head));

    return 0;
}
    */