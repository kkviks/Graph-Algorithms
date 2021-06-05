#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<pair<int, int>>> l; // {v,w}
public:
    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int dijkstra(int src, int dest, int n)
    {
        set<pair<int, int>> set;
        vector<int> dist(n, -1);

        set.insert({0, src}); // w, node;
        dist[src] = 0;

        while (!set.empty())
        {
            pair<int, int> front = *set.begin();
            set.erase(set.begin());
            int parent_distance = front.first, parent = front.second;
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

        return dist[dest];
    }
};

void solve()
{
    int n, e;
    cin >> n >> e;

    Graph g;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int A, B;
    cin >> A >> B;

    int distance = g.dijkstra(A, B, n + 1);
    if (distance != -1)
        cout << distance << endl;
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    cout.flush();
    return 0;
}