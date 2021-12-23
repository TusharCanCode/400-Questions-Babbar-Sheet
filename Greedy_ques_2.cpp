

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    static bool comp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job vec[], int n)
    {
        sort(vec, vec + n, comp);
        vector<bool> s(110, true);
        int count = 0;
        int profit = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[vec[i].dead])
            {
                count++;
                profit += vec[i].profit;
                s[vec[i].dead] = false;
            }
            else
            {
                for (int j = vec[i].dead; j >= 1; j--)
                {
                    if (s[j])
                    {
                        count++;
                        profit += vec[i].profit;
                        s[j] = false;
                        break;
                    }
                }
            }
        }

        return {count, profit};
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
        Job arr[n];

        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;

        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}