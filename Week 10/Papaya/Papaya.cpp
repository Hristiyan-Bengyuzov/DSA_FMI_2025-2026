// https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4446
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, minThreshold;
	cin >> n >> minThreshold;

	priority_queue<int, vector<int>, greater<int>> papayas;

	for (size_t i = 0; i < n; i++)
	{
		int papaya;
		cin >> papaya;
		papayas.push(papaya);
	}

	int totalDays = 0;

	while (papayas.size() > 1 && papayas.top() < minThreshold)
	{
		int p1 = papayas.top(); papayas.pop();
		int p2 = papayas.top(); papayas.pop();
		papayas.push(p1 + 2 * p2);
		totalDays++;
	}

	cout << (papayas.top() >= minThreshold ? totalDays : -1);
}
