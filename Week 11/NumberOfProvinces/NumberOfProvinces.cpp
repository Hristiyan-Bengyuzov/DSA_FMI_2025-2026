// https://leetcode.com/problems/number-of-provinces/description/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<int>> getAdjacencyListFromAdjacencyMatrix(vector<vector<int>>& matrix) {
		size_t n = matrix.size();
		vector<vector<int>> res(n);

		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				if (matrix[i][j] && i != j)
				{
					res[i].push_back(j);
				}
			}
		}
	}

	void dfs(int curr, vector<vector<int>>& graph, vector<bool>& visited) {
		visited[curr] = true;

		for (int& neighbour : graph[curr]) {
			if (!visited[neighbour])
				dfs(neighbour, graph, visited);
		}
	}

public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		vector<vector<int>> graph = getAdjacencyListFromAdjacencyMatrix(isConnected);
		vector<bool> visited(graph.size(), false);
		int provincesCount = 0;

		for (size_t i = 0; i < graph.size(); i++)
		{
			if (!visited[i])
			{
				dfs(i, graph, visited);
				provincesCount++;
			}
		}

		return provincesCount;
	}
};