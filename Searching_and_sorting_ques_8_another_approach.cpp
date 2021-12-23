#include <bits/stdc++.h>
using namespace std;

//The below algorithm is called Moore's Voting algorithm and works only if the largest occuring element is greater than size/2;
bool ismajority(int a[], int size, int val)
{
    int half = size / 2, count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == val)
            count++;
    }
    return count > half;
}
int majorityElement(int a[], int size)
{
    int index = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[i] == a[index])
            count++;
        else
            count--;

        if (count == 0)
            index = i, count = 1;
    }

    if (ismajority(a, size, a[index]))
        return a[index];
    return -1;
}

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
    cout << "The majority element in the array is: " << majorityElement(arr, N);
}