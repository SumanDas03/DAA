#include <iostream>
#include <climits>
using namespace std;

int cost[10][10], n;

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
}

void primMST() {
    int parent[10];
    int key[10];
    bool mstSet[10];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (cost[u][v] && mstSet[v] == false && cost[u][v] < key[v])
                parent[v] = u, key[v] = cost[u][v];
    }

    printMST(parent);
}

int main() {
    int m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = 0;

    cout << "\nEDGES (format: start_vertex end_vertex weight):\n";
    for (int k = 0; k < m; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        cost[i][j] = w;
        cost[j][i] = w;  // Since it's an undirected graph
    }

    primMST();

    return 0;
}
