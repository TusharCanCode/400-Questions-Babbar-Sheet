//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> find_it;

    void isthere(string x, int index)
    {
        sort(x.begin(), x.end());
        if (find_it.find(x) == find_it.end())
        {
            find_it.insert({x, {index}});
        }
        else
            find_it[x].push_back(index);
    }

    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        for (int i = 0; i < (int)string_list.size(); i++)
        {
            isthere(string_list[i], i);
        }
        for (auto i : find_it)
        {
            vector<string> temp;
            for (auto j : i.second)
                temp.push_back(string_list[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}