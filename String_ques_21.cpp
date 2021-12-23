#include <iostream>
#include <stack>
using namespace std;

int countRev(string s)
{
    stack<char> st;
    int crev = 0;
    for (char i : s)
    {
        if (i == '{')
            st.push(i);
        else
        {
            if (st.empty())
            {
                crev++;
                st.push('{');
            }
            else
                st.pop();
        }
    }
    int count = 0;
    while (!st.empty())
    {
        count++;
        st.pop();
    }

    if (count % 2 != 0)
        return -1;

    crev += count / 2;
    return crev;
}

//Without Using stack:
// int countRev(string s)
// {
//     int count = 0;
//     int crev = 0;
//     for (char i : s)
//     {
//         if (i == '{')
//             count++;
//         else
//         {
//             if (count == 0)
//             {
//                 crev++;
//                 count++;
//             }
//             else
//                 count--;
//         }
//     }
//     if (count % 2 != 0)
//         return -1;

//     return crev + count / 2;
// }

int main()
{
    string x;
    cout << "Enter the paranthesis expression (should only contain '{' or '}'): ";
    cin >> x;
    cout << "Number of conversions required to balance this expression are: " << countRev(x);
}