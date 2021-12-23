#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string swap(string a, char first, char second)
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == first)
                a[i] = second;
            else if (a[i] == second)
                a[i] = first;
        }

        return a;
    }

    string chooseandswap(string a)
    {
        int arr[26] = {0};
        arr[a[0] - 'a'] = 1;
        char mini = '~';
        char prev = a[0];
        for (int i = 1; i < a.length(); i++)
        {
            if (arr[a[i] - 'a'])
                continue;
            arr[a[i] - 'a'] = 1;
            if (a[i] < prev)
                mini = min(mini, a[i]);

            prev = a[i];
        }
        for (char i : a)
            if (i > mini)
                return swap(a, i, mini);

        return a;
    }
};

int main()
{
    Solution obj;
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
    }
    return 0;
}