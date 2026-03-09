#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Search element in inorder array
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Construct tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end) {

    static int postIndex = 5;   // last index of postorder

    if(start > end)
        return NULL;

    // Take root from postorder
    struct Node* root = createNode(postorder[postIndex]);
    postIndex--;

    // If leaf node
    if(start == end)
        return root;

    // Find root in inorder
    int pos = search(inorder, start, end, root->data);

    // Build right subtree first
    root->right = buildTree(inorder, postorder, pos + 1, end);

    // Build left subtree
    root->left = buildTree(inorder, postorder, start, pos - 1);

    return root;
}

// Print inorder to verify tree
void printInorder(struct Node* root) {
    if(root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {

    int inorder[] = {4,2,5,1,6,3};
    int postorder[] = {4,5,2,6,3,1};

    int n = 6;

    struct Node* root = buildTree(inorder, postorder, 0, n-1);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}