#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, size;
    vector<long long> componentWeight;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        componentWeight.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    bool unite(int a, int b, int weight) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        componentWeight[a] += weight + componentWeight[b];

        return true;
    }

    int getComponentSize(int node) {
        return size[find(node)];
    }

    long long getComponentWeight(int node) {
        return componentWeight[find(node)];
    }
};

long long solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);

    for (const Edge& edge : edges) {
        dsu.unite(edge.u, edge.v, edge.weight);
    }

    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) { 
            int componentSize = dsu.getComponentSize(i);

            if (componentSize % k == 0) {
                totalSum += dsu.getComponentWeight(i);
            }
        }
    }

    return totalSum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}