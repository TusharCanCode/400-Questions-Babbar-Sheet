#include <bits/stdc++.h>
using namespace std;

//Using Floyd's tortoise hare algorithm
int findDuplicate(vector<int> &nums)
{
    int tortoise = nums[0];
    int hare = nums[0];
    do
    {
        hare = nums[hare];
        tortoise = nums[nums[tortoise]];
    }
    (tortoise != hare);

    hare = nums[0];
    while (hare != tortoise)
    {
        hare = nums[hare];
        torotise = nums[tortoise];
    }
    return hare;
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