#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    void nextPermutation(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size()-1;
        int x = n;
        bool flag = false;
        for(; x>0; x--)
        {
            if(nums[x-1] < nums[x])
            {
                flag = true;
                --x;
                break;
            }
        }
        
        if(!flag)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int j = n; j>x; j--)
        {
            if(nums[x] < nums[j])
            {
                swap(nums[x], nums[j]);
                reverse(nums.begin()+x+1, nums.end());
               return;
            }
        }
        
    }
};

int main()
{
    int N;
    cout<<"Enter the length of the number:";
    cin>>N;
    vector<int>num;
    cout<<"Enter the digits of the number:";
    for (int i = 0; i < N; i++)
    {
        int a;
        cin>>a;
        num.push_back(a);
    }
    Solution obj;
    obj.nextPermutation(num);
    cout<<"The next permutation of the given number is: ";
    for(int i: num)
        cout<<i;
}