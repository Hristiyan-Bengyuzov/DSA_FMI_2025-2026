// https://www.hackerrank.com/contests/exam-2022-part1-sda/challenges/sda-exam
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	size_t q;
	cin >> q;

	while (q--)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> graph(v + 1);

		for (size_t i = 0; i < e; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		int start;
		cin >> start;

		queue<int> q;
		vector<int> dist(v + 1, -1);
		dist[start] = 0;
		q.push(start);

		while (!q.empty())
		{
			int curr = q.front(); q.pop();

			for (int& next : graph[curr]) {
				if (dist[next] == -1)
				{
					dist[next] = dist[curr] + 6;
					q.push(next);
				}
			}
		}

		for (size_t i = 1; i <= v; i++)
		{
			if (i != start)
			{
				cout << dist[i] << " ";
			}
		}

		cout << endl;
	}
}
