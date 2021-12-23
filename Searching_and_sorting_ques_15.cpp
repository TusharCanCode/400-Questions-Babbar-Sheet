#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    ll findSubarray(vector<ll> arr, int n)
    {
        unordered_map<ll, ll> m;
        ll sum = 0;
        ll answer = 0;
        m[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (m[sum] != 0)
                answer += m[sum];

            m[sum]++;
        }

        return answer;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; //input size of array

        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++)
            cin >> arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr, n) << "\n";
    }
    return 0;
}