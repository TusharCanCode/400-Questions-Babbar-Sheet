#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    set<string> s;
    int size = arr.size();
    int sum = 0;
    vector<vector<int>> ans;

    for (int i = 0; i < size - 3; i++)
    {
        sum += arr[i];
        for (int j = i + 1; j < size - 2; j++)
        {
            sum += arr[j];
            for (int start = j + 1, end = size - 1; start < end;)
            {
                if (sum + arr[start] + arr[end] == k)
                {
                    stringstream ss;
                    ss << arr[i] << arr[j] << arr[start] << arr[end];
                    string search;
                    ss >> search;
                    if (s.find(search) == s.end())
                    {
                        ans.push_back({arr[i], arr[j], arr[start], arr[end]});
                        s.insert(search);
                    }

                    start++, end--;
                }

                else if (sum + arr[start] + arr[end] < k)
                    start++;
                else
                    end--;
            }
            sum = arr[i];
        }
        sum = 0;
    }
    return ans;
}

int main()
{
    cout << "Enter the size of the array: ";
    int N;
    cin >> N;
    vector<int> arr;
    cout << "Enter the elements of the array: ";
    int val;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    cout << "Enter the sum of quadruple you wish to find: ";
    int sum;
    cin >> sum;
    cout << "The unique quadruple with sum = " << sum << " are: ";
    auto ans = fourSum(arr, sum);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << ' ';

        cout << endl;
    }
}