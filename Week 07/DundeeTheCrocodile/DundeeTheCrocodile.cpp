// https://www.hackerrank.com/contests/sda-test5-2022-2023-43wdst52/challenges/dundee-the-crocodile
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

unordered_map<string, int> getSentence(string& line) {
	string word;
	stringstream ss(line);
	unordered_map<string, int> res;

	while (ss >> word)
	{
		res[word]++;
	}

	return res;
}

void getUniqueMissing(unordered_map<string, int>& first, unordered_map<string, int>& second, set<string>& res) {
	for (auto& entry : first)
	{
		if (entry.second == 1 && !second.count(entry.first))
		{
			res.insert(entry.first);
		}
	}
}


int main()
{
	string line;

	std::getline(std::cin, line);
	unordered_map<string, int> firstSentence = getSentence(line);

	std::getline(std::cin, line);
	unordered_map<string, int> secondSentence = getSentence(line);

	set<string> result;
	getUniqueMissing(firstSentence, secondSentence, result);
	getUniqueMissing(secondSentence, firstSentence, result);

	for (const string& str : result)
	{
		cout << str << endl;
	}
}
