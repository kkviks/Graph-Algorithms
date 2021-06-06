#include <bits/stdc++.h>
using namespace std;

//Euler tour of a tree

class Graph
{
    vector<vector<int>> l;

public:
    Graph(int n)
    {
        l.reserve(n);
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void euler_tour_1(int node, int parent)
    {
        cout << node << " ";
        for (auto nbr : l[node])
        {
            if (nbr != parent)
            {
                euler_tour_1(nbr, node);
                cout << node << " ";
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Graph g(n + 1);

    int e = n - 1; //becasue tree

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.euler_tour_1(1, -1);
    
}