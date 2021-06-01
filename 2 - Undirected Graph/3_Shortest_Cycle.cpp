#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> &l, int n, int &ans)
{
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nbr : l[node])
        {
            if (dist[nbr] == INT_MAX)
            {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
            else if (dist[nbr] >= dist[node])
            {
                ans = min(ans, dist[nbr] + dist[node] + 1);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> l(n);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        l[u].push_back(v);
        l[v].push_back(u);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        bfs(i, l, n, ans);
    }

    if (ans == INT_MAX)
    {
        ans = 0;
    }

    cout << "Min cycle len = " << ans;
    return 0;
}