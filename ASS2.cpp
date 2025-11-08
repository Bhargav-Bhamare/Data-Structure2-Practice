#include <iostream>
using namespace std;

int parent[10];

// ---------- Find parent ----------
int find(int i) {
    while (parent[i] != i)
    i =parent[i];
    return i;
}

// ---------- Union ----------
void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// ---------- Kruskal's Algorithm ----------
void kruskal(int cost[5][5], int n) {
    for (int i = 0; i < n; i++) parent[i] = i;
    int edge = 0, mincost = 0;   
    while (edge < n - 1) {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i; b = j;
                }

        union1(a, b);
        cout << a << " - " << b << " : " << min << endl;
        mincost += min;
        edge++;
    }
    cout << "Total Cost = " << mincost << endl;
}

// ---------- Prim's Algorithm ----------
void prim(int cost[5][5], int n) {
    int selected[10] = {0};
    selected[0] = 1;
    int edges = 0, mincost = 0;

    while (edges < n - 1) {
        int min = 999, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j]) {
                        if (min > cost[i][j]) {
                            min = cost[i][j];
                            x = i; y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << " : " << cost[x][y] << endl;
        mincost += cost[x][y];
        selected[y] = 1;
        edges++;
    }
    cout << "Total Cost = " << mincost << endl;
}

// ---------- Main Function ----------
int main() {
    int n = 5;
    int cost[5][5] = {
        {999, 2, 999, 6, 999},
        {2, 999, 3, 8, 5},
        {999, 3, 999, 999, 7},
        {6, 8, 999, 999, 9},
        {999, 5, 7, 9, 999}
    };

    kruskal(cost, n);
    prim(cost, n);
    return 0;
}
