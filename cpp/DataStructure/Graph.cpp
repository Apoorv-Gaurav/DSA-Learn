#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

 public:
    Graph(int v) : V(v), adj(v){}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start){
        vector<bool> visited(V,false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout<<"BFS: ";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<" ";
            for(int nb : adj[node])
                if(!visited[nb]){ visited[nb] = true; q.push(nb);}
        }
        cout<<"\n";
    }

    void DFSHelper(int node, vector<bool>& visited){
        visited[node] = true;
        cout<<node<<" ";
        for(int nb : adj[node])
            if(!visited[nb]) DFSHelper(nb, visited);
    }

    void DFS(int start){
        vector<bool> visited(V, false);
        cout<<"DFS: ";
        DFSHelper(start, visited);
        cout<< "\n";
    }
};

int main(){
    Graph g(6);    //nodes 1 to 5(index 0 unused)
    
    g.addEdge(1,2);
    //g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.BFS(1); //1 2 3 4 5
    g.DFS(1); //1 2 4 5 3
}


/*
class Graph{
    int V;
    vector<vector<int>> adj;
    public:
    Graph(int v){
        V=v;
        adj = vector<vector<int>>(v);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int start){
        bool visited[V] = {false};
        queue<int> q;
        cout<<"BFS: ";
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int nb:adj[node]){
                if(!visited[nb]){
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        cout<<"\n";
    }
    void DFSHelper(int node, vector<bool>& visited){
        visited[node] = true;
        cout<<node<<" ";
        for(int nb:adj[node]){
            if(!visited[nb]){
                DFSHelper(nb,visited);
            }
        }
    }
    void DFS(int start){
        vector<bool> visited(V,false);
        cout<<"DFS: ";
        DFSHelper(start,visited);
        cout<<"\n";
    }
};

int main(){
    Graph g(6);

    return 0;
}
    */