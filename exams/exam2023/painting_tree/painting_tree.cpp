// https://www.hackerrank.com/contests/2023-2024-2/challenges/challenge-4607
#include <iostream>
#include <vector>

using namespace std;

int paints = 0;

enum State {
	UNCOVERED = 0,
	COVERED,
	PAINT
};

State dfs(int start, vector<vector<int>>& tree) {
	bool hasUncoveredChild = false;
	bool hasPaintChild = false;

	for (int next : tree[start]) {
		State state = dfs(next, tree);
		if (state == UNCOVERED)
			hasUncoveredChild = true;
		if (state == PAINT)
			hasPaintChild = true;
	}

	if (hasUncoveredChild)
	{
		paints++;
		return PAINT;
	}

	if (hasPaintChild)
	{
		return COVERED;
	}

	return UNCOVERED;
}


int main()
{
	size_t n;
	cin >> n;

	vector<vector<int>> tree(n);

	for (size_t i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l != -1)
			tree[i].push_back(l);

		if (r != -1)
			tree[i].push_back(r);
	}

	if (dfs(0, tree) == UNCOVERED)
	{
		paints++;
	}

	cout << paints;
}