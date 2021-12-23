#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    vector<int> res;
    long long carry;
    long long temp;
    res.push_back(1);
    while (N > 0)
    {
        carry = 0;
        for (int i = 0; i < res.size(); i++)
        {
            temp = (res[i] * N) + carry;
            res[i] = temp % 10;
            carry = temp / 10;
        }
        while (carry != 0)
        {
            res.push_back(carry % 10);
            carry /= 10;
        }
        N--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout<<"Enter the number whose factorial you wish to find: ";
    int N;
    cin>>N;
    cout<<"The factorial of the entered number is: ";
    auto x = factorial(N);
    for(int i: x)
        cout<<i;
}