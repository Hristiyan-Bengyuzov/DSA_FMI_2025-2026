// https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/walking-median-sorting
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// gives the index so that vector keeps being sorted
size_t getInsertIndex(const vector<int>& nums, int num) {
	int l = 0, r = nums.size() - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (nums[mid] == num)
			return mid;

		if (nums[mid] < num)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return l;
}

int main()
{
	size_t n;
	vector<int> nums;

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		// alternative to this
		// auto it = lower_bound(nums.begin(), nums.end(), num);
		// nums.insert(it, num);
		size_t insertIdx = getInsertIndex(nums, num);
		nums.insert(nums.begin() + insertIdx, num);

		// left is always 0 for mid
		int mid = (nums.size() - 1) / 2;
		if (nums.size() % 2 == 0)
		{
			double avg = (nums[mid] + nums[mid + 1]) / 2.0;
			cout << avg << endl;
		}
		else
		{
			cout << nums[mid] << endl;
		}
	}
}
