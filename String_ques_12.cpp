#include<bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n)
{
    int count0 = 0, count1 = 0;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
        if (count0 == count1)
        {
            ans++;
        }
    }

    if (ans == 0)
    {
        return -1;
    }

    return ans;
}

int main()
{
    string str = "0100110101";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}