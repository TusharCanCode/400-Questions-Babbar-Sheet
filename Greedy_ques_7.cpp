#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> first, vector<int> second)
    {
        return first[0] < second[0];
    }

    int maxStop(vector<vector<int>> arr)
    {
        unordered_map<int, pair<int, int>> prev;
        for (auto i : arr)
        {
            if (prev.find(i[2]) == prev.end())
                prev[i[2]] = {-1, -1};
        }

        sort(arr.begin(), arr.end(), comp);

        int count = 0;
        int station;
        pair<int, int> previous;
        for (auto i : arr)
        {
            station = i[2];
            previous = prev[station];
            if (i[0] > previous.second)
            {
                prev[station] = {i[0], i[1]};
                count++;
            }

            else if (i[1] < previous.second)
                prev[station] = {i[0], i[1]};
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
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        Solution ob;
        cout << ob.maxStop(arr) << endl;
    }
    return 0;
}