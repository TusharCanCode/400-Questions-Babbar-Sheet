#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n, m;
    vector<vector<int>> edgeList;

public:
    Graph() {}
    Graph(int n, int m) : n(n), m(m) {}
    void add_edge(int a, int b)
    {
        edgeList.push_back({a, b});
    }

    bool dfs_finder(vector<vector<int>> &graph, vector<int> &visited, vector<int> &dfs, int index)
    {
        if (visited[index] == 1 && dfs[index] == 1)
            return false;
        else if (visited[index] == 1 && dfs[index] == 0)
        {
            dfs[index] = 1;
            return true;
        }

        bool check;
        visited[index] = 1;
        for (auto i : graph[index])
        {
            check = dfs_finder(graph, visited, dfs, i);
            if (!check)
                return false;
            dfs[index] = 0;
        }
        return true;
    }

    bool isGraphTree()
    {
        vector<vector<int>> graph(n);
        for (auto i : edgeList)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<int> visited(n, 0);
        vector<int> dfs(n, 0);

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans = dfs_finder(graph, visited, dfs, i);
                if (ans == false)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    int x, y, a, b;
    cout << "Enter number of vertices and edges respectively: ";
    cin >> x >> y;

    Graph g(x, y);
    cout << "Enter the pair of vertices connected by an edge:\n";
    for (int i = 0; i < y; i++)
    {
        cout << "Edge - " << i + 1 << " : ";
        cin >> a >> b;
        g.add_edge(a, b);
    }

    if (g.isGraphTree())
        cout << "The entered graph is a tree";
    else
        cout << "The entered graph is not a tree";
}