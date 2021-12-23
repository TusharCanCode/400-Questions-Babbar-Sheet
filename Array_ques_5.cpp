#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int size)
{
    int j = size - 1;
    for (int i = 0; i < size && i < j;)
    {
        if (arr[i] > 0 && arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
        else
        {
            if (arr[i] < 0)
                i++;

            if (arr[j] > 0)
                j--;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    rearrange(arr, size);
    cout << "The rearranged array looks like: ";
    for (int i : arr)
        cout << i << " ";
}