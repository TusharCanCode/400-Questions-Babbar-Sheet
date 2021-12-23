#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    int half = size / 2;

    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[a[i]]++;
        if (map[a[i]] > half)
            return a[i];
    }
    return -1;
}

int main()
{
    cout << "Enter the size of the array: ";
    int N;
    cin >> N;
    int arr[N];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << "The majority element in the array is: " << majorityElement(arr, N);
}