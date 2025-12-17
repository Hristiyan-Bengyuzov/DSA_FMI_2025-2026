// https://www.hackerrank.com/contests/sda-test4-2022-2023-343rrsdfs/challenges/challenge-3768/problem
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);


	for (size_t i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		intervals[i] = { start, end };
	}

	priority_queue<int, vector<int>, std::greater<int>> ends;
	int maxOverlapping = 0;

	for (auto& interval : intervals) {
		while (!ends.empty() && ends.top() <= interval.first)
		{
			ends.pop();
		}

		ends.push(interval.second);

		if (maxOverlapping < ends.size())
			maxOverlapping = ends.size();
	}

	cout << maxOverlapping;
}
