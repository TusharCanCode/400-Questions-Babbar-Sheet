#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum(int A[], int N)
    {
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            ans += A[i];
        }
        return ans;
    }

    bool utility(int A[], int N, int M, int mid)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum > mid)
            {
                M--;
                i--;
                sum = 0;
            }
            if (M == 0)
                return false;
        }
        return true;
    }

    int findPages(int A[], int N, int M)
    {
        if (M > N)
            return -1;
        int start = *max_element(A, A + N);
        int end = sum(A, N);

        int res = start;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (utility(A, N, M, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}