#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> startindex;
    int utility(vector<int> &nums, int &k, int index)
    {
        if (startindex.find(index) != startindex.end())
            return startindex[index];
        int n = nums.size();
        if (index >= n)
            return 0;

        int min = INT_MAX;
        int sum = 0;
        int temp;
        for (int i = index; i < n; i++)
        {
            if (sum != 0)
                sum++;

            sum += nums[i];
            if (sum <= k && i != n - 1)
                temp = (k - sum) * (k - sum) + utility(nums, k, i + 1);

            else if (sum <= k && i == n - 1)
                temp = utility(nums, k, i + 1);

            else
                break;

            min = min < temp ? min : temp;
        }
        return startindex[index] = min;
    }
    int solveWordWrap(vector<int> nums, int k)
    {
        return utility(nums, k, 0);
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
}