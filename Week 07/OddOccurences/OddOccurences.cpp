// https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3157
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	size_t n;
	cin >> n;
	unordered_map<long long, size_t> numOccurences;

	for (size_t i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		numOccurences[num]++;
	}

	int sum = 0;

	for (auto& entry : numOccurences)
	{
		if (entry.second % 2 != 0)
		{
			sum += (entry.second * entry.first);
		}
	}

	cout << sum;
}

