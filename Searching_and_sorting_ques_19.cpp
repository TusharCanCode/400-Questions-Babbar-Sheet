#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> result(vector<int> &soldiers, vector<int> &bishu, int N)
{
    vector<pair<int, int>> ans;
    sort(soldiers.begin(), soldiers.end());
    vector<int> sumconsec;
    int sum = 0;
    for (int i : soldiers)
    {
        sum += i;
        sumconsec.push_back(sum);
    }
    int index;
    for (int i : bishu)
    {
        auto ptr = upper_bound(soldiers.begin(), soldiers.end(), i);
        if (ptr == soldiers.end())
        {
            ans.push_back({N, sumconsec.back()});
        }
        else
        {
            index = ptr - soldiers.begin();
            ans.push_back({index, sumconsec[index] - soldiers[index]});
        }
    }
    return ans;
}

int main()
{
    int N, Q;
    cin >> N;
    vector<int> soldiers;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        soldiers.push_back(x);
    }
    cin >> Q;
    vector<int> bishu;
    for (int i = 0; i < Q; i++)
    {
        cin >> x;
        bishu.push_back(x);
    }
    auto ans = result(soldiers, bishu, N);
    for (auto x : ans)
    {
        cout << x.first << ' ' << x.second << '\n';
    }
}