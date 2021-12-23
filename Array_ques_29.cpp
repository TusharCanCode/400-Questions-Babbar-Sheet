#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int trappingWater(int arr[], int n)
    {
        int first = 0, second = 0;
        int firstindex = -1, secondindex = -1;
        int water = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1] && arr[i] > first)
                first = arr[i], firstindex = i;
            else if (arr[i] < arr[i + 1] && firstindex != -1)
                second = arr[i + 1], secondindex = i + 1;

            if (second >= first && firstindex != -1)
            {
                for (int j = firstindex + 1; j < secondindex; j++)
                {
                    water += (first - arr[j]);
                }
                first = 0, firstindex = -1, second = 0, secondindex = -1;
            }
        }
        if (firstindex != -1 && secondindex != -1)
        {
            for (int j = secondindex; j > firstindex; j--)
            {
                if (second - arr[j] >= 0)
                    water += (second - arr[j]);

                else
                    second = arr[j];
            }
        }
        return water;
    }
};

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
}