// https://www.hackerrank.com/contests/sda-exam-20222023-part-1/challenges/challenge-3906
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	vector<int> stickers(n);
	vector<int> wanted(n);


	for (size_t i = 0; i < n; i++)
		cin >> stickers[i];

	for (size_t i = 0; i < n; i++)
		cin >> wanted[i];

	unordered_map<int, int> stickersCount;
	int fights = 0;

	for (size_t i = 0; i < n; i++)
	{
		stickersCount[stickers[i]]++;

		if (stickersCount.count(wanted[i]))
		{
			if (stickersCount[wanted[i]] == 0)
				fights++;
			else
				stickersCount[wanted[i]]--;
		}
		else
		{
			fights++;
		}
	}

	cout << fights;
}