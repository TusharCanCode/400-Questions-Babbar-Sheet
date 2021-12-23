#include <bits/stdc++.h>
using namespace std;

long long int utility(int arr1[], vector<long long int> &sum1, vector<long long int> &sum2, unordered_map<int, int> &map2, int n1, int n2)
{
    long long int ans = 0;
    int start = 0, prev1 = -1, prev2 = -1;
    while (start < n1)
    {
        if (map2.find(arr1[start]) != map2.end())
        {
            if (prev1 == -1)
            {
                ans += (sum1[start] > sum2[map2[arr1[start]]] ? sum1[start] : sum2[map2[arr1[start]]]);
            }
            else
            {
                ans += max(sum1[start] - sum1[prev1], sum2[map2[arr1[start]]] - sum2[prev2]);
            }
            prev1 = start;
            prev2 = map2[arr1[start]];
        }
        start++;
    }
    if (prev1 == -1)
    {
        ans += max(sum1[n1 - 1], sum2[n2 - 1]);
    }
    else
    {
        ans += max(sum1[n1 - 1] - sum1[prev1], sum2[n2 - 1] - sum2[prev2]);
    }
    return ans;
}

int main()
{
    int n1, n2;
    while (true)
    {
        cin >> n1;
        if (n1 == 0)
            break;

        int arr1[n1];

        vector<long long int> sum1;
        vector<long long int> sum2;
        unordered_map<int, int> map2;

        long long sum = 0;
        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
            sum += arr1[i];
            sum1.push_back(sum);
        }

        cin >> n2;
        if (n2 == 0)
        {
            cout << sum1[n1 - 1] << '\n';
            continue;
        }
        int ele;

        sum = 0;
        for (int i = 0; i < n2; i++)
        {
            cin >> ele;
            map2[ele] = i;
            sum += ele;
            sum2.push_back(sum);
        }

        cout << utility(arr1, sum1, sum2, map2, n1, n2) << '\n';
    }
    return 0;
}