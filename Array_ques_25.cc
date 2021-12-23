#include<bits/stdc++.h>
using namespace std;

int freq(int arr[], int n, int k)
{
    unordered_map<int, int>map;
    for(int i = 0; i<n; i++)
        map[arr[i]]++;
    
    int count = 0;
    for(auto i: map)
    {
        if(i.second > (int)n/k)
            count++;
    }
    return count;
}

int main()
{
    int N;
    cout<<"Enter the size of the array: ";
    cin>>N;
    int arr[N];

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<N; i++)
        cin>>arr[i];

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Number of elements with frequency more than n/k are: "<<freq(arr, N, k);
}