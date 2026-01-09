// https://www.hackerrank.com/contests/sda-hw-11-2023/challenges/challenge-4505
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
	int to;
	long long time;
};

struct Node {
	int index;
	long long time;

	bool operator>(const Node& other) const {
		return time > other.time;
	}
};

int main()
{
	int V, E, s, e;
	cin >> V >> E >> s >> e;

	vector<int> times(V);
	for (size_t i = 0; i < V; i++)
		cin >> times[i];

	vector<vector<Edge>> graph(V);
	for (size_t i = 0; i < E; i++)
	{
		int u, v;
		long long c;
		cin >> u >> v >> c;
		graph[u].push_back({ v,c });
	}

	vector<long long> distances(V, INT_MAX);
	distances[s] = 0;

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push({ s, 0 });

	while (!pq.empty())
	{
		Node curr = pq.top(); pq.pop();

		if (curr.time > distances[curr.index])
			continue;

		for (const Edge& edge : graph[curr.index]) {
			long long neededTime = curr.time % times[curr.index];
			long long waitTime = neededTime != 0 ? times[curr.index] - neededTime : 0;
			long long newTime = curr.time + waitTime + edge.time;

			if (newTime < distances[edge.to])
			{
				distances[edge.to] = newTime;
				pq.push({ edge.to, newTime });
			}
		}
	}

	cout << (distances[e] == INT_MAX ? -1 : distances[e]);
}
