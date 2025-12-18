// https://leetcode.com/problems/find-median-from-data-stream/description/
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
	priority_queue<int> leftHalf;
	priority_queue<int, vector<int>, greater<int>> rightHalf;

public:
	MedianFinder() {

	}

	void addNum(int num) {
		if (leftHalf.empty() || num <= leftHalf.top())
			leftHalf.push(num);
		else
			rightHalf.push(num);

		if (leftHalf.size() > rightHalf.size() + 1)
		{
			rightHalf.push(leftHalf.top());
			leftHalf.pop();
		}
		else if (rightHalf.size() > leftHalf.size())
		{
			leftHalf.push(rightHalf.top());
			rightHalf.pop();
		}
	}

	double findMedian() {
		if (leftHalf.size() > rightHalf.size())
			return leftHalf.top();
		return (leftHalf.top() + rightHalf.top()) / 2.0;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */