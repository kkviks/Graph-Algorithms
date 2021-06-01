#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &l, int n, int parent, vector<int> &visited, int color)
{
    visited[node] = color;
    for (int nbr : l[node])
    {
        if (visited[nbr] == -1)
        {
            bool isBipartite = dfs(nbr, l, n, node, visited, 1 - color);
            if (isBipartite == false)
            {
                return false;
            }
        }
        else if (nbr != parent and visited[nbr] == color)
        {
            return false;
        }
    }
    return true;
}

bool bipartite_check(vector<vector<int>> &l, int n)
{
    vector<int> visited(n, -1);
    bool ans = true;
    for (int i = 0; i < n and ans; i++)
    {
        if (visited[i] == -1)
        {
            ans &= dfs(i, l, n, -1, visited, 0);
        }
    }
    return ans;
}

int main()
{

    int n, e;
    cin >> n >> e;
    vector<vector<int>> l(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        l[u].push_back(v);
        l[v].push_back(u);
    }

    if (bipartite_check(l, n))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}