#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> x;
        for (int i = 0; i < n; i++)
            x.push_back({start[i], end[i]});

        sort(x.begin(), x.end());
        int ans = 0;
        pair<int, int> prev = {-1, -1};

        for (auto i : x)
        {
            if (i.first > prev.second)
            {
                prev = i;
                ans++;
            }

            else if (i.second < prev.second)
                prev = i;
        }

        return ans;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}