#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int start = i + 1, end = n - 1; start < end;)
            {
                if (arr[i] + arr[start] + arr[end] < sum)
                {
                    ans += (end - start);
                    start++;
                }

                else
                    end--;
            }
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
        int n;
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}