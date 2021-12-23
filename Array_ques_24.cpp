#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    sort(arr, arr + N);
    int maximum = 1;
    int temp = 1;
    for (int i = 0; i < N - 1; i++)
    {
        if (arr[i + 1] - arr[i] == 1)
            temp++;

        else if (arr[i + 1] - arr[i] == 0)
            continue;

        else
            temp = 1;

        maximum = max(temp, maximum);
    }
    return maximum;
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

    cout<<"The longest common subsequence is of size: "<<findLongestConseqSubseq(arr, N);
}