#include <bits/stdc++.h>
using namespace std;

int bestjump(int arr[], int start, int val, int n)
{
    int best = INT_MIN;
    int index = start;
    for (int i = start; i < n && i < start + val; i++)
    {
        if (i + arr[i] > best)
        {
            best = i + arr[i];
            index = i;
        }
    }
    return index;
}
int minJumps(int arr[], int n)
{
    int jumps = 0;
    for (int i = 0; i < n;)
    {
        jumps++;

        if (arr[i] <= 0)
            return -1;
        else if (arr[i] + i + 1 >= n)
            return jumps;

        i = bestjump(arr, i + 1, arr[i], n);
    }
    return -1;
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

    cout << "The minimum jumps required to reach the end of the array are: ";
    int jumps = minJumps(arr, size);
    
    if (jumps == -1)
        cout << "\nWelp, it is found that we can't reach the end of the array :(";

    else
        cout << jumps;
}