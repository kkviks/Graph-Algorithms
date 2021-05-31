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

    void dfs(T src, map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited);
            }
        }
    }

    int getConnectedComps()
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            visited[p.first] = false;
        }

        int count = 0;
        for (auto p : l)
        {
            int node = p.first;
            if (!visited[node])
            {
                cout << "Component #" << count << " ---> ";
                dfs(node, visited);
                count++;
                cout << endl;
            }
        }
        return count;
    }
};

int main()
{
    Graph<int> g;

    int u, v;
    while (cin >> u >> v)
    {
        g.addEdge(u, v);
    }
    int components = g.getConnectedComps();
    cout << "Total connect components: " << components;
    return 0;
}