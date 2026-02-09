// https://www.hackerrank.com/contests/2024-2025-2/challenges/treevalidator
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
	size_t q;
	cin >> q;

	while (q--)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> graph(v);
		vector<bool> visited(v, false);

		for (size_t i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}


		bool hasCyle = false;
		int components = 0;
		for (size_t i = 0; i < graph.size(); i++)
		{
			if (!visited[i])
			{
				components++;
				if (dfs(i, graph, visited, -1))
				{
					hasCyle = true;
					break;
				}
			}
		}

		bool isTree = !hasCyle && components == 1;
		cout << isTree << endl;
	}
}