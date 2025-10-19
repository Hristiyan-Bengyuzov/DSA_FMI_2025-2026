// https://www.hackerrank.com/contests/sda-hw-1-2025/challenges/coachsort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int charToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 36;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // time exceeded with this cool one liner
    //sort(s.begin(), s.end(), [](char& a, char& b) {
    //    charToInt(a) < charToInt(b);
    //});

    vector<pair<int, char>> pairs;
    for (char c : s) 
        pairs.push_back({ charToInt(c), c });

    sort(pairs.begin(), pairs.end());

    string result;
    for (auto& p : pairs)
        result += p.second;

    cout << result;
    return 0;
}