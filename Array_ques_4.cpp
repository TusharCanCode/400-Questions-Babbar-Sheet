#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int one = 0;
    int zero = 0;
    int two = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zero++;
        else if (a[i] == 1)
            one++;
        else
            two++;
        a[i] = 2;
    }

    for (int i = 0; i < zero; i++)
        a[i] = 0;
    for (int i = zero; i < (zero + one); i++)
        a[i] = 1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array (The elements should only include 0's, 1's and 2's):";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1 && arr[i] != 2)
            exit(0);
    }

    sort012(arr, size);
    cout << "The sorted array looks like: ";
    for (int i : arr)
        cout << i << " ";
}