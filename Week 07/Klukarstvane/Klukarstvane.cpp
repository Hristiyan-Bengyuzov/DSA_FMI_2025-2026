// https://www.hackerrank.com/contests/sda-hw-9-2023/challenges/challenge-4437
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int main()
{
	int n, theme;
	cin >> n;

	unordered_map<int, int> themes;
	int minDist = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		cin >> theme;

		if (themes.count(theme))
		{
			minDist = min(minDist, i - themes[theme]);
		}

		themes[theme] = i;
	}

	cout << minDist;
}