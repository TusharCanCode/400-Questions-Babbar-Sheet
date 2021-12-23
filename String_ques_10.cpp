#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<string>sets;
void subsequences(string &s, int index, string x)
{
    if(index >= (int)s.size())
        return;
    for(int i=index; i<(int)s.size(); i++)
    {
        x.push_back(s[i]);
        if(sets.find(x) == sets.end())
        {
            cout<<x<<' ';
            sets.insert(x);
        }
        subsequences(s, i+1, x);
        x.pop_back();
    }
}

int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"All the possible subsequences of the entered string are as follow:-\n";
    subsequences(s, 0, "");
}