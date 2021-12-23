#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int> map;
        int sum = 0;
        map.insert(0);
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (map.find(sum) != map.end())
                return true;

            map.insert(sum);
        }
        return false;
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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}