// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
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
	vector<vector<int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

public:
	int minCost(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
		distances[0][0] = 0;

		priority_queue<Node, vector<Node>, greater<Node>> pq;
		pq.push({ 0, 0, 0 });

		while (!pq.empty())
		{
			Node currNode = pq.top(); pq.pop();
			int x = currNode.x;
			int y = currNode.y;
			int dist = currNode.distance;

			if (dist > distances[x][y])
				continue;

			for (size_t dir = 0; dir < directions.size(); dir++)
			{
				int newX = x + directions[dir][0];
				int newY = y + directions[dir][1];

				if (newX < 0 || newX >= rows || newY < 0 || newY >= cols)
					continue;

				int extraCost = dir + 1 == grid[x][y] ? 0 : 1;
				int newDist = dist + extraCost;

				if (newDist < distances[newX][newY])
				{
					distances[newX][newY] = newDist;
					pq.push({ newX, newY, newDist });
				}
			}
		}

		return distances[rows - 1][cols - 1];
	}
};