#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[a1[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (map[a2[i]] == 0)
            return "No";
    }
    return "Yes";
}

int main()
{
    int size1, size2;
    cout << "Enter the size of the first and the second array: ";
    cin >> size1 >> size2;

    int arr1[size1];
    int arr2[size2];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++)
        cin >> arr1[i];

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++)
        cin >> arr2[i];

    cout<<"Is array-2 is a subset of array-1: "<<isSubset(arr1, arr2, size1, size2);
}