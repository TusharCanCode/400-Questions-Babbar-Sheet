#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int utility(int arr[], int n, vector<int> &dp)
    {
        if (n == 0)
            return arr[0];

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = max(utility(arr, n - 2, dp) + arr[n], utility(arr, n - 1, dp));
    }

    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n, -1);
        return utility(arr, n - 1, dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}