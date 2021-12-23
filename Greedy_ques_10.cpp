#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int utility(int N, int K)
    {
        int i = 0;
        while (i < N)
        {
            i++;
            N -= K;
        }

        return i;
    }

    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        int min = 0, max = 0;
        int count = utility(N, K);
        for (int i = 0; i < count; i++)
        {
            min += candies[i];
            max += candies[N - i - 1];
        }

        return {min, max};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}