#include <bits/stdc++.h>
using namespace std;

pair<int, int> minmax(int arr[], int size)
{
    int min = INT_MAX, max = INT_MIN;
    if (size == 1)
        return {arr[0], arr[0]};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    return {min, max};
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the array:";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    auto res = minmax(arr, size);
    cout << "The maximum value of the array is: " << res.first << " and the minimum value of the array is: " << res.second;
}