#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;

vector<vector<int>> l;

bool dfs_helper(int node, int n, int parent, vector<bool> &visited)
{
    visited[node] = true;

    for (auto nbr : l[node])
    {
        if (!visited[nbr])
        {
            bool cycle = dfs_helper(nbr, n, node, visited);
            if (cycle)
                return true;
        }
        else if (visited[nbr] and nbr != parent)
        {
            return true;
        }
    }
    return false;
}

bool dfs(int n)
{
    vector<bool> visited(n + 1);
    bool cycle = dfs_helper(0, n, -1, visited);
    if (cycle == true)
        return false;
    return count(begin(visited), end(visited), true) == n;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, e;
    cin >> n >> e;

    l.reserve(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool tree = dfs(n);

    cout << (tree ? "YES" : "NO");

    cout.flush();
    return 0;
}