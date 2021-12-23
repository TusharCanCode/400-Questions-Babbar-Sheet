#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void swap(char &a, char &b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char> &s)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++, j--;
        }
        for(auto i:s)
            cout<<i;
    }
};

int main()
{
    int n;
    cout<<"Enter the size of the string: ";
    cin>>n;
    vector<char>input;
    cout<<"Enter the string: ";
    while(n--)
    {
        char a;
        cin>>a;
        input.push_back(a);
    }
    Solution obj;
    obj.reverseString(input);
}