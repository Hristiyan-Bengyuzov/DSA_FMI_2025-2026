// https://www.hackerrank.com/contests/sda-hw-2-2025/challenges/challenge-3669
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, minWeight, maxWeight;
    cin >> n >> q;

    vector<int> weights(n);
    for (size_t i = 0; i < n; i++)
        cin >> weights[i];

    sort(weights.begin(), weights.end());

    for (size_t i = 0; i < q; i++)
    {
        cin >> minWeight >> maxWeight;

        if (minWeight > maxWeight)
        {
            cout << 0 << endl;
            continue;
        }

        auto beg = lower_bound(weights.begin(), weights.end(), minWeight);
        auto end = upper_bound(weights.begin(), weights.end(), maxWeight);
        cout << end - beg << endl;
    }
}
