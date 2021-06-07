#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<vector<int>> l;
    vector<int> time_in, time_out;

public:
    Graph(int n)
    {
        l.reserve(n);
        for (int i = 0; i < n; i++)
        {
            time_in.push_back(-1);
            time_out.push_back(-1);
        }
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void euler_tour(int node, int parent, int &timer)
    {
        time_in[node] = ++timer;
        for (auto nbr : l[node])
        {
            if (nbr != parent)
            {
                euler_tour(nbr, node, timer);
            }
        }
        time_out[node] = timer;
    }

    bool isAncestor(int parent, int child)
    {
        int timer = 0;
        euler_tour(1, -1, timer = 0);
        return time_in[parent] <= time_in[child] and time_out[parent] >= time_out[child];
    }
};

int main()
{
    int n;
    cin >> n;

    Graph g(n + 1);

    int e = n - 1; // because tree
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int parent = 1, child = 5;

    if (g.isAncestor(parent, child))
        cout << "Yes, it is ancestor";
    else
        cout << "Nope, no luck, it's not!";

    return 0;
}