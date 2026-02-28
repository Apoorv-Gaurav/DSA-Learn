#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int d) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = d;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function that returns the height of the tree if the tree is balanced
// Otherwise it returns -1.
int isBalancedRec(Node* root) {
    if (root == NULL)
        return 0;

    // Find Heights of left and right sub trees
    int lHeight = isBalancedRec(root->left);
    int rHeight = isBalancedRec(root->right);

    // If either the subtrees are unbalanced or the absolute difference  
    // of their heights is greater than 1, return -1
    if (lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
        return -1;

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

// Function to check if tree is height balanced
int isBalanced(Node* root) {
    return isBalancedRec(root) > 0;
}

int main() {
    // Representation of input BST:
    //            10
    //           / \
    //          20  30
    //         /  \
    //       40    60
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(60);

    printf("%s", isBalanced(root) ? "true" : "false");
    return 0;
}