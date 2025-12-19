// https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-2852
#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& components, int component) {
	visited[curr] = true;
	components[curr] = component;

	for (int& next : graph[curr]) {
		if (!visited[next]) {
			dfs(next, graph, visited, components, component);
		}
	}
}


int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);

	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	vector<bool> visited(n + 1, false);
	vector<int> components(n + 1);
	int component = 1;

	for (size_t i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, graph, visited, components, component++);
		}
	}

	size_t k;
	cin >> k;

	for (size_t i = 0; i < k; i++) {
		int ki, kj;
		cin >> ki >> kj;
		cout << (components[ki] == components[kj]) << " ";
	}
}