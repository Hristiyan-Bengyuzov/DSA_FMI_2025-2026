#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr) {
	for (auto& num : arr)
		cout << num << " ";
	cout << endl;
}

void insertionSort(vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); i++)
	{
		int current = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > current)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = current;
	}
}

int main()
{
	vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
	insertionSort(numbers);
	printArr(numbers);
}
