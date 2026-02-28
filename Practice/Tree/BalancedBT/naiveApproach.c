// O(n2) Time and O(h) Space

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h> 

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

// Function to calculate the height of a tree
int height(Node* node) {
   
    if (node == NULL)
        return 0;

    // Height = 1 + max of left height and right heights
    int lHeight = height(node->left);
    int rHeight = height(node->right);
    return 1 + (lHeight > rHeight ? lHeight : rHeight);
}

// Function to check if the binary tree with given root, is height-balanced
bool isBalanced(Node* root) {
    
    if (root == NULL)
        return true;

    // Get the height of left and right sub trees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if (abs(lHeight - rHeight) > 1)
        return false;

    // Recursively check the left and right subtrees
    //return isBalanced(root->left) && isBalanced(root->right);

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    return (left && right);
}

int main() {
    
    // Representation of input BST:
    //            10
    //           / \
    //          20   30
    //         /  \
    //        40   60
    Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(60);

    printf("%s\n", isBalanced(root) ? "true" : "false");
    return 0;
}