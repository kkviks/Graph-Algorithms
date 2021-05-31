#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T u, T v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int src)
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            visited[p.first] = false;
        }
        dfs_helper(src, visited);
    }

    void dfs_helper(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (int nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }
};

int main()
{

    Graph<int> g;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.dfs(0);
}