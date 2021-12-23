#include <bits/stdc++.h>
using namespace std;

pair<double, double> optimalpoints(vector<pair<int, int>>&points, vector<int>&line)
{
    double x_1 = -1e+10, x_2 = 1e+10, mid;
    double dis_1, dis_2;
    while(x_1 - x_2 > 1e-6)
    {
        
    }
}

int main()
{
    vector<int> line;
    cout << "Enter the a, b and c coffieints of line (ax + by + c): ";
    for (int i = 0; i < 3; i++)
    {
        int a;
        line.push_back(a);
    }
    
    cout<<"Enter the number of points you wish to enter: ";
    int N;
    cin>>N;

    vector<pair<int, int>>points;
    cout<<"Enter the points: ";
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin>>a>>b;
        points.push_back({a, b});
    }
}