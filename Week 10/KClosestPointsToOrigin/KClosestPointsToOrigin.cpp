// https://leetcode.com/problems/k-closest-points-to-origin/description/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
	static double getDistanceFromOrigin(const vector<int>& point) {
		return sqrt(point[0] * point[0] + point[1] * point[1]);
	}

	struct DistanceFromOriginComparator {
		bool operator()(const vector<int>& first, const vector<int>& second) {
			return getDistanceFromOrigin(first) > getDistanceFromOrigin(second);
		}
	};

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		priority_queue<vector<int>, vector<vector<int>>, DistanceFromOriginComparator> pq(points.begin(), points.end());
		vector<vector<int>> res(k);

		for (size_t i = 0; i < k; i++)
		{
			res[i] = pq.top();
			pq.pop();
		}

		return res;
	}
};