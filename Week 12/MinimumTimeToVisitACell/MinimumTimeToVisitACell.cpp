// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
	int x, y, time;

	bool operator>(const Cell& other) const {
		return time > other.time;
	}
};


class Solution {
private:
	vector<vector<int>> directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

public:
	int minimumTime(vector<vector<int>>& grid) {
		if (grid[0][1] > 1 && grid[1][0] > 1)
			return -1;

		int rows = grid.size();
		int cols = grid[0].size();

		vector<vector<bool>> visited(rows, vector<bool>(cols, false));

		priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
		pq.push({ 0, 0, grid[0][0] });

		while (!pq.empty())
		{
			Cell currCell = pq.top(); pq.pop();
			int x = currCell.x;
			int y = currCell.y;
			int time = currCell.time;

			if (x == rows - 1 && y == cols - 1)
				return time;

			if (visited[x][y])
				continue;

			visited[x][y] = true;

			for (auto& direction : directions) {
				int newX = x + direction[0];
				int newY = y + direction[1];

				if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || visited[newX][newY])
					continue;

				int waitTime = ((grid[newX][newY] - time) % 2 == 0) ? 1 : 0;
				int newTime = max(grid[newX][newY] + waitTime, time + 1);
				pq.push({ newX, newY, newTime });
			}
		}

		return -1;
	}
};