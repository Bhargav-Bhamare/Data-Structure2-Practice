#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Graph size constant
const int SIZE = 5;

// Adjacency matrix
int graph[SIZE][SIZE] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,0},
    {0,1,1,0,1},
    {0,0,0,1,0}
};

// Visited array
int visited[SIZE];

// Function to reset visited array
void resetVisited() {
    for(int i = 0; i < SIZE; i++) {
        visited[i] = 0;
    }
}

// Function to display visited array (extra)
void showVisited() {
    cout << "\nVisited Status: ";
    for(int i = 0; i < SIZE; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;
}

// Recursive DFS
void dfs(int v) {

    // Visit node
    cout << v << " ";
    visited[v] = 1;

    // Explore neighbors
    for(int i = 0; i < SIZE; i++) {

        // Check connection
        if(graph[v][i] == 1) {

            // Check if not visited
            if(visited[i] == 0) {
                dfs(i);
            }
        }
    }
}

// Iterative DFS using stack
void explore(int start) {

    stack<int> s;

    // Push starting node
    s.push(start);
    visited[start] = 1;

    while(!s.empty()) {

        // Get top element
        int currentNode = s.top();
        s.pop();

        // Print node
        cout << currentNode << " ";

        // Traverse neighbors in reverse
        for(int i = SIZE - 1; i >= 0; i--) {

            if(graph[currentNode][i] == 1 && visited[i] == 0) {

                s.push(i);
                visited[i] = 1;
            }
        }
    }
}

// BFS using queue
void bfs(int start) {

    queue<int> q;

    // Insert start node
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {

        // Get front element
        int currentNode = q.front();
        q.pop();

        // Print node
        cout << currentNode << " ";

        // Traverse neighbors
        for(int i = 0; i < SIZE; i++) {

            if(graph[currentNode][i] == 1) {

                if(visited[i] == 0) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}

int main() {

    cout << "DFS (Recursive): ";
    dfs(0);

    // Reset visited for next traversal
    resetVisited();

    cout << "\nDFS (Iterative using Stack): ";
    explore(0);

    // Reset again
    resetVisited();

    cout << "\nBFS (Using Queue): ";
    bfs(0);

    cout << endl;

    return 0;
}