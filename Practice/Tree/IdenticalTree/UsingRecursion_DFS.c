#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

bool isIdentical(struct Node* r1, struct Node* r2) {

    // If both trees are empty, they are identical
    if (r1 == NULL && r2 == NULL)
        return true;

    // If only one tree is empty, they are not identical
    if (r1 == NULL || r2 == NULL)
        return false;

    // Check if the root data is the same and
    // recursively check for the left and right subtrees
    return (r1->data == r2->data) &&
           isIdentical(r1->left, r2->left) &&
           isIdentical(r1->right, r2->right);
}

struct Node* createNode(int val) {
    struct Node *newNode 
      = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {

    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    struct Node *r1 = createNode(1);
    r1->left = createNode(2);
    r1->right = createNode(3);
    r1->left->left = createNode(4);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      2   3
    //     /
    //    4
    struct Node *r2 = createNode(1);
    r2->left = createNode(2);
    r2->right = createNode(3);
    r2->left->left = createNode(4);

    if (isIdentical(r1, r2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}