#include <iostream>
using namespace std;

int minimumNumberOfSwaps(string S)
{
    int count = 0;
    int ans = 0;
    for (auto i : S)
    {
        if (count < 0 && i == '[')
            ans = ans - count;

        if (i == '[')
            count++;
        else if (i == ']')
            count--;
    }

    return ans;
}

int main()
{
    string x;
    cout<<"Enter a paranthesis expression that should contains equal number of [ and ] : ";
    cin>>x;
    cout<<"The minimum number of adjacent swaps required to balance the equation are: "<<minimumNumberOfSwaps(x);
}