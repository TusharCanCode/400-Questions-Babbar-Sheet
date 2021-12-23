#include <bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n, int x)
{
    int i = 0, j = n - 1, mid;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (arr[mid] < x)
            i = mid + 1;

        else if (arr[mid] > x)
            j = mid - 1;

        else
        {
            if (mid != 0 && arr[mid - 1] == x)
                j = mid - 1;

            else
                break;
        }
    }
    vector<int> ans;

    if (arr[mid] != x)
        return {-1, -1};

    ans.push_back(mid);

    i = mid, j = n - 1;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (arr[mid] < x)
            i = mid + 1;

        else if (arr[mid] > x)
            j = mid - 1;

        else
        {
            if (mid != n - 1 && arr[mid + 1] == x)
                i = mid + 1;

            else
                break;
        }
    }
    ans.push_back(mid);
    return ans;
}

int main()
{
    cout << "Enter the size of the array: ";
    int N;
    cin >> N;
    cout << "Enter the elements of the array (in sorted fashion): ";
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the number whose first and last occurence you wish to find out in the array: ";
    int x;
    cin >> x;

    auto ans = find(arr, N, x);
    cout << "The first occurence of the number in the array is at index " << ans[0] << " and the last occurence at index " << ans[1];
}