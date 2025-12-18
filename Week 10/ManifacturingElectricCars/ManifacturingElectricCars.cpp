// https://www.hackerrank.com/contests/sda-2020-2021-test7-8jfn4/challenges/challenge-2737/copy-from/1401843993
#include <iostream>
#include <queue>

using namespace std;

int main() {
	priority_queue<int> orders;
	size_t n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int order;
		cin >> order;

		if (order == -1)
		{
			if (!orders.empty())
			{
				cout << orders.top() << " ";
				orders.pop();
			}
		}
		else
		{
			orders.push(order);
		}
	}
}