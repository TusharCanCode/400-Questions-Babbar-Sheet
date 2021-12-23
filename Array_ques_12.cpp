#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void merge(int arr1[], int arr2[], int n, int m)
{
    // code here
    int ptr1 = n - 1;
    int ptr2 = 0;
    while (arr1[ptr1] > arr2[ptr2] && ptr1 >= 0 && ptr2 < m)
    {
        swap(arr1[ptr1], arr2[ptr2]);
        ptr1--, ptr2++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

//Or you can use gap algorithm to learn about that refer gfg

int main()
{
    int size1, size2;
    cout<<"Enter the size of the first and the second array: ";
    cin>>size1>>size2;

    int arr1[size1];
    int arr2[size2];
    cout<<"Enter the elements of the first array (in sorted fashion): ";
    for (int i = 0; i < size1; i++)
        cin>>arr1[i];
    
    cout<<"Enter the elements of the second array (in sorted fashion): ";
    for (int i = 0; i < size2; i++)
        cin>>arr2[i];

    merge(arr1, arr2, size1, size2);
    cout<<"The array after merging: ";
    for (int i = 0; i < size1; i++)
        cout<<arr1[i]<<" ";
    for (int i = 0; i < size2; i++)
        cout<<arr2[i]<<" ";
}