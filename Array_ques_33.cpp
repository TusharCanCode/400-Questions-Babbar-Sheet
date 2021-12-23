#include <bits/stdc++.h>
using namespace std;

int minSwap(int *arr, int n, int k);
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << minSwap(arr, n, k) << "\n";
    }
    return 0;
}

int minSwap(int *arr, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            count++;
    }

    int res = 0;
    for (int x = 0; x < count; x++)
    {
        if (arr[x] > k)
            res++;
    }

    int mini = res;
    for (int i = 0, j = count - 1; i < n - 1 && j < n - 1; i++, j++)
    {
        if (arr[i] <= k)
        {
            res++;
        }
        if (arr[j + 1] <= k)
        {
            res--;
        }

        mini = min(res, mini);
    }
    return mini;
}