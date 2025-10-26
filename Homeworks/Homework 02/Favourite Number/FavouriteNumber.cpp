// https://www.hackerrank.com/contests/sda-hw-2-2025/challenges/challenge-3668
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long getCandies(long long l, long long r, long long friendNum, int depth = 1) {
	if (l >= r)
		return depth;

	long long mid1 = l + (r - l) / 3;
	long long mid2 = r - (r - l) / 3;

	if (friendNum > mid1 && friendNum < mid2)
		return depth;

	if (friendNum <= mid1)
		return getCandies(l, mid1, friendNum, depth + 1);

	return getCandies(mid2, r, friendNum, depth + 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int p, n;
	cin >> p >> n;

	long long totalFriends = pow(3, p);
	vector<long long> friendNums(n);

	for (size_t i = 0; i < n; i++)
		cin >> friendNums[i];

	for (long long friendNum : friendNums) {
		cout << getCandies(1, totalFriends, friendNum) << endl;
	}
}
