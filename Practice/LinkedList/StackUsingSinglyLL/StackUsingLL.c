#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *top = NULL;

bool isEmpty(){
    return (top==NULL);
}

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack\n", val);
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    int popped = top->data;
    struct Node *del = top;
    top = top->next;
    free(del);
    return popped;
}

int peek(){
    if(isEmpty()){
        printf("Stack is Empty\n");
        return -1;
    }
    return top->data;
}

void display(){
    if(isEmpty()){
        printf("Stack is Empty\n");
        return;
    }
    struct Node *temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    push(10);
    push(20);
    push(30);

    display();

    printf("Popped: %d\n", pop());

    printf("Top element: %d\n", peek());

    display();

    return 0;
}