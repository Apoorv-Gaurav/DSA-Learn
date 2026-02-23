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
struct Node *reverseList(struct Node *head) {
    
    struct Node *stack[100000];
    int top = -1;
    struct Node *temp = head;

    // push all nodes into stack
    while (temp != NULL) {
        stack[++top] = temp;
        temp = temp->next;
    }

    // make the last node as new head of the linked list
    if (top >= 0) {
        head = stack[top];
        temp = head;

        // pop all the nodes and append to the linked list
        while (top > 0) {
            
            // append the top value of stack in list
            temp->next = stack[--top];

            temp = temp->next;
        }

        // update the next pointer of last node of stack to null
        temp->next = NULL;
    }

    return head;
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
    head = reverseList(head);

    printf("Reversed List:\n");
    printfLL();

    return 0;
}
