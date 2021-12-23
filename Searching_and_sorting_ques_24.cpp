#include <bits/stdc++.h>
using namespace std;

bool is_possible(vector<int> stables, int target, int cows)
{
    int count = 1, sum = 0;
    for (int i = 1; i < (int)stables.size(); i++)
    {
        sum += stables[i] - stables[i - 1];
        if (sum >= target)
        {
            count++;
            sum = 0;
        }

        if (count == cows)
            return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, C, min = INT_MAX, max = INT_MIN;
        vector<int> stables;
        cin >> N >> C;

        while (N--)
        {
            int ele;
            cin >> ele;

            if (ele < min)
                min = ele;

            if (ele > max)
                max = ele;

            stables.push_back(ele);
        }
        sort(stables.begin(), stables.end());
        int ans = min;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            if (is_possible(stables, mid, C))
            {
                min = mid + 1;
                ans = mid;
            }
            else
                max = mid - 1;
        }
        cout << ans << '\n';
    }
}