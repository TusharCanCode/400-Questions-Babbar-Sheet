#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int min = INT_MAX;
    char x;
    for (string i : strs)
        min = min > (int)i.length() ? (int)i.length() : min;
    for (int i = 0; i < min; i++)
    {
        x = strs[0][i];
        for (int j = 1; j < (int)strs.size(); j++)
        {
            if (strs[j][i] != x)
                return ans;
        }
        ans.push_back(x);
    }
    return ans;
}

int main()
{
    vector<string> x;
    cout << "Enter the number of strings you wish to enter: ";
    int n;
    cin >> n;
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++)
    {
        string temp; 
        cin >> temp;
        x.push_back(temp);
    }
    cout << "The longest common prefix in the entered strings is: " << longestCommonPrefix(x);
}