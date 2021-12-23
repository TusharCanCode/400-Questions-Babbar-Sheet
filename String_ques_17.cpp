#include <iostream>
#include <vector>
using namespace std;

bool isfound(vector<string> &B, string find)
{
    for (int i = 0; i < (int)B.size(); i++)
    {
        if (B[i] == find)
            return true;
    }
    return false;
}

bool utility(string &A, int start, vector<string> &B, vector<int> &dp)
{
    int size = A.size();
    if (start == size)
        return true;

    if (dp[start] != -1)
        return dp[start];

    string x;
    bool res = false;
    for (int i = start; i < size; i++)
    {
        x.push_back(A[i]);
        if (isfound(B, x))
        {
            res = utility(A, i + 1, B, dp);
            if (res)
                return dp[start] = res;
        }
    }
    return dp[start] = res;
}
int wordBreak(string A, vector<string> &B)
{
    //code here
    int a = A.size();
    vector<int> dp(a + 1, -1);
    return utility(A, 0, B, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}