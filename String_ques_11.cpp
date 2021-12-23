#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_set<string> temp;
    vector<string> ans;
    void utility(string S, int index)
    {
        if (index > (int)S.size())
            return;

        for (int i = index; i < (int)S.size(); i++)
        {
            swap(S[index], S[i]);
            if (temp.find(S) == temp.end())
            {
                ans.push_back(S);
                temp.insert(S);
            }
            utility(S, index + 1);
            swap(S[index], S[i]);
        }
    }
    vector<string> find_permutation(string S)
    {
        utility(S, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}