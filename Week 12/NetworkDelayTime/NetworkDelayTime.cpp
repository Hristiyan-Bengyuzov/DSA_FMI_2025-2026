#include <iostream>
#include <vector>
#include <queue>

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

class Solution {
private:
	vector<vector<Edge>> buildGraph(vector<vector<int>>& times, int n) {
		vector<vector<Edge>> graph(n + 1);
		for (const vector<int>& time : times) {
			graph[time[0]].push_back({ time[1], time[2] });
		}
		return graph;
	}

public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<Edge>> graph = buildGraph(times, n);
		vector<int> distances(n + 1, INT_MAX);
		distances[k] = 0;

		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push({ k, 0 });

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


		int res = 0;
		for (size_t i = 1; i <= n; i++)
		{
			if (distances[i] == INT_MAX)
				return -1;

			res = max(res, distances[i]);
		}

		return res;
	}
};