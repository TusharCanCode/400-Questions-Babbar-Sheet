#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        int sum = A[i];
        for (int j = i + 1, k = n - 1; j < k;)
        {
            sum += (A[j] + A[k]);
            if (X == sum)
                return true;
            else if (X > sum)
                j++;
            else
                k--;
            sum = A[i];
        }
    }
    return false;
}

int main()
{
    int n, X;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the sum of the triplet: ";
    cin >> X;

    int i, A[n];
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++)
        cin >> A[i];

    cout << "Does the such triplet exists: " << find3Numbers(A, n, X);
}