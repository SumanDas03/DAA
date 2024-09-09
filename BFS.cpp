#include <iostream>
#include <queue>
using namespace std;

int cost[10][10] = {0}, visited[10] = {0};

void bfs(int v, int n) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    cout << "BFS ORDER OF VISITED VERTICES: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int j = 1; j <= n; j++) {
            if (cost[current][j] != 0 && !visited[j]) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

int main() {
    int n, m, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEDGES (format: start_vertex end_vertex):\n";
    for (int k = 1; k <= m; k++) {
        int i, j;
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;  // Since it's an undirected graph
    }

    cout << "Enter initial vertex to traverse from: ";
    cin >> v;

    bfs(v, n);

    return 0;
}
