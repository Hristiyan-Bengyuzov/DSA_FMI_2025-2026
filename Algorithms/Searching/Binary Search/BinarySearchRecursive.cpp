#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int target) {
	if (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == target)
			return mid;

		if (arr[mid] < target)
			return binarySearch(arr, mid + 1, r, target);

		return binarySearch(arr, l, mid - 1, target);
	}

	return -1;
}


int main()
{
	vector<int> arr = { 10, 20, 30, 40, 50 };
	cout << binarySearch(arr, 0, arr.size() - 1, 30) << endl;
	cout << binarySearch(arr, 0, arr.size() - 1, 60) << endl;
}
