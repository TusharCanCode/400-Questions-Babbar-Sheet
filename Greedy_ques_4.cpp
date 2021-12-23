#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dfs(int &begin, int start, vector<bool> &visited, int &mini, vector<vector<int>> &vec)
    {
        if (visited[start])
            return {};

        if (vec[start][0] != 0 && !visited[vec[start][0]])
        {
            if (vec[start][0] == begin)
                return {};

            return dfs(begin, vec[start][0], visited, mini, vec);
        }
        else if (vec[start][0] == 0)
            begin = start;

        visited[start] = true;

        if (vec[start][1] == 0)
            return {begin, start, mini};

        mini = min(mini, vec[start][2]);
        return dfs(begin, vec[start][1], visited, mini, vec);
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<vector<int>> vec(n + 1, vector<int>(3, 0));
        for (int i = 0; i < p; i++)
        {
            vec[a[i]][1] = b[i];
            vec[a[i]][2] = d[i];
            vec[b[i]][0] = a[i];
        }
        vector<vector<int>> ans;
        int mini, begin;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && vec[i][1] != 0)
            {
                mini = INT_MAX;
                begin = i;
                auto temp = dfs(begin, i, visited, mini, vec);
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
}