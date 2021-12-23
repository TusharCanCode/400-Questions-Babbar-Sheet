#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool utility(int arr[], int n, int x, int mid)
    {
        int start = 0;
        int end = mid - 1;
        int sum = 0;
        for (int i = 0; i < mid - 1; i++)
            sum += arr[i];

        for (; end < n; start++, end++)
        {
            sum += arr[end];
            if (sum > x)
                return true;
            sum = sum - arr[start];
        }
        return false;
    }
    int sb(int arr[], int n, int x)
    {
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (max < arr[i])
                max = arr[i];
        }
        if (max > x)
            return 1;

        int start = 1;
        int end = n;

        int ans = INT_MAX;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (utility(arr, n, x, mid))
                ans = mid, end = mid - 1;

            else
                start = mid + 1;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
}