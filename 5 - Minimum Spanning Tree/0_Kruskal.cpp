#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> g;

class DSU
{
    vector<int> parent, rank;

public:
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
            {
                swap(s1, s2);
            }
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
};

int kruksal(int n)
{

    sort(g.begin(), g.end(), [&](auto t1, auto t2)
         { return get<2>(t1) <= get<2>(t2); });

    int u, v, w;
    long long int sum = 0;
    DSU s(n + 1);

    for (tuple<int, int, int> const &t : g)
    {
        tie(u, v, w) = t;
        if (s.find(u) != s.find(v))
        {
            //cout << u << " " << v << " " << endl;
            s.unite(u, v);
            sum += w;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n,e;
    cin >> n >> e;

    int u, v, w;

    while (cin >> u >> v >> w)
    {
        g.push_back(make_tuple(u, v, w));
    }

    int wt_sum = kruksal(n+1);
    cout << wt_sum;
}