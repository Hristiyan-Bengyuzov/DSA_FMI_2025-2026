#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int>& arr, int target) {
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}

	return -1;
}


int main()
{
	vector<int> arr = { 10, 20, 30, 40, 50 };
	cout << linearSearch(arr, 30) << endl;
	cout << linearSearch(arr, 60) << endl;
}
