#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* delete deepest node */
void deleteDeepest(struct Node *root, struct Node *d_node){
    struct Node *queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while(front <= rear){
        struct Node *temp = queue[front++];

        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                free(d_node);
                return;
            }
            queue[++rear] = temp->left;
        }

        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                free(d_node);
                return;
            }
            queue[++rear] = temp->right;
        }
    }
}

/* delete node from tree */
struct Node* deleteNode(struct Node *root, int key){

    if(root == NULL)
        return NULL;

    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
            free(root);
            return NULL;
        }
        else
            return root;
    }

    struct Node *queue[100];
    int front = 0, rear = -1;

    struct Node *temp;
    struct Node *keyNode = NULL;

    queue[++rear] = root;

    while(front <= rear){
        temp = queue[front++];

        if(temp->data == key)
            keyNode = temp;

        if(temp->left)
            queue[++rear] = temp->left;

        if(temp->right)
            queue[++rear] = temp->right;
    }

    if(keyNode != NULL){
        int x = temp->data;   // deepest node data
        deleteDeepest(root, temp);
        keyNode->data = x;
    }

    return root;
}

/* level order traversal */
void levelOrder(struct Node *root){
    struct Node *queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while(front <= rear){
        struct Node *temp = queue[front++];

        printf("%d ", temp->data);

        if(temp->left)
            queue[++rear] = temp->left;

        if(temp->right)
            queue[++rear] = temp->right;
    }
}

/* main */
int main(){

    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Original Tree (Level Order):\n");
    levelOrder(root);

    root = deleteNode(root, 2);

    printf("\nAfter Deleting 2:\n");
    levelOrder(root);

    return 0;
}