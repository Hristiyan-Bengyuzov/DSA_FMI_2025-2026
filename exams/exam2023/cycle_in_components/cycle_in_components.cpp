// https://www.hackerrank.com/contests/2023-2024-2/challenges/cycles-components
#include <iostream>
#include <vector>


using namespace std;

bool dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited, int parent) {
	visited[curr] = true;

	for (int& next : graph[curr]) {
		if (!visited[next])
		{
			if (dfs(next, graph, visited, curr))
				return true;
		}
		else if (next != parent)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	size_t t;
	cin >> t;

	while (t--)
	{
		size_t v, e;
		cin >> v >> e;

		vector<vector<int>> graph(v);

		for (size_t i = 0; i < e; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		vector<bool> visited(v, false);
		int cycles = 0;

		for (size_t i = 0; i < graph.size(); i++)
		{
			if (!visited[i])
			{
				if (dfs(i, graph, visited, -1))
				{
					cycles++;
				}
			}
		}

		cout << cycles << endl;
	}
}
