#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void row(vector<int> &res, vector<vector<int>> &matrix, int row, int start, int end)
    {
        for (int i = start; i <= end; i++)
            res.push_back(matrix[row][i]);
    }

    void rowreverse(vector<int> &res, vector<vector<int>> &matrix, int row, int start, int end)
    {
        for (int i = start; i >= end; i--)
            res.push_back(matrix[row][i]);
    }

    void column(vector<int> &res, vector<vector<int>> &matrix, int column, int start, int end)
    {
        for (int i = start; i <= end; i++)
            res.push_back(matrix[i][column]);
    }

    void columnreverse(vector<int> &res, vector<vector<int>> &matrix, int column, int start, int end)
    {
        for (int i = start; i >= end; i--)
            res.push_back(matrix[i][column]);
    }

    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> result;
        int rowstart = 0, columnstart = 0, columnend = c - 1, rowend = r - 1;
        while (rowstart <= rowend && columnstart <= columnend)
        {
            if (rowstart <= rowend && columnstart <= columnend)
            {
                row(result, matrix, rowstart, columnstart, columnend);
                rowstart++;
            }

            if (rowstart <= rowend && columnstart <= columnend)
            {
                column(result, matrix, columnend, rowstart, rowend);
                columnend--;
            }

            if (rowstart <= rowend && columnstart <= columnend)
            {
                rowreverse(result, matrix, rowend, columnend, columnstart);
                rowend--;
            }

            if (rowstart <= rowend && columnstart <= columnend)
            {
                columnreverse(result, matrix, columnstart, rowend, rowstart);
                columnstart++;
            }
        }
        return result;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
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
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}