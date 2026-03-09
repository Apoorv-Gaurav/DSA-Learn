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
struct Node* buildTree(int inorder[], int preorder[], int start, int end) {

    static int preIndex = 0;   // first element in preorder

    if(start > end)
        return NULL;

    // Create node using preorder
    struct Node* root = createNode(preorder[preIndex]);
    preIndex++;

    // If leaf node
    if(start == end)
        return root;

    // Find root in inorder
    int pos = search(inorder, start, end, root->data);

    // Build left subtree
    root->left = buildTree(inorder, preorder, start, pos - 1);

    // Build right subtree
    root->right = buildTree(inorder, preorder, pos + 1, end);

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
    int preorder[] = {1,2,4,5,3,6};

    int n = 6;

    struct Node* root = buildTree(inorder, preorder, 0, n-1);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}