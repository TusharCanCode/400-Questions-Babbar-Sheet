#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0;
    while (i < size - 1)
    {
        if (binary_search(arr + i + 1, arr + size, n + arr[i]))
            return true;
        i++;
    }
    return false;
}

//OR

// bool findPair(int arr[], int size, int n)
// {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < size; i++)
//     {
//         mp[arr[i]]++;
//     }
//     for (int i = 0; i < size; i++)
//     {
//         mp[arr[i]]--;
//         if (mp[arr[i] + n] != 0)
//             return true;

//         mp[arr[i]]++;
//     }
//     return false;
// }

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

    cout << "Enter the difference between the pair you wish to search: ";
    int difference;
    cin >> difference;

    if (findPair(arr, N, difference))
        cout << "A pair with the difference " << difference << " is successfully found in the array!";
    else
        cout << "No pair with the difference " << difference << " is found in the array!";
}