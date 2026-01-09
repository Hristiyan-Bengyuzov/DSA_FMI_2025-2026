// https://www.hackerrank.com/contests/test6sda-renfuvidbviw/challenges/challenge-2326
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
	int to, weight;
};

struct Node {
	int index, distance;

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
};

vector<int> dijkstra(int start, int n, vector<vector<Edge>>& graph) {
	vector<int> distances(n + 1, INT_MAX);
	distances[start] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		Node currNode = pq.top(); pq.pop();

		if (currNode.distance > distances[currNode.index])
			continue;

		for (const Edge& edge : graph[currNode.index]) {
			int newWeight = currNode.distance + edge.weight;

			if (newWeight < distances[edge.to])
			{
				distances[edge.to] = newWeight;
				pq.push({ edge.to, newWeight });
			}
		}
	}

	return distances;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<Edge>> graph(n + 1);

	for (size_t i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	int start;
	cin >> start;

	vector<int> distances = dijkstra(start, n, graph);

	for (size_t i = 1; i <= n; i++)
	{
		if (i != start)
			cout << (distances[i] == INT_MAX ? -1 : distances[i]) << " ";
	}
}
