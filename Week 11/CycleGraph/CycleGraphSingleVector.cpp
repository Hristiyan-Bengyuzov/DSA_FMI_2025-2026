// https://www.hackerrank.com/contests/sda-homework-10/challenges/-1-12
#include <iostream>
#include <vector>

using namespace std;

enum State {
	Unvisited = 0,
	Visiting,
	Visited
};

bool dfs(int curr, vector<vector<int>>& graph, vector<State>& visited) {
	visited[curr] = Visiting;

	for (int& neighbour : graph[curr]) {
		if (!visited[neighbour])
		{
			if (dfs(neighbour, graph, visited))
				return true;
		}
		else if (visited[neighbour] == Visiting)
		{
			return true;
		}
	}

	visited[curr] = Visited;
	return false;
}


bool hasCycle(vector<vector<int>>& graph) {
	vector<State> visited(graph.size(), Unvisited);

	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			if (dfs(i, graph, visited))
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
