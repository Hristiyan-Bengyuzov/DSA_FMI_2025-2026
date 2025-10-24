#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
	for (auto& num : arr)
		cout << num << " ";
	cout << endl;
}

int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[high], i = low;

	for (size_t j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr[i++], arr[j]);
		}
	}

	swap(arr[i], arr[high]);
	return i;
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
	quickSort(numbers, 0, numbers.size() - 1);
	printArr(numbers);
}
