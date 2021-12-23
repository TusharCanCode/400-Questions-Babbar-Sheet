#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    inline double utility(Item temp)
    {
        return (double)temp.value / temp.weight;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);
        double ans = 0;
        Item temp;
        for (int i = 0; i < n && W > 0; i++)
        {
            temp = arr[i];
            if (temp.weight < W)
            {
                ans += temp.value;
                W -= temp.weight;
            }

            else
            {
                ans += utility(temp) * W;
                W = 0;
            }
        }
        return ans;
    }
};

int main()
{
    int t;

    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {

        int n, W;
        cin >> n >> W;

        Item arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}