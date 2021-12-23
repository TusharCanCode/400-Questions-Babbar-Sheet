#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;
    for (int i = l; i <= r; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int kthLargest(int arr[], int l, int r, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = l; i <= r; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
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

    cout << "The sorted array is: ";
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    
    int k_largest, k_smallest;
    
    cout << "\nEnter the rank (th) of the largest number and the smallest number to be found respectively: ";
    cin >> k_largest >> k_smallest;
    
    cout << "The " << k_largest << "th largest element of the array is: " << kthLargest(arr, 0, size - 1, k_largest);
    cout << "The " << k_smallest << "th smallest element of the array is: " << kthSmallest(arr, 0, size - 1, k_smallest);
}