#include <bits/stdc++.h>
using namespace std;

bool is_possible(int arr[], int L, int P, int target)
{
    int parata = 0, time = 0;
    for (int i = 0; i < L; i++)
    {
        for (int j = 1; time <= target; j++)
        {
            time += arr[i] * j;
            if (time <= target)
                parata++;

            if (parata >= P)
                return true;
        }

        time = 0;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int P, L;
        cin >> P >> L;
        int arr[L];

        for (int i = 0; i < L; i++)
        {
            cin >> arr[i];
        }

        int start = 1, end = 4004008, res = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (is_possible(arr, L, P, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        cout << res << '\n';
    }
}