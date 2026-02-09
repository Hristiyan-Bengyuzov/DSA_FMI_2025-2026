// https://www.hackerrank.com/contests/2023-2024-2/challenges/challenge-4609
#include <iostream>
#include <unordered_map>

using namespace std;

bool areEqualAfterRemoval(unordered_map<char, int>& map) {
	int curr = -1;

	for (auto& entry : map) {
		if (entry.second == 0)
			continue;

		if (curr == -1)
			curr = entry.second;
		else if (curr != entry.second)
			return false;
	}

	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		unordered_map<char, int> counts;
		for (char c : s)
			counts[c]++;

		bool found = false;
		for (auto& count : counts) {
			count.second--;

			if (areEqualAfterRemoval(counts))
			{
				found = true;
				break;
			}

			count.second++;
		}

		cout << found << endl;
	}
}

