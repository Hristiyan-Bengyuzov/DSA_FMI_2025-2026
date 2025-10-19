#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<int>& arr) {
	for (auto& num : arr)
		cout << num << " ";
	cout << endl;
}

void countingSort(vector<int>& arr) {
	int k = *max_element(arr.begin(), arr.end()) + 1;
	vector<int> counter(k, 0);

	for (int num : arr)
		counter[num]++;

	size_t index = 0;
	for (size_t i = 0; i < k; i++)
	{
		while (counter[i])
		{
			arr[index++] = i;
			counter[i]--;
		}
	}
}

int main()
{
	vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
	countingSort(numbers);
	printArr(numbers);
}
