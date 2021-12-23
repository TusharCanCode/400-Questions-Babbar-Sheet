#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int profit;
    int dead;
};

static bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    int deadline[101] = {0};
    sort(arr, arr + n, comp);
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (deadline[arr[i].dead] == 0)
        {
            deadline[arr[i].dead] = 1;
            sum += arr[i].profit;
            count++;
        }
        else
        {
            int j = arr[i].dead - 1;
            while (j > 0)
            {
                if (deadline[j] == 0)
                {
                    deadline[j] = 1;
                    sum += arr[i].profit;
                    count++;
                    break;
                }
                else
                    j--;
            }
        }
    }
    return {count, sum};
}

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

        vector<int> ans = JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
}