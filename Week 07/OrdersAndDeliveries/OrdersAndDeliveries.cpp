// https://www.hackerrank.com/contests/sda-test-5/challenges/1-140
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int n;
	unordered_map<int, int> clientOrders;

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int clientId;
		cin >> clientId;
		clientOrders[clientId]++;
	}

	int clientsWithUnfulfilledOrders = 0, unfulfilledOrders = 0;

	for (auto& order : clientOrders)
	{
		int remainingOrders = order.second % 10;

		if (remainingOrders)
		{
			clientsWithUnfulfilledOrders++;
			unfulfilledOrders += remainingOrders;
		}
	}

	cout << clientsWithUnfulfilledOrders << " " << unfulfilledOrders;
}