// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
	int x, y, distance;

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
};

class Solution {
private:
	vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

public:
	int minimumObstacles(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> distances(m, vector<int>(n, INT_MAX));
		distances[0][0] = 0;

		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push({ 0, 0, 0 });

		while (!pq.empty())
		{
			Node currNode = pq.top(); pq.pop();

			if (currNode.distance > distances[currNode.x][currNode.y])
				continue;

			for (auto& direction : directions) {
				int newX = currNode.x + direction[0];
				int newY = currNode.y + direction[1];

				if (newX < 0 || newX >= m || newY < 0 || newY >= n)
					continue;

				int newDistance = currNode.distance + grid[newX][newY];

				if (newDistance < distances[newX][newY])
				{
					distances[newX][newY] = newDistance;
					pq.push({ newX, newY, newDistance });
				}
			}
		}

		return distances[m - 1][n - 1];
	}
};