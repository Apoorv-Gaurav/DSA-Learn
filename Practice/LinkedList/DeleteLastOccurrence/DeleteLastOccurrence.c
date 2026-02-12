
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void deleteLastOccurrence(int val){
    struct Node *last = NULL, *lastPrev = NULL;
    struct Node *temp = head, *prev = NULL;
    if(head==NULL){
        return;
    }
    if(head->next == NULL && head->data == val){
        free(head);
        head = NULL;
        return;
    }
    while(temp!=NULL){        //Careful
        if(temp->data == val){
            last = temp;
            lastPrev = prev;
        }
        prev= temp;
        temp = temp->next;
    }
    if(last == NULL){
        return;
    }
    if(last != NULL){
        if(lastPrev == NULL){
            head = head->next;
        }
        else{
            lastPrev->next = last->next;
        }
        free(last);
    }

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
    int arr[] = {1,2,3,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        insertNode(arr[i]);
    }
    printfLL();
    deleteLastOccurrence(1);
    printfLL();
}