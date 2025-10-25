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

		if (arr[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return -1;
}


int main()
{
	vector<int> arr = { 10, 20, 30, 40, 50 };
	cout << binarySearch(arr, 30) << endl;
	cout << binarySearch(arr, 60) << endl;
}
