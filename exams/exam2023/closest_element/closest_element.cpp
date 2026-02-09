// https://www.hackerrank.com/contests/2023-2024-2/challenges/--169
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
	int l = 0, r = arr.size() - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == target)
			return mid;

		if (target > arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}

	return l;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	size_t n, q;
	cin >> n;

	vector<int> arr(n);
	for (size_t i = 0; i < n; i++)
		cin >> arr[i];

	cin >> q;
	while (q--)
	{
		int target;
		cin >> target;

		int l = binarySearch(arr, target);
		int ind = 0;

		if (l == 0)
			ind = 0;
		else if (l == n)
			ind = n - 1;
		else {
			int firstDiff = abs(arr[l] - target);
			int secondDiff = abs(arr[l - 1] - target);

			ind = (firstDiff < secondDiff ? l : l - 1);
		}

		cout << (ind == 0 ? -1 : arr[ind - 1]) << endl;
	}
}