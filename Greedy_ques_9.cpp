#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxStock(vector<int> &prices, int n, int amount)
    {
        vector<pair<int, int>> stocks;
        for (int i = 0; i < n; i++)
            stocks.push_back({prices[i], i + 1});

        sort(stocks.begin(), stocks.end());

        int count = 0, x;
        for (auto i : stocks)
        {
            if (i.first <= amount)
            {
                x = amount / i.first;
                x = min(x, i.second);
                count += x;
                amount -= (x * (i.first));
            }
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> prices(n);
        for (int i = 0; i < n; i++)
            cin >> prices[i];
        Solution ob;
        cout << ob.maxStock(prices, n, x) << endl;
    }
    return 0;
}