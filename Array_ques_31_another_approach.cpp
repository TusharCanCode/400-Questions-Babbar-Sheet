#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sb(int arr[], int n, int x)
    {
        int start = 0;
        int end = 0;
        int sum = arr[end];
        int ans = INT_MAX;
        for (; end < n;)
        {
            if (sum > x)
            {
                if (end - start + 1 < ans)
                    ans = end - start + 1;

                sum -= arr[start];
                start++;
                if (sum > x && end - start + 1 < ans)
                    ans = end - start + 1;
            }
            else
                end++, sum += arr[end];
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