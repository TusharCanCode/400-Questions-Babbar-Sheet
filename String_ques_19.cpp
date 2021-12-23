#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int lps(string s)
{
    if (s.length() == 1)
        return 0;

    int count = 0;
    int n = s.size() - 1;
    int j = n;
    int pos = n;

    while (j > 0)
    {
        if (s[j] == s[0])
            pos = j;
        j--;
    }

    for (int i = 0, k = pos; k <= n;)
    {
        if (s[k] == s[i])
        {
            count++;
            i++;
            k++;
        }
        else
        {
            i = 0;
            count = 0;

            do
            {
                pos++;
            } while (pos <= n && s[pos] != s[0]);

            k = pos;
        }
    }

    return count;
}

int main()
{
    string x;
    cout<<"Enter a string: ";
    cin>>x;
    cout<<"The length of longest prefix which is also a suffix is: "<<lps(x);
}