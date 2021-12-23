#include <bits/stdc++.h>
using namespace std;

int findMissing(int arr[], int n)
{
    int start = 0, end = n - 1, diff = (arr[n - 1] - arr[0]) / n;
    while (start <= end)
    {
        int mid = (start + end) / 2, anticipate = arr[0] + mid * diff;

        if (end - start == 1)
        {
            return arr[start] + diff;
        }

        else if (arr[mid] == anticipate)
            start = mid;

        else
            end = mid;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the A.P. : ";
    cin >> n;
    cout << "Enter the A.P. with one number missing : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The missing number in the A.P. is : " << findMissing(arr, n);
}