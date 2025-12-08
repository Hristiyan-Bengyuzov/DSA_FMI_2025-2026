// https://www.hackerrank.com/contests/5-2023-2024/challenges/challenge-4497
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> readSentence(size_t size) {
	unordered_map<string, int> res;

	for (size_t i = 0; i < size; i++)
	{
		string str;
		cin >> str;
		res[str]++;
	}

	return res;
}

int main()
{
	int tests;
	cin >> tests;

	for (size_t i = 0; i < tests; i++)
	{
		size_t firstWords, secondWords;
		cin >> firstWords >> secondWords;

		unordered_map<string, int> firstSentence = readSentence(firstWords);
		unordered_map<string, int> secondSentence = readSentence(secondWords);

		bool seen = true;

		for (auto entry : secondSentence) {
			if (!firstSentence.count(entry.first))
			{
				seen = false;
				break;
			}

			if (entry.second > firstSentence[entry.first])
			{
				seen = false;
				break;
			}
		}

		cout << (seen ? "Yes" : "No") << endl;
	}
}
