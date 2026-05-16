#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;






// Graph using adjacency list
vector<vector<int>> graph = {
    {1, 2},      // 0 connected to 1,2
    {0, 3},      // 1 connected to 0,3
    {0, 3},      // 2 connected to 0,3
    {1, 2, 4},   // 3 connected to 1,2,4
    {3}          // 4 connected to 3
};

// DFS (Recursive)
void dfsRecursive(int node, vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;

    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfsRecursive(neighbor, visited);
        }
    }
}


// DFS (Iterative using Stack)
void dfsIterative(int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    s.push(start);

    while(!s.empty()) {
        int node = s.top();
        s.pop();

        if(!visited[node]) {
            cout << node << " ";
            visited[node] = true;

            // push neighbors (reverse for same order as recursive)
            for(int i = graph[node].size() - 1; i >= 0; i--) {
                int neighbor = graph[node][i];
                if(!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

// BFS (Queue)
void bfs(int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {

    vector<bool> visited(graph.size(), false);

    cout << "DFS (Recursive): ";
    dfsRecursive(0, visited);

    cout << "\nDFS (Iterative): ";
    dfsIterative(0);

    cout << "\nBFS: ";
    bfs(0);

    cout << endl;
    return 0;
}