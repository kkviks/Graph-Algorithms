#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<pair<int, int>>> l; // {v,w}
    int *dist;
    int n;

public:
    Graph(int n)
    {
        this->n = n;
        dist = new int[n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = -1;
        }
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void dijkstra(int src)
    {
        set<pair<int, int>> set;
        set.insert({0, src});
        dist[src] = 0;

        while (!set.empty())
        {
            auto front = *set.begin();
            int parent = front.second;
            set.erase(set.begin());

            for (auto p : l[parent])
            {
                int nbr = p.first, w = p.second;
                if (dist[parent] + w < dist[nbr] or dist[nbr] == -1)
                {
                    set.erase({dist[nbr], nbr});
                    dist[nbr] = dist[parent] + w;
                    set.insert({dist[parent] + w, nbr});
                }
            }
        }
    }

    void print_distances()
    {
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, e;
    cin >> n >> e;

    Graph g(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.dijkstra(1);
    g.print_distances();

    cout.flush();
    return 0;
}