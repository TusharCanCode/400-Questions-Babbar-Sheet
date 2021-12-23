#include <bits/stdc++.h>
using namespace std;

int val(char x)
{
    switch (x)
    {
    case 'I':
        return 1;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    case 'V':
        return 5;
    }
    return 0;
}
int romanToDecimal(string &str)
{
    int n = str.length();
    int num = 0, i = 0;
    for (; i < n - 1; i++)
    {
        if (val(str[i]) < val(str[i + 1]))
        {
            num += val(str[i + 1]) - val(str[i]);
            i++;
        }
        else
        {
            num += val(str[i]);
        }
    }
    if (i == n - 1)
        num += val(str[n - 1]);
    return num;
}

int main()
{
    string x;
    cout<<"Enter a roman number: ";
    cin>>x;
    cout<<"It's decimal equivalent is: "<<romanToDecimal(x);
}