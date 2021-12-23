#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        if (m < 2)
            return 0;

        sort(a.begin(), a.end());
        int start = 0, end = m - 1;
        long long mini = INT_MAX;
        while (end < n)
        {
            mini = min(mini, a[end] - a[start]);
            start++, end++;
        }

        return mini;
    }
};

int main()
{
    long long n;
    cout << "Enter number of chocolate packets: ";
    cin >> n;
    vector<long long> a;
    long long x;
    cout << "Enter the number of chocolates in each packets: ";
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    long long m;
    cout << "Enter the number of children coming at the party: ";
    cin >> m;
    Solution ob;
    cout << "The difference between the maximum and minimum number of chocolates: " << ob.findMinDiff(a, n, m);
    return 0;
}