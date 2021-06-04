#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<pair<int, int>> *l;
    int n;

public:
    Graph(int n)
    {
        l = new vector<pair<int, int>>[n];
        this->n = n;
    }

    void addEdge(int u, int v, int w)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    int prim()
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //minheap
        vector<bool> visited(n, false);

        int ans = 0;

        pair<int, int> hypothetical_node = {0, 1}; // {0,0} if 0-indexed
        pq.push(hypothetical_node);

        while (!pq.empty())
        {
            auto best = pq.top();
            pq.pop();

            int best_w = best.first;
            int to = best.second;

            if (visited[to])
                continue;

            ans += best_w;
            visited[to] = true;

            for (auto nbr : l[to])
            {
                if (!visited[nbr.first])
                {
                    pq.push({nbr.second, nbr.first});
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph g(n + 1);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int cost = g.prim();
    cout << cost;

    return 0;
}