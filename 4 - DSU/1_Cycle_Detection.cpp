#include <bits/stdc++.h>
using namespace std;

class Graph
{

    list<pair<int, int>> l; // Edge list representation
    int n;

public:
    Graph(int n)
    {
        this->n = n;
    }

    void addEdge(int u, int v)
    {
        l.push_back({u, v});
    }

    bool contain_cycle()
    {
        vector<int> parent(n + 1, -1);

        for (auto p : l)
        {
            int a = p.first;
            int b = p.second;

            int s1 = findSet(a, parent);
            int s2 = findSet(b, parent);

            if (s1 == s2)
            {
                return true;
            }
            else
            {
                unionSet(a, b, parent);
            }
        }
        return false;
    }

private:
    int findSet(int i, vector<int> &parent) const
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return findSet(parent[i], parent);
    }

    void unionSet(int a, int b, vector<int> &parent)
    {
        int s1 = findSet(a, parent);
        int s2 = findSet(b, parent);

        if (s1 == s2)
            return;

        parent[s2] = s1;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph g(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    bool hasCycle = g.contain_cycle();

    string ans = hasCycle ? "Cycle exists" : "No cycle";
    cout << ans;

    return 0;
}