#include <iostream>
#include <vector>
using namespace std;

bool issame(string &pat, string &txt, int start)
{
    int end = pat.size() - 1;
    for (int i = start, j = 0; i <= start + end; i++, j++)
    {
        if (txt[i] != pat[j])
            return false;
    }
    return true;
}
void search(string pat, string txt)
{
    vector<int> res;
    int end = txt.size() - pat.size();
    for (int i = 0; i <= end; i++)
    {
        if (issame(pat, txt, i))
            res.push_back(i + 1);
    }
    if (res.empty())
        cout<<"-1";
    else
    {
        for(int i: res)
            cout<<i<<' ';
    }
}

int main()
{
    string text;
    cout<<"Enter the text string: ";
    getline(cin,text);
    cout<<"Enter the pattern you wish to find in the text string: ";
    string pattern;
    cin>>pattern;
    cout<<"The starting position of the substring in the text which are same as the pattern entered are: ";
    search(pattern, text);
}