#include <bits/stdc++.h>
using namespace std;

void dfs2(int node, vector<vector<int>> &l, vector<int> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (auto nbr : l[node])
    {
        if (!visited[nbr])
        {
            dfs2(nbr, l, visited);
        }
    }
}

void dfs1(int node, vector<vector<int>> &l, vector<int> &visited, vector<int> &ordering)
{
    visited[node] = true;

    for (auto nbr : l[node])
    {
        if (!visited[nbr])
        {
            dfs1(nbr, l, visited, ordering);
        }
    }
    ordering.push_back(node);
}

void SSC(vector<vector<int>> &l, vector<vector<int>> &rev_l, int n)
{
    vector<int> visited(n, 0), ordering;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i, l, visited, ordering);
        }
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    char component = 'A';
    for (int i = ordering.size() - 1; i >= 0; i--)
    {
        int x = ordering[i];
        if (!visited[x])
        {
            cout << "Component " << component << ": ";
            dfs2(x, rev_l, visited);
            cout << endl;
            component++;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> l(n), rev_l(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        //Directed graph
        l[u].push_back(v);
        rev_l[v].push_back(u);
    }

    SSC(l, rev_l, n);

    return 0;
}