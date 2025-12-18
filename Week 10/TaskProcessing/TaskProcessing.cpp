// https://www.hackerrank.com/contests/sda-2021-2022-test4-nov30/challenges/challenge-3148
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Task {
	size_t startTime;
	size_t waitTime;

	bool operator>(const Task& other) const {
		return waitTime > other.waitTime;
	}
};


int main()
{
	size_t n;
	cin >> n;

	size_t min = 1e9, max = 0;
	vector<Task> tasks(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> tasks[i].waitTime;
		tasks[i].startTime = i;
	}

	priority_queue<Task, vector<Task>, greater<Task>> pq;
	pq.push(tasks[0]);
	size_t startTime = 0;

	while (!pq.empty())
	{
		Task currTask = pq.top(); pq.pop();
		size_t totalProcessingTime = startTime - currTask.startTime + currTask.waitTime;

		if (totalProcessingTime < min)
			min = totalProcessingTime;

		if (totalProcessingTime > max)
			max = totalProcessingTime;

		size_t finishTime = startTime + currTask.waitTime;

		for (size_t i = startTime + 1; i <= finishTime; i++)
		{
			if (i < n)
				pq.push(tasks[i]);
		}

		startTime = finishTime;
	}

	cout << min << " " << max;
}
