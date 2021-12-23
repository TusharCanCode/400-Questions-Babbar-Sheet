#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        vector<int> temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                temp.push_back(Mat[i][j]);
        }
        sort(temp.begin(), temp.end());
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
                Mat[i][j] = temp.back(), temp.pop_back();
        }
        return Mat;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}