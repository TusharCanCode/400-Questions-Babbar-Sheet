#include <bits/stdc++.h>
using namespace std;

void inorder_finder(vector<int> &arr, int index, vector<int> &in, int n)
{
    if (index >= n)
        return;

    inorder_finder(arr, 2 * index + 1, in, n);
    in.push_back(arr[index]);
    inorder_finder(arr, 2 * index + 2, in, n);
}

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int minimumSwaps(vector<int> &arr, int n)
{
    vector<int> inorder;
    inorder_finder(arr, 0, inorder, n);
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m.insert({inorder[i], i});

    int a, swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (sorted[i] != inorder[i])
        {
            a = m[sorted[i]];
            m[inorder[i]] = a;
            m[sorted[i]] = i;
            swap(inorder[i], inorder[a]);
            swaps++;
        }
    }
    return swaps;
}

int main()
{
    cout << "Enter the size of the array: ";
    int size, x;
    cin >> size;
    vector<int> tree;
    cout << "Enter the binary tree elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        tree.push_back(x);
    }
    cout << "Minimum swaps required to convert the entered binary tree into BST is: " << minimumSwaps(tree, size);
}