#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);

int min(vector<int>arr)
{
    int a=INT_MAX;
    for(int i:arr)
    {
        if(i<a)
            a = i;
    }
    return a;
}

int max(vector<int>arr)
{
    int b=INT_MIN;
    for(int i:arr)
    {
        if(i>b)
            b = i;
    }
    return b;
}

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    int n = array1.size();
    int m = array2.size();
    
    for(int i=n-1, j = 0; i>=0 && j<m; )
    {
        if(array1[i] > array2[j])
        {
            swap(array1[i], array2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    double ans = 0;
    if((n+m)%2 != 0)
    {
        int x = (n+m)/2;
        if(x >= n)
        {
            x = x-n;
            sort(array2.begin(), array2.end());
            ans = array2[x];
        }
        else
        {
            sort(array1.begin(), array1.end());
            ans = array1[x];
        }
    }
    
    else
    {
        int x = (n+m)/2;
        int y = x-1;
        if(x > n)
        {
            x = x-n;
            y = y-n;
            sort(array2.begin(), array2.end());
            ans = (double)(array2[x] + array2[y])/2;
        }
        else if(x<n)
        {
            sort(array1.begin(), array1.end());
            ans = (double)(array1[x] + array1[y])/2;
        }
        else
        {
            int a = min(array2) + max(array1);
            ans = (double)a/2;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin>>array1[i];
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin>>array2[i];
        cout<<MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}