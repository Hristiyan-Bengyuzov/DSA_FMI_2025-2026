#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
	enum Color {
		START = -1,
		RED,
		BLUE
	};

	vector<vector<int>> buildGraph(vector<vector<int>>& edges, int n) {
		vector<vector<int>> res(n);

		for (auto& edge : edges) {
			res[edge[0]].push_back(edge[1]);
		}

		return res;
	}

public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		auto redGraph = buildGraph(redEdges, n);
		auto blueGraph = buildGraph(blueEdges, n);

		vector<bool> visitedRed(n, false);
		vector<bool> visitedBlue(n, false);
		vector<int> dist(n, -1);

		queue<pair<int, int>> q;
		q.push({ 0, START });

		int level = 0;

		while (!q.empty())
		{
			int size = q.size();

			for (size_t i = 0; i < size; i++)
			{
				auto p = q.front(); q.pop();
				auto node = p.first;
				auto prevColor = p.second;

				if (dist[node] == -1)
					dist[node] = level;

				if (prevColor != RED)
				{
					for (int& next : redGraph[node]) {
						if (!visitedRed[next])
						{
							visitedRed[next] = true;
							q.push({ next, RED });
						}
					}
				}

				if (prevColor != BLUE)
				{
					for (int& next : blueGraph[node]) {
						if (!visitedBlue[next])
						{
							visitedBlue[next] = true;
							q.push({ next, BLUE });
						}
					}
				}
			}

			level++;
		}

		return dist;
	}
};