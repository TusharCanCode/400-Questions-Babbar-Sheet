#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(int N)
    {
        int i = 1, count = 0;
        while ((i * i) < N)
        {
            count++;
            i++;
        }
        return count;
    }
};

//OR

// int countSquares(int N)
// {
//     // code here
//     long long int i = 1, j = N, mid;
//     while (i <= j)
//     {
//         mid = (i + j) / 2;
//         if (mid * mid == N)
//             return mid - 1;

//         else if (mid * mid > N)
//         {
//             j = mid - 1;
//         }

//         else if (mid * mid < N)
//         {
//             i = mid + 1;
//         }
//     }
//     if (mid * mid > N)
//         return mid - 1;

//     return mid;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}