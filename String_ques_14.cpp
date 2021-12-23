#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int utility(string s, string t, int size1, int size2, vector<vector<int>> &dp)
{
    if (size2 == 0 || size1 == 0)
        return abs(size2 - size1);

    if (dp[size1][size2] != -1)
        return dp[size1][size2];

    if (s[size1 - 1] == t[size2 - 1])
        return dp[size1][size2] = utility(s, t, size1 - 1, size2 - 1, dp);

    return dp[size1][size2] = min(min(utility(s, t, size1 - 1, size2 - 1, dp), utility(s, t, size1 - 1, size2, dp)), utility(s, t, size1, size2 - 1, dp)) + 1;
}

int editDistance(string s, string t)
{
    int a = s.size();
    int b = t.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
    return utility(s, t, a, b, dp);
}

int main()
{
    string s1, s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    cout<<"The number of operations on string 1 required to convert string 1 to string 2 is: "<<editDistance(s1, s2);
}