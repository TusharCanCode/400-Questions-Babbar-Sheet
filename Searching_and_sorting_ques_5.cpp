#include <bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C)
{
    int diff1 = B - A;
    int diff2 = C - A;
    if (diff1 * diff2 < 0)
        return A;

    if (abs(diff1) > abs(diff2))
        return C;

    return B;
}

int main()
{
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    cout << "The middle of the three numbers is (in sorted array): " <<middle(a, b, c);
}