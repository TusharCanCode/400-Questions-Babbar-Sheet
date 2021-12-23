#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int x)
{
    int i = 0, j = arr.size() - 1, mid;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (arr[mid] == x)
            return mid;

        else if (arr[i] == x)
            return i;

        else if (arr[j] == x)
            return j;

        else if (arr[mid] > arr[i] && arr[mid] > arr[j])
        {
            if (x > arr[i] && x < arr[mid])
                j = mid - 1;

            else
                i = mid + 1;
        }

        else if (arr[mid] < arr[i] && arr[mid] < arr[j])
        {
            if (x > arr[mid] && x < arr[j])
                i = mid + 1;

            else
                j = mid - 1;
        }

        else
        {
            if (x > arr[mid])
                i = mid + 1;
            else
                j = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int>arr;
    cout<<"Enter the number of elements in the array: ";
    int N;
    cin>>N;
    cout<<"Enter the sorted rotated array elements: ";
    for(int i=0; i<N; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Enter the element you wish to search in this array: ";
    int x;
    cin>>x;
    int ans = search(arr, x);
    if(ans == -1)
        cout<<"The element can't be found...";
    else
        cout<<"The element is found at index "<<ans;
}