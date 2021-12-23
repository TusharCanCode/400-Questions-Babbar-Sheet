#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int prev = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        arr[i] = prev;
        prev = temp;
    }
    arr[0] = prev;
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

    rotate(arr, size);
    cout << "After rotating the array by one position in clock-wise direction, it looks like: ";
    for (int i : arr)
        cout << i << " ";
}