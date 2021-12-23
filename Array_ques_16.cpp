#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findminimumswaps(int *arr, int N)
{
    vector<int>temp;
    for(int i=0; i<N; i++)
    {
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end());
    unordered_map<int, int> map;
}

int main()
{
    int N;
    cout << "Enter the size of the array:";
    cin >> N;
    cout << "Enter the elements of the array:";
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        arr[i] = val;
    }

    cout << "The minimum number of swaps required to sort the given array is: " << findminimumswaps(arr, N);
}