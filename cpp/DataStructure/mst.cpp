#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Number of vertices in the graph
#define V 5

int findMinKey(int key[], bool inMST[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        // If node not in MST and key is smaller than current min
        if (inMST[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V]) {
    int parent[V];  // Array to store constructed MST
    int key[V];     // Values used to pick minimum weight edge
    bool inMST[V];  // To represent set of vertices included in MST

    // 1. Initialize all keys as INFINITY
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // 2. Start node initialization (using vertex 0)
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // 3. The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // a. Pick the minimum key vertex from the set of vertices not yet included
        int u = findMinKey(key, inMST);

        // b. Add the picked vertex to the MST Set
        inMST[u] = true;

        // c. Update key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // inMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && inMST[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    /* Let us create the following graph
        2    3
    (0)--(1)--(2)
     |   / \   |
    6| 8/   \5 |7
     | /     \ |
    (3)-------(4)
          9          */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}