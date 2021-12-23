#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int> trees, int target, int M)
{
    int sum = 0;
    for (int i : trees)
    {
        if (i > target)
            sum += (i - target);

        if (sum >= M)
            return true;
    }
    return false;
}

int main()
{
    int M, N, start = 0, end = INT_MIN;
    cin >> N >> M;
    vector<int> trees;
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        trees.push_back(ele);
        if (ele > end)
            end = ele;
    }

    int res = start;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (ispossible(trees, mid, M))
        {
            start = mid + 1;
            res = mid;
        }
        else
            end = mid - 1;
    }
    cout << res;
}