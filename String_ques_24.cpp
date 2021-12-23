#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    int r;
    int c;
    bool check_top(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (i >= (int)word.size() - 1)
        {
            int start = 0;
            while (i >= 0 && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                i--;
            }
            return true;
        }
        return false;
    }
    bool check_left(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (j >= (int)word.size() - 1)
        {
            int start = 0;
            while (j >= 0 && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                j--;
            }
            return true;
        }
        return false;
    }
    bool check_bottom(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (r - i >= (int)word.size())
        {
            int start = 0;
            while (i < r && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                i++;
            }
            return true;
        }
        return false;
    }
    bool check_right(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (c - j >= (int)word.size())
        {
            int start = 0;
            while (j < c && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                j++;
            }
            return true;
        }
        return false;
    }
    bool check_topleft(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (min(j, i) >= (int)word.size() - 1)
        {
            int start = 0;
            while (j >= 0 && i >= 0 && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                j--;
                i--;
            }
            return true;
        }
        return false;
    }
    bool check_topright(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (min(c - j, i + 1) >= (int)word.size())
        {
            int start = 0;
            while (j < c && i >= 0 && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                j++;
                i--;
            }
            return true;
        }
        return false;
    }
    bool check_bottomleft(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (min(r - i, j + 1) >= (int)word.size())
        {
            int start = 0;
            while (i < r && j >= 0 && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                i++;
                j--;
            }
            return true;
        }
        return false;
    }
    bool check_bottomright(int i, int j, string &word, vector<vector<char>> &grid)
    {
        if (min(r - i, c - j) >= (int)word.size())
        {
            int start = 0;
            while (i < r && j < c && start < (int)word.size())
            {
                if (grid[i][j] != word[start])
                    return false;
                start++;
                i++;
                j++;
            }
            return true;
        }
        return false;
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        r = grid.size();
        c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == word[0])
                {
                    bool res = check_top(i, j, word, grid) || check_bottom(i, j, word, grid) || check_left(i, j, word, grid) || check_right(i, j, word, grid) || check_topleft(i, j, word, grid) || check_topright(i, j, word, grid) || check_bottomleft(i, j, word, grid) || check_bottomright(i, j, word, grid);
                    if (res)
                        ans.push_back({i, j});
                }
            }
        }
        if (ans.empty())
            return {{-1}};
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
}