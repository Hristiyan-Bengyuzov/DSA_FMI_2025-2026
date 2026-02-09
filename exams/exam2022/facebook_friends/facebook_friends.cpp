// https://www.hackerrank.com/contests/sda-exam-20222023-part-1/challenges/challenge-3904
#include <iostream>
#include <vector>

using namespace std;

int dfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
	visited[start] = true;
	int count = 1;

	for (int& next : graph[start]) {
		if (!visited[next])
		{
			count += dfs(next, graph, visited);
		}
	}

	return count;
}

int main()
{
	size_t v, e;
	int k = 0;
	cin >> v >> e >> k;

	vector<vector<int>> graph(v);

	for (size_t i = 0; i < e; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<bool> visited(v, false);
	int divisibleByK = 0;


	for (size_t i = 0; i < graph.size(); i++)
	{
		if (!visited[i])
		{
			if (dfs(i, graph, visited) % k == 0)
			{
				divisibleByK++;
			}
		}
	}

	cout << divisibleByK;
}
