#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    string x;
    void rec(string s, int index, int pos)
    {
        if (pos == 3 && index < (int)x.size())
        {
            string temp;
            for (int i = index; i < (int)x.size(); i++)
            {
                if (!temp.empty() && temp[0] == '0')
                    return;
                temp.push_back(x[i]);
            }

            if (stoi(temp) <= 255)
            {
                ans.push_back(s + temp);
            }
            return;
        }

        else if (index == (int)x.size())
            return;

        string temp;
        for (int i = index; i < (int)x.size(); i++)
        {
            if (!temp.empty() && temp[0] == '0')
                return;
            temp.push_back(x[i]);
            if (stoi(temp) <= 255)
            {
                temp.push_back('.');
                rec(s + temp, i + 1, pos + 1);
                temp.pop_back();
            }
            else
            {
                return;
            }
        }
        return;
    }

    vector<string> genIp(string &s)
    {
        x = s;
        int size = s.length();
        if (size > 12 || size < 4)
            return {};
        rec("", 0, 0);
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        for (auto &u : str)
        {
            cout << u << "\n";
        }
    }
}