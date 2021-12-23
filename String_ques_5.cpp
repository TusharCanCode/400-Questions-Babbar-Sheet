#include <iostream>
#include <string>
using namespace std;

bool isrotated(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    return (s2 + s2).find(s1)!=string::npos;
}

int main()
{
    cout << "Enter the string: ";
    string s;
    getline(cin, s);
    cout << "Enter the other string: ";
    string srot;
    getline(cin, srot);
    if (isrotated(s, srot))
        cout << "The second string is the rotated version of the first string...";
    else
        cout << "The second string is not the rotated version of the first string...";
}