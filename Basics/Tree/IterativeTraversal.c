#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;//No need
}
//Inorder (Left → Root → Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* Stack[100];
    int top = -1;
    struct Node* curr = root;
    while(curr!=NULL || top >-1){
        while(curr != NULL){
            Stack[++top] = curr;
            curr= curr->left;
        }
        curr = Stack[top--];
        printf("%d ",curr->data);
        curr = curr->right;
    }
}
//Preorder (Root → Left → Right)
void preorder(struct Node* root) {
    struct Node* Stack[100];
    int top = -1;
    if(root == NULL) return ;
    Stack[++top] = root;
    while(top>-1){
        struct Node* curr = Stack[top--];
        printf("%d ",curr->data);
        if(curr->right != NULL){
            Stack[++top] = curr->right;
        }
        if(curr->left != NULL){
            Stack[++top] = curr->left;
        }
    }

}
//Postorder (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 30);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n\n");

    return 0;
}
