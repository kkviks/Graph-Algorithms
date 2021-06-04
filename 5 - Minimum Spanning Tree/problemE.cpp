//https://codeforces.com/gym/102220/problem/E

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

struct DSU
{
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.reserve(n), rank.reserve(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int a, int b)
    {
        int s1 = find(a);
        int s2 = find(b);

        if (s1 != s2)
        {
            if (rank[s2] > rank[s1])
                swap(s1, s2);
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
};

bool comp(const tuple<int, int, int> a, const tuple<int, int, int> b)
{
    return get<2>(a) < get<2>(b);
}

void kruksal()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v(n - 1);

    for (auto &t : v)
    {
        int u, v, w;
        cin >> u >> v >> w;
        t = make_tuple(u, v, w);
    }
    sort(all(v), comp);

    DSU g(n + 1);

    int sum = 0;

    for (auto t : v)
    {
        int u, v, w;
        tie(u, v, w) = t;

        if (g.find(u) != g.find(v))
        {
            sum += w;
            g.unite(u, v);
        }
    }

    cout << sum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        kruksal();
    }

    cout.flush();
    return 0;
}