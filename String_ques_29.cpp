#include <iostream>
#include <unordered_map>
using namespace std;

string secFrequent(string arr[], int n)
{
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    string ans = "";
    string maxs = "";
    int max = 0, second_max = 0;
    for (auto i : m)
    {
        if (i.second >= max)
        {
            second_max = max;
            max = i.second;
            ans = maxs;
            maxs = i.first;
        }
        else if (i.second > second_max)
        {
            second_max = i.second;
            ans = i.first;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter number of strings: ";
    cin>>n;
    string arr[n];
    cout<<"Enter the strings: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The second-most frequent string is: "<<secFrequent(arr, n);
}