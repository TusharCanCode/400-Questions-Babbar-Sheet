#include <bits/stdc++.h>
using namespace std;

void kthsmallest(vector<pair<long long int, long long int>> &ranges, vector<long long int> &K)
{
    //Merging the array:
    vector<pair<long long int, long long int>> merge;
    merge.push_back(ranges[0]);
    for (auto i : ranges)
    {
        if (i.first > (merge.back()).second)
            merge.push_back(i);
        else
            (merge.back()).second = max((merge.back()).second, i.second);
    }

    long long int range, ans;
    for (auto i : K)
    {
        ans = -1;
        for (auto j : merge)
        {
            range = j.second - j.first + 1;

            if (i <= range)
            {
                ans = j.first + i - 1;
                break;
            }

            i = i - range;
        }
        cout << ans << '\n';
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        vector<pair<long long int, long long int>> ranges;
        vector<long long int> K;
        while (N--)
        {
            long long int a, b;
            cin >> a >> b;
            ranges.push_back({a, b});
        }

        while (Q--)
        {
            long long int ele;
            cin >> ele;
            K.push_back(ele);
        }
        sort(ranges.begin(), ranges.end());
        kthsmallest(ranges, K);
    }
}