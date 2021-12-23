#include <iostream>
#include <vector>
using namespace std;

int utility(string &str, int a, int b, vector<vector<int>> &dp)
{
    if (a >= str.length() || b >= str.length())
        return 0;

    else if (dp[b][a] != -1)
        return dp[b][a];

    if (str[a] == str[b] && a != b)
        return dp[b][a] = max(utility(str, a + 1, b + 1, dp), utility(str, a + 1, b + 1, dp)) + 1;

    return dp[b][a] = max(utility(str, a + 1, b, dp), utility(str, a, b + 1, dp));
}
int LongestRepeatingSubsequence(string str)
{
    int a = str.size();
    vector<vector<int>> dp(a, vector<int>(a, -1));
    return utility(str, 0, 0, dp);
}

int main()
{
    string x;
    cout << "Enter a string: ";
    getline(cin, x);
    cout << "The longest recurring subsequence in the string is: "<<LongestRepeatingSubsequence(x);
}