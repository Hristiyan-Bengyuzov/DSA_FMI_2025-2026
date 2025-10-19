#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
	for (auto& num : arr)
		cout << num << " ";
	cout << endl;
}

void bubbleSort(vector<int>& arr) {
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		bool swapped = false;

		for (size_t j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

int main()
{
	vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
	bubbleSort(numbers);
	printArr(numbers);
}
