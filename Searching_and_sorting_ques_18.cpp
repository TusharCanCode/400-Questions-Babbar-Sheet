#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    vector<int> temp;
    unordered_map<int, int> map;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        temp.push_back(nums[i]);
        map.insert({nums[i], i});
    }
    sort(temp.begin(), temp.end());
    int count = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        if (temp[i] != nums[i])
        {
            count++;
            map[nums[i]] = map[temp[i]];
            swap(nums[i], nums[map[temp[i]]]);
        }
    }
    return count;
}

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    cout << "The minimum number of swaps required to sort the array is: " << minSwaps(nums);
}