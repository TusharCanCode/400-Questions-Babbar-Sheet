#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> num = { "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string x;
    cout<<"Enter the string (in caps): ";
    getline(cin, x);
    cout<<"The equivalent mobile numeric keypad sequence is: ";
    for(char i:x)
    {
        if(i == ' ')
            cout<<0;
        
        else
            cout<<num[i-'A'];
    }
}