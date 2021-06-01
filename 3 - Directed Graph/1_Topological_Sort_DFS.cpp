#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
private:
    map<T, vector<T>> l;

    void dfs(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node] = true;

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, ordering);
            }
        }
        ordering.push_front(node);
    }

public:
    void addEdge(T u, T v)
    {
        l[u].push_back(v);
    }

    list<T> topological_sort()
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        list<T> ordering;

        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                dfs(node, visited, ordering);
            }
        }

        return ordering;
    }
};

int main()
{
    Graph<string> g;

    g.addEdge("ML Basics", "Deep Learning");
    g.addEdge("Deep Learning", "Face Recognition");
    g.addEdge("Dataset", "Face Recognition");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "Data Preprocessing");
    g.addEdge("Python", "ML Basics");
    g.addEdge("PyTorch", "Deep Learning");

    list<string> ordering = g.topological_sort();

    for (auto x : ordering)
    {
        cout << x << endl;
    }

    return 0;
}