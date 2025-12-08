// https://www.hackerrank.com/contests/sda-2019-2020-test-5/challenges/challenge-2298
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	size_t n, m;
	unordered_map<string, size_t> townCosts;

	cin >> n >> m;

	for (size_t i = 0; i < n; i++)
	{
		string town;
		size_t cost;
		cin >> town >> cost;

		townCosts[town] = cost;
	}

	size_t sum = 0;

	for (size_t i = 0; i < m; i++)
	{
		string town;
		cin >> town;

		if (townCosts.count(town))
		{
			sum += townCosts[town];
		}
	}

	cout << sum;
}
