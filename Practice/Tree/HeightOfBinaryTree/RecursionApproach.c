/*
Time Complexity: O(n)
Space Complexity: O(n), Recursive stack space
*/

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
//------------------------------------------------------------------
int findHeight(struct Node* root){
    if(root == NULL) return -1;  // or 0 depending on definition

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return (left > right ? left : right) + 1;
}
//-------------------------------------------------------------------
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

    int height = findHeight(root);
    printf("%d", height);

    return 0;
}