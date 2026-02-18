


/*
Height = number of edges
Diameter of a binary tree = Number of edges in the longest path between any two nodes.
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

int findHeight(struct Node* root){
    if(root == NULL) return 0;  // Minor change // Thoda Socho Dimak

    int left = findHeight(root->left);
    int right = findHeight(root->right);

    return (left > right ? left : right) + 1;
}

// Function to get diameter of a binary tree
int diameter(struct Node* root) {
    if (root == NULL)
        return 0;

    // Get the height of left and right sub-trees
    int lheight = findHeight(root->left);
    int rheight = findHeight(root->right);

    // Diameter of current subtree 
    int curr = lheight+rheight;

    // Get the diameter of left and right sub-trees
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    
    if (ldiameter > rdiameter && ldiameter > curr)
        return ldiameter;
    else if (rdiameter > ldiameter && rdiameter > curr) 
        return rdiameter;
    return curr;
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