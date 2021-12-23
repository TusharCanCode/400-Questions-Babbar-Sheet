#include <iostream>
#include <vector>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int>> dp(x + 1, vector<int>(y + 1));
    for (int i = 0; i <= x; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= y; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}

int main()
{
    string s1, s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    int a = s1.length(), b = s2.length();
    cout<<"The length of the longest common subsequence in first string and the second string is: "<<lcs(a, b, s1, s2);
}