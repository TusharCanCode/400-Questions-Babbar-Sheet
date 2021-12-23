#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    int start1 = 0, start2 = 0, start3 = 0;
    int prev = INT_MIN;
    while (start1 < n1 && start2 < n2 && start3 < n3)
    {
        int a = A[start1], b = B[start2], c = C[start3];
        if (A[start1] == B[start2] && B[start2] == C[start3])
        {
            if (A[start1] != prev)
            {
                res.push_back(a);
                prev = a;
            }

            start1++;
            start2++;
            start3++;
        }
        else if (a == b && c < a)
        {
            start3++;
        }
        else if (b == c && a < c)
        {
            start1++;
        }
        else if (a == c && b < a)
        {
            start2++;
        }
        else if (a >= b && a >= c)
            start2++, start3++;
        else if (b >= c && b >= a)
            start1++, start3++;
        else if (c >= a && c >= b)
            start1++, start2++;
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the size of the array1: ";
    cin >> n;
    int arr1[n];
    cout << "Enter the elements of the array1 (in sorted fashion): ";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int m;
    cout << "Enter the size of the array2: ";
    cin >> m;
    int arr2[m];
    cout << "Enter the elements of the array2 (in sorted fashion): ";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    int o;
    cout << "Enter the size of the array3: ";
    cin >> o;
    int arr3[o];
    cout << "Enter the elements of the array3 (in sorted fashion): ";
    for (int i = 0; i < o; i++)
        cin >> arr3[i];

    cout<<"The common elements present in these three arrays are: ";
    vector<int>vec (commonElements(arr1, arr2, arr3, m, n, o));
    for(auto i: vec)
        cout<<i<<" ";
}