#include <iostream>
#include <stack>
using namespace std;

bool isopening(char t)
{
    return (t == '(' || t == '[' || t == '{');
}

char openingpair(char t)
{
    switch (t)
    {
    case ')':
        return '(';

    case ']':
        return '[';

    case '}':
        return '{';
    }
    return '\0';
}
bool ispar(string x)
{
    stack<char> temp;
    for (char i : x)
    {
        if (isopening(i))
            temp.push(i);
        else
        {
            if (temp.empty())
                return false;
            if (openingpair(i) != temp.top())
                return false;
            temp.pop();
        }
    }
    return temp.empty();
}

int main()
{
    string x;
    cout<<"Enter the paranthesis experession which should only contain {, [, (, }, ], ) : ";
    cin>>x;
    if(ispar(x))
        cout<<"The entered paranthesis expression is balanced...";
    else
        cout<<"The entered paranthesis experssion is unbalanced...";
}