// https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/just-sorting-1
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
	string name;
	unsigned points;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned n;
	cin >> n;

	vector<Student> students(n);

	for (size_t i = 0; i < n; i++)
		cin >> students[i].name;

	for (size_t i = 0; i < n; i++)
		cin >> students[i].points;

	sort(students.begin(), students.end(), [](const Student& first, const Student& second) {
		if (first.points != second.points)
			return first.points > second.points;
		return first.name < second.name;
	});

	for (size_t i = 0; i < n; i++)
		cout << students[i].name << " " << students[i].points << endl;
}
