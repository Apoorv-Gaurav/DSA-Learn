//Using Single Traversal - O(n) Time and O(h) Space
/*
The core idea is to efficiently calculate the diameter, 
avoiding redundant height calculations. We use recursion 
to find both height and diameter in a single traversal. 
For each node, the longest path through it is the sum of its left and right subtree heights. 
By tracking the maximum diameter, we find the longest path.*/

#include<stdio.h>
#include<stdlib.h>

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

struct Node* insert(struct Node *root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

// Global variable to store the maximum diameter
int maxDiameter = 0;

int diameterRecur(struct Node* root){  //Modify heigth to diameterRecur
    if(root == NULL) return 0;  

    int left = diameterRecur(root->left);
    int right = diameterRecur(root->right);

    if(left+right > maxDiameter) maxDiameter = left+right;

    return (left > right ? left : right) + 1;
}

// Function to get diameter of a binary tree
int diameter(struct Node* root) {
    maxDiameter = 0; 
    diameterRecur(root);
    return maxDiameter;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    struct Node* root = NULL;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 30);
    insert(root, 1);
    insert(root, 4);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n\n");

    int dia = diameter(root);
    printf("%d", dia);

    return 0;
}