

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void check(vector<pair<int, int>> &platforms, int arrival, int departure)
    {
        for (int i = 0; i < platforms.size(); i++)
        {
            if (platforms[i].second < arrival)
            {
                platforms[i] = {arrival, departure};
                return;
            }
        }
        platforms.push_back({arrival, departure});
    }

    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, int>> platforms;
        vector<pair<int, int>> timing;
        for (int i = 0; i < n; i++)
            timing.push_back({arr[i], dep[i]});

        sort(timing.begin(), timing.end());

        platforms.push_back(timing[0]);
        for (int i = 1; i < n; i++)
            check(platforms, timing[i].first, timing[i].second);

        return platforms.size();
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}