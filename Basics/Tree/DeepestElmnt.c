#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* deepestNode(struct Node* root){

    struct Node* queue[100];
    int front = 0;
    int rear = -1;

    if(root == NULL)
        return NULL;

    queue[++rear] = root;

    struct Node* temp = NULL;

    while(front <= rear){
        temp = queue[front++];

        if(temp->left != NULL)
            queue[++rear] = temp->left;

        if(temp->right != NULL)
            queue[++rear] = temp->right;
    }

    return temp; // last visited node
}

int main(){

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
               /
              7
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);
    root->right->right->left = createNode(7);

    struct Node* result = deepestNode(root);

    if(result != NULL)
        printf("Deepest Node: %d\n", result->data);

    return 0;
}