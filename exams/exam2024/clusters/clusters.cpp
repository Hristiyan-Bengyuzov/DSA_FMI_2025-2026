// https://www.hackerrank.com/contests/2024-2025-2/challenges/clusterstask
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
	int from, to, weight;
	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

struct DSU {
	vector<int> parent, size, maxWeight;

	int n;

	DSU(int n) : n(n) {
		parent.resize(n);
		size.resize(n, 1);
		maxWeight.resize(n, 0);

		for (size_t i = 0; i < n; i++)
		{
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
		maxWeight[a] = max(max(maxWeight[a], maxWeight[b]), weight);
		n--;
		return true;
	}

	int getComps() const {
		return n;
	}

	int getMaxWeight(int node) {
		return maxWeight[find(node)];
	}
};

int main()
{
	int v, e, k;
	cin >> v >> e >> k;

	vector<Edge> edges(e);

	for (size_t i = 0; i < e; i++)
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;


	sort(edges.begin(), edges.end());
	DSU du(v);
	vector<Edge> used;

	for (const Edge& edge : edges) {
		if (du.getComps() == k)
			break;

		if (du.unite(edge.from, edge.to, edge.weight))
		{
			used.push_back(edge);
		}
	}

	vector<int> res;
	for (size_t i = 0; i < v; i++)
	{
		if (du.find(i) == i)
		{
			res.push_back(du.getMaxWeight(i));
		}
	}

	sort(res.begin(), res.end());
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}
