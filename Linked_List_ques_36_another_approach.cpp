#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        int s[256];
        memset(s, 0, sizeof(s));
        queue<char> q;
        int n = A.size();

        string res = "";
        for (int i = 0; i < n; i++)
        {
            char c = A[i];
            int j = (int)c;
            s[j]++;

            if (s[j] == 1)
                q.push(c);
            while (!q.empty() and s[(int)(q.front())] > 1)
                q.pop();

            if (q.empty())
                res.push_back('#');
            else
                res.push_back(q.front());
        }

        return res;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}