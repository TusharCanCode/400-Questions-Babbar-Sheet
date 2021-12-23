#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>&a, int R, int C)
{
    for(int i=0; i<R; i++)
    {
        for(int j=i+1; j<C; j++)
        {
            swap(a[i][j], a[j][i]);
        }
        reverse(a[i].begin(), a[i].end());
    }
}

int main()
{
    int R, C;
    cout<<"Enter the number of rows and columns: ";
    cin>>R>>C;
    vector<vector<int>>arr(R, vector<int>(C));
    for(int i=0; i<R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin>>arr[i][j];
        }   
    }
    cout<<"The array after rotating the entered array by 90 degrees:-\n";
    rotate(arr, R, C);
    for(auto i: arr)
    {
        for(int j : i)
        {
            cout<<j<<' ';
        }
        cout<<'\n';
    }
}