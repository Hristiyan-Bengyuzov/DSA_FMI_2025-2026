// https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351
#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[curr] = true;

	for (int& neighbor : graph[curr]) {
		if (!visited[neighbor])
		{
			dfs(neighbor, graph, visited);
		}
	}
}


int main()
{
	size_t t, citiesCount, pathsCount;

	cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		cin >> citiesCount >> pathsCount;
		vector<vector<int>> graph(citiesCount);
		vector<bool> visited(citiesCount, false);
		int areas = 0;

		for (size_t i = 0; i < pathsCount; i++)
		{
			size_t u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (size_t i = 0; i < graph.size(); i++)
		{
			if (!visited[i])
			{
				dfs(i, graph, visited);
				areas++;
			}
		}

		cout << areas << " ";
	}
}

