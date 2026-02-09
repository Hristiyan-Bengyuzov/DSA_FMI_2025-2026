// https://www.hackerrank.com/contests/2024-2025-2/challenges/challenge-5368
#include <iostream>
#include <vector>
#include <algorithm>

struct Land {
	double diameter;
	double pricePerMeter;
	size_t index;
};

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	vector<Land> lands;

	for (size_t i = 0; i < n; i++)
	{
		double d, price;
		cin >> d >> price;
		double r = d / 2;

		lands.push_back({ d, price / (r * r), i + 1 });
	}

	sort(lands.begin(), lands.end(), [](const Land& first, const Land& second) {
		if (first.pricePerMeter == second.pricePerMeter)
		{
			return first.diameter > second.diameter;
		}
		return first.pricePerMeter < second.pricePerMeter;
		});

	for (size_t i = 0; i < n; i++)
	{
		cout << lands[i].index << " ";
	}
}