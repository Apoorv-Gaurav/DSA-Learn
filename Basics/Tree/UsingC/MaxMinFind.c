#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
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

    return root;
}

int findMin(struct Node *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int findMax(struct Node *root){
    if(root == NULL){
        printf("Tree is empty!\n");
        return -1;
    }

    while(root->right != NULL){
        root = root->right;
    }

    return root->data;
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 30);

    printf("Minimum Value = %d\n", findMin(root));
    printf("Maximum Value = %d\n", findMax(root));

    return 0;
}
