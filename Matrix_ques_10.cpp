#include<bits/stdc++.h>
using namespace std;

int main()
{
    int R, C;
    cout<<"Enter the number of rows and columns of the matrix: ";
    cin>>R>>C;
    cout<<"Enter the elements of array: ";
    vector<vector<int>>matrix(R, vector<int>(C));
    unordered_map<int, int>m;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>matrix[i][j];
            m[matrix[i][j]]++;
        }
    }
    cout<<"The duplicate numbers in the array are: ";
    for(auto i: m)
    {
        if(i.second > 1)
            cout<<i.first<<' ';
    }
}