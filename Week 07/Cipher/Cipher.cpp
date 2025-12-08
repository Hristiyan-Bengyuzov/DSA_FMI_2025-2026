// https://www.hackerrank.com/contests/sda-2021-2022-test5-8dec/challenges/challenge-3156
#include <iostream>
#include <unordered_map>
#include<queue>

using namespace std;

int main()
{
	int n;
	unordered_map<string, int> wordsCount;
	queue<string> q;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		q.push(word);
		wordsCount[word]++;
	}

	while (!q.empty())
	{
		std::cout << wordsCount[q.front()] << " ";
		q.pop();
	}
}
