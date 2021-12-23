#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i : nums)
    {
        if (++map[i] > 1)
            return i;
    }
    return INT_MIN;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter the values in the array(note there should be only one repeating element): ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "The duplicate number is: ";
    int ans = findDuplicate(arr);
    if (ans == INT_MIN)
        cout << "\nWelp it is found that there are no duplicate numbers.";
    else
        cout << ans;
}