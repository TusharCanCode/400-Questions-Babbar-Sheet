#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string temp = countAndSay(n - 1);
    string ans = "";
    int count = 0;
    char val = temp[0];
    for (auto i : temp)
    {
        if (i == val)
            count++;
        else
        {
            stringstream s;
            s << count << val;
            string x;
            s >> x;
            ans += x;
            count = 1;
            val = i;
        }
    }
    stringstream s;
    s << count << val;
    string x;
    s >> x;
    ans += x;
    return ans;
}

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    cout<<"The count and say sequence of the entered number is: ";
    cout<<countAndSay(number);
}