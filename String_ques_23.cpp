#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<char>> &mat, string target, int index, int i, int j, vector<vector<bool>> &visited)
{
    if (i == (int)mat.size() || j == (int)mat[0].size() || i < 0 || j < 0)
        return 0;

    if (mat[i][j] != target[index] || visited[i][j])
        return 0;

    visited[i][j] = true;

    if (index == (int)target.size() - 1 && mat[i][j] == target[index])
    {
        visited[i][j] = false;
        return 1;
    }

    int answer = dfs(mat, target, index + 1, i + 1, j, visited) + dfs(mat, target, index + 1, i - 1, j, visited) + dfs(mat, target, index + 1, i, j + 1, visited) + dfs(mat, target, index + 1, i, j - 1, visited);
    visited[i][j] = false;
    return answer;
}
int findOccurrence(vector<vector<char>> &mat, string target)
{
    int r = mat.size();
    int c = mat[0].size();
    int ans = 0;
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == target[0])
            {
                ans += dfs(mat, target, 0, i, j, visited);
            }
        }
    }
    return ans;
}

int main()
{
    cout<<"Enter the row and column of the character matrix: ";
    int R, C;
    cin>>R>>C;
    vector<vector<char>>mat(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin>>mat[i][j];
        }
        
    }

    cout<<"Enter the string you wish to find in the matrix: ";
    string x;
    cin>>x;

    cout<<"The number of occurences of the entered string in the character matrix are: "<<findOccurrence(mat, x);  
}