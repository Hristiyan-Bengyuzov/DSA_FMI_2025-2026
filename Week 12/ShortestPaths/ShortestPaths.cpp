// https://www.hackerrank.com/contests/6-20232024/challenges/shortest-paths-2/copy-from/1386711781
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long MOD = 1e9 + 7;

struct Edge {
	int to;
	long long weight;
};

struct Node {
	int index;
	long long distance;

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<Edge>> graph(n + 1);

	for (size_t i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		long long c;
		cin >> c;

		graph[u].push_back({ v, c });
	}

	vector<long long> distances(n + 1, LLONG_MAX);
	vector<long long> ways(n + 1);
	int start = 1;

	distances[start] = 0;
	ways[start] = 1;

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		Node currNode = pq.top(); pq.pop();

		if (currNode.distance > distances[currNode.index])
			continue;

		for (const Edge& edge : graph[currNode.index]) {
			long long newWeight = currNode.distance + edge.weight;

			if (newWeight < distances[edge.to])
			{
				distances[edge.to] = newWeight;
				ways[edge.to] = ways[currNode.index];
				pq.push({ edge.to, newWeight });
			}
			else if (newWeight == distances[edge.to])
			{
				ways[edge.to] = (ways[edge.to] + ways[currNode.index]) % MOD;
			}
		}
	}

	cout << (distances[n] == LLONG_MAX ? -1 : distances[n]) << " " << ways[n];
}
