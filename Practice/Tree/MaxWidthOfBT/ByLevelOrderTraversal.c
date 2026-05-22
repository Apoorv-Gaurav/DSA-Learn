//Level Order Traversal (Breadth-First Search – BFS)
// Time : O(n)   Space: O(n)
#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure (stores node + index)
struct Pair {
    struct TreeNode* node;
    long long index;   // use long long to avoid overflow
};

// Function to get maximum width
int maximumWidth(struct TreeNode* root) {
    
    if (root == NULL)
        return 0;

    // Create queue (Assume max 10000 nodes)
    struct Pair queue[10000];
    int front = 0, rear = 0;

    // Push root with index 0
    queue[rear].node = root;
    queue[rear].index = 0;
    rear++;

    int maxWidth = 0;

    while (front < rear) {

        int size = rear - front;   // number of nodes in current level
        long long minIndex = queue[front].index;

        long long first = 0, last = 0;

        for (int i = 0; i < size; i++) {

            struct TreeNode* currNode = queue[front].node;
            long long currIndex = queue[front].index - minIndex;
            front++;

            if (i == 0)
                first = currIndex;

            if (i == size - 1)
                last = currIndex;

            if (currNode->left != NULL) {
                queue[rear].node = currNode->left;
                queue[rear].index = 2 * currIndex + 1;
                rear++;
            }

            if (currNode->right != NULL) {
                queue[rear].node = currNode->right;
                queue[rear].index = 2 * currIndex + 2;
                rear++;
            }
        }

        int width = (int)(last - first + 1);

        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}