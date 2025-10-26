// https://www.hackerrank.com/contests/sda-hw-2-2025/challenges/challenge-3670
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<long long>& devSkills, long long mid, long long t) {
	long long devSkillsSum = 0;
	int devTeams = 1;

	for (size_t i = 0; i < devSkills.size(); i++)
	{
		if (devSkills[i] > mid)
			return false;

		devSkillsSum += devSkills[i];
		if (devSkillsSum > mid)
		{
			devTeams++;
			devSkillsSum = devSkills[i];
		}
	}

	return devTeams <= t;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, t;
	cin >> n >> t;
	long long l = 0, r = 0;


	vector<long long> devSkills(n);
	for (size_t i = 0; i < n; i++) {
		cin >> devSkills[i];
		l = max(l, devSkills[i]);
		r += devSkills[i];
	}

	long long result = 0;
	while (l <= r)
	{
		long long mid = l + (r - l) / 2;

		if (check(devSkills, mid, t))
		{
			result = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	cout << result;
}
