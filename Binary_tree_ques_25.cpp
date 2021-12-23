#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkMirrorTree(int n, int e, int A[], int B[])
    {
        vector<vector<int>> vecA(100000);
        vector<vector<int>> vecB(100000);
        int a1, a2, b1, b2;
        for (int i = 0; i < 2 * e; i += 2)
        {
            vecA[A[i]].push_back(A[i + 1]);
            vecB[B[i]].push_back(B[i + 1]);
        }

        for (int i = 0; i < (int)vecA.size(); i++)
        {
            if (vecA[i].size() != vecB[i].size())
                return 0;

            for (int j = 0, k = (int)vecA[i].size() - 1; j < (int)vecA[i].size(); j++, k--)
            {
                if (vecA[i][j] != vecB[i][k])
                    return 0;
            }
        }

        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;

        cin >> n >> e;
        int A[2 * e], B[2 * e];

        for (int i = 0; i < 2 * e; i++)
            cin >> A[i];

        for (int i = 0; i < 2 * e; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n, e, A, B) << endl;
    }
    return 0;
}