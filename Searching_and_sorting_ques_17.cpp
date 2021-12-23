#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    int count1=0, count2=0;
    while(a!=0)
    {
        a &= (a-1);
        count1++;
    }
    while(b!=0)
    {
        b &= (b-1);
        count2++;
    }
    return count1>count2;
}

int main() {
    cout<<"Enter the size of the array: ";
    int N;
    int arr[N];
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+N, comp);
    for(int i=0; i<N; i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}