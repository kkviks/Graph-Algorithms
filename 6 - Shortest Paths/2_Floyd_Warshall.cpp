#include <bits/stdc++.h>
using namespace std;

class Graph
{
    const int INF = INT_MAX / 2;
    vector<vector<int>> g;

public:
    Graph(int n)
    {
        g.reserve(n);
        for (int i = 0; i < g.size(); i++)
        {
            g[i].reserve(n);
            for (int j = 0; j < g[i].size(); j++)
            {
                g[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int w)
    {
        //Unidirectional Graph
        g[u][v] = w;
    }

    vector<vector<int>> floyd_warshal()
    {
        vector<vector<int>> dp(g); //Change maybe?
        for (int k = 0; k < dp.size(); k++)
        {
            for (int i = 0; i < dp.size(); i++)
            {
                for (int j = 0; j < dp[i].size(); j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        vector<vector<int>> &distances = dp;
        return distances;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph g(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    auto dist = g.floyd_warshal();
    int i = 1, j = n;
    cout << dist[i][j] << endl;
    
    return 0;
}