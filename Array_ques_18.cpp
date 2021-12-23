#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k)
{
    map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (map[k - arr[i]] > 0)
        {
            map[arr[i]]--;
            count = count + map[k - arr[i]];
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the sum of the pair: ";
    int sum;
    cin >> sum;
    cout << "There are " << getPairsCount(arr, n, sum) << " pairs in the array whose sum is " << sum;
}