#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maximum = INT_MIN;
    int start = 0, end = 1, size = prices.size();
    if (size == 1)
        return 0;
    for (; end < size;)
    {
        if (prices[end] - prices[start] < 0)
            start = end++;
        else
        {
            maximum = max(maximum, prices[end] - prices[start]);
            end++;
        }
    }
    if (maximum == INT_MIN)
        return 0;
    return maximum;
}

int main()
{
    vector<int> prices;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        int x;
        cin>>x;
        prices.push_back(x);
    }
    cout << "The maximum profit that can be achieved by buying and selling stocks: " << maxProfit(prices);
}