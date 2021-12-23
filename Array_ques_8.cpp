#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{

    int sum = 0;
    int maxm = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum = max(sum + arr[i], arr[i]);
        maxm = max(sum, maxm);
    }
    return maxm;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array:";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "The maximum sum of the continguous sub-array is: " << maxSubarraySum(arr, size);
}