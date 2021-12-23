#include <iostream>
using namespace std;

int minFlips(string S)
{
    int count = 0;
    int n = S.size();
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && S[i] == '1')
            count++;

        else if (i % 2 != 0 && S[i] == '0')
            count++;
    }
    return count < n - count ? count : n - count;
}

int main()
{
    string x;
    cout<<"Enter a binary string: ";
    cin>>x;
    cout<<"The minimum number of flips required to arrange the bits in alternative positions are: "<<minFlips(x);
}