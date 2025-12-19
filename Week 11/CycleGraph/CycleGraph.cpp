// https://www.hackerrank.com/contests/sda-homework-10/challenges/-1-12
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onPath) {
	visited[curr] = true;
	onPath[curr] = true;

	for (int& next : graph[curr]) {
		if (!visited[next])
		{
			if (dfs(next, graph, visited, onPath))
				return true;
		}
		else if (onPath[next])
		{
			return true;
		}
	}

	onPath[curr] = false;
	return false;
}

bool hasCycle(vector<vector<int>>& graph) {
	vector<bool> visited(graph.size() + 1, false);
	vector<bool> onPath(graph.size() + 1, false);

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			if (dfs(i, graph, visited, onPath))
				return true;
		}
	}

	return false;
}

int main()
{
	size_t n;
	cin >> n;

	while (n--)
	{
		size_t v, e;
		cin >> v >> e;

		vector<vector<int>> graph(v + 1);

		for (size_t i = 0; i < e; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			graph[x].push_back(y);
		}

		cout << (hasCycle(graph) ? "true" : "false") << " ";
	}
}
