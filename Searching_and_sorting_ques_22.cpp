#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < arr[start] && arr[mid] < arr[end])
            end = mid;
        else if (arr[mid] > arr[start] && arr[mid] > arr[end])
            start = mid;
        else
            return min(arr[start], arr[end]);
    }
    return arr[start];
}

int main()
{
    vector<int> arr;
    cout << "Enter the size of the array: ";
    int N;
    cin >> N;
    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    cout << "The smallest element of the entered array is: " << findMin(arr);
}