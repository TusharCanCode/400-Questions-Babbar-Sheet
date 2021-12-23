#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int row = -1, end = m - 1;
        for (int i = 0; i < n; i++)
        {
            while (end >= 0 && arr[i][end] == 1)
            {
                end--;
                row = i;
            }
        }
        return row;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}