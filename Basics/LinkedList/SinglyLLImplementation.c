
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertAtB(struct Node *head, int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtE(struct Node *head, int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* deleteFromB(struct Node *head){
    if(head == NULL){
        printf("LL is empty");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteFromE(struct Node *head){
    if(head == NULL){
        printf("LL is empty");
        return head;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return head;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void traverse(struct Node *head){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    // Demo values
    head = insertAtB(head, 10);
    head = insertAtB(head, 5);
    head = insertAtE(head, 20);
    head = insertAtE(head, 30);

    printf("Linked List:\n");
    traverse(head);

    head = deleteFromB(head);
    printf("After deleting from beginning:\n");
    traverse(head);

    head = deleteFromE(head);
    printf("After deleting from end:\n");
    traverse(head);

    return 0;
}
