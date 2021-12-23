#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)
{
    int ans = 0;
    vector<int> table;
    for (int i = 0; i < n; i++)
        table.push_back(a[i]);

    for (int j = 0; j < m; j++)
        table.push_back(b[j]);

    sort(table.begin(), table.end());
    int prev = -1;
    for (int i : table)
    {
        if (i != prev)
        {
            ans++;
            prev = i;
        }
    }
    return ans;
}

//Solution using unordered_map
/*
int doUnion(int a[], int n, int b[], int m)
{
    //code here
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[a[i]]++;

    for (int j = 0; j < m; j++)
        map[b[j]]++;

    return map.size();
}
*/

int main()
{
    int n, m;
    cout << "Enter the size of first array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nEnter the size of the second array: ";
    cin >> m;
    int b[m];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < m; i++)
        cin >> b[i];

    cout << "\nThe union of these two arrays will consist of " << doUnion(a, n, b, m) << " elements.";
}