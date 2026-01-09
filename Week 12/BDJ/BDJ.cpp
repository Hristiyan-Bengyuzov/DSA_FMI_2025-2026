// https://www.hackerrank.com/contests/sda-hw-11/challenges/1-143
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
	int to;
	long long weight;
	bool isRail;
};

struct Node {
	int index;
	long long distance;

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
};

vector<bool> dijkstra(vector<vector<Edge>>& graph, int n) {
	vector<long long> distances(n + 1, LLONG_MAX);
	vector<bool> usedRail(n + 1, false);
	distances[1] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ 1, 0 });

	while (!pq.empty())
	{
		Node currNode = pq.top(); pq.pop();

		if (currNode.distance > distances[currNode.index])
			continue;

		for (const Edge& edge : graph[currNode.index]) {
			long long newDist = currNode.distance + edge.weight;

			if (newDist < distances[edge.to])
			{
				distances[edge.to] = newDist;
				usedRail[edge.to] = edge.isRail;
				pq.push({ edge.to, newDist });
			}
			else if (newDist == distances[edge.to])
			{
				// prefer non rail ones
				if (!edge.isRail)
					usedRail[edge.to] = false;
			}
		}
	}

	return usedRail;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<Edge>> graph(n + 1);

	for (size_t i = 0; i < m; i++)
	{
		int u, v;
		long long c;
		cin >> u >> v >> c;
		graph[u].push_back({ v,c,false });
		graph[v].push_back({ u,c,false });
	}


	for (size_t i = 0; i < k; i++)
	{
		int u;
		long long c;
		cin >> u >> c;
		graph[u].push_back({ 1,c,true });
		graph[1].push_back({ u,c,true });
	}

	vector<bool> used = dijkstra(graph, n);
	int neededRailRoads = 0;
	for (size_t i = 2; i <= n; i++)
	{
		if (used[i])
			neededRailRoads++;
	}

	cout << k - neededRailRoads;
}
