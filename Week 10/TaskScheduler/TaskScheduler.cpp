#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> frequencies;
		priority_queue<int> pq;

		for (char& task : tasks)
			frequencies[task]++;

		for (auto& entry : frequencies)
			pq.push(entry.second);

		int totalTime = 0;

		while (!pq.empty())
		{
			vector<int> remain;
			int taskCount = 0, cycle = n + 1;

			while (cycle-- && !pq.empty())
			{
				if (pq.top() > 1)
					remain.push_back(pq.top() - 1);
				pq.pop();
				taskCount++;
			}

			for (int& x : remain)
				pq.push(x);

			totalTime += (pq.empty() ? taskCount : n + 1);
		}

		return totalTime;
	}
};