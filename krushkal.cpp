#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

struct Edge {
    int u, v, w;
};

Edge edges[MAX];
int parent[MAX], n, m;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal() {
    Edge result[MAX];
    int e = 0;  // Index used for result
    int i = 0;  // Index used for sorted edges

    sort(edges, edges + m, [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < n; i++)
        parent[i] = i;

    while (e < n - 1 && i < m) {
        Edge next_edge = edges[i++];

        int x = find(next_edge.u);
        int y = find(next_edge.v);

        if (x != y) {
            result[e++] = next_edge;
            union_set(x, y);
        }
    }

    cout << "Edge \tWeight\n";
    for (i = 0; i < e; i++)
        cout << result[i].u << " - " << result[i].v << " \t" << result[i].w << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEDGES (format: start_vertex end_vertex weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    kruskal();

    return 0;
}
