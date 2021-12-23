#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    int i, j = 0;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for (i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= res[j][1] && intervals[i][1] > res[j][1])
        {
            res[j][1] = intervals[i][1];
        }
        else if (intervals[i][0] > res[j][1])
        {
            res.push_back(intervals[i]);
            j++;
        }
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the number of intervals: ";
    cin>>n;
    vector<vector<int>> intervals;
    cout<<"Enter the intervals:\n";
    for(int i=0; i<n; i++)
    {
        int a, b;
        cout<<"start: ";
        cin>>a;
        cout<<"end: ";
        cin>>b;
        intervals.push_back({a,b});
        cout<<"\n";
    }

    cout<<"Merging the intervals....\nAfter merging: ";
    auto res = merge(intervals);
    for(auto i: res)
    {
        cout<<"[ ";
        for(int x: i)
        {
            cout<<x<<" ";
        }
        cout<<"]"<<" ";
    }
}