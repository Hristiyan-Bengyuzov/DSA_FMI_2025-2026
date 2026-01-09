// https://leetcode.com/problems/path-with-maximum-probability/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to;
	double weight;
};

struct Node {
	int index;
	double probability;

	bool operator<(const Node& other) const {
		return probability < other.probability;
	}
};

const double DOUBLE_MIN = numeric_limits<double>::lowest();

class Solution {
private:
	vector<vector<Edge>> buildGraph(int n, vector<vector<int>>& edges, vector<double>& succProb) {
		vector<vector<Edge>> graph(n);

		for (size_t i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]].push_back({ edges[i][1], succProb[i] });
			graph[edges[i][1]].push_back({ edges[i][0], succProb[i] });
		}

		return graph;
	}

public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
		vector<vector<Edge>> graph = buildGraph(n, edges, succProb);
		vector<double> probabilities(n, DOUBLE_MIN);
		probabilities[start_node] = 1;

		priority_queue<Node, vector<Node>, less<Node>> pq;
		pq.push({ start_node, 1 });

		while (!pq.empty())
		{
			Node currNode = pq.top(); pq.pop();

			if (currNode.probability < probabilities[currNode.index])
				continue;

			for (const Edge& edge : graph[currNode.index]) {
				double newProbability = currNode.probability * edge.weight;

				if (newProbability > probabilities[edge.to])
				{
					probabilities[edge.to] = newProbability;
					pq.push({ edge.to, newProbability });
				}
			}
		}

		return probabilities[end_node] == DOUBLE_MIN ? 0 : probabilities[end_node];
	}
};