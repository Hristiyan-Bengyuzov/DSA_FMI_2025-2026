// https://www.hackerrank.com/contests/exam-2022-part1-sda/challenges/unique-rows
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	size_t n, m;
	cin >> n >> m;

	map<vector<int>, int> counts;

	for (size_t i = 0; i < n; i++)
	{
		vector<int> row(m);
		for (size_t j = 0; j < m; j++)
			cin >> row[j];

		counts[row]++;
	}

	int res = 0;
	for (auto& entry : counts) {
		if (entry.second == 1)
			res++;
	}

	cout << res;
}
