#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findSubString(string str)
    {
        int length = str.length();
        if (length == 1)
            return str;
        set<char> st;
        int unique = 0;
        for (auto i : str)
            st.insert(i);

        unique = st.size();

        unordered_map<char, int> m;
        int i = 0, j = 0, count = 0;
        int start = 0, end = INT_MAX;

        while (j < length)
        {
            if (m[str[j]] == 0)
                count++;

            m[str[j]]++;

            if (count == unique)
            {
                while (i < j && m[str[i]] > 1)
                {
                    m[str[i]]--;
                    i++;
                }

                if (j - i < end - start)
                {
                    end = j;
                    start = i;
                }
            }
            j++;
        }

        string ans;
        for (int x = start; x <= end; x++)
            ans.push_back(str[x]);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}