#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0;
        int r = matrix.size(), c = matrix[0].size();
        while (i < r)
        {
            if (matrix[i][c - 1] == target)
                return true;

            else if (matrix[i][c - 1] > target)
            {
                for (int k = c - 2; k >= 0; k--)
                {
                    if (matrix[i][k] == target)
                        return true;
                }
                return false;
            }
            else
                i++;
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c, target;
        cin >> r >> c >> target;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        bool result = ob.searchMatrix(matrix, target);
        cout << "answer: " << result;
    }
    return 0;
}