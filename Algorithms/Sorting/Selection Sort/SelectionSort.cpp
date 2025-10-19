#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
	for (auto& num : arr)
		cout << num << " ";
	cout << endl;
}

void selectionSort(vector<int>& arr) {
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		size_t minIdx = i;
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
			swap(arr[minIdx], arr[i]);
	}
}

int main()
{
	vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
	selectionSort(numbers);
	printArr(numbers);
}
