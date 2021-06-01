#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, vector<T>> l;

public:
    void addEdge(T u, T v)
    {
        //Direct Graph
        l[u].push_back(v);
    }

    list<T> topological_sort()
    {
        map<T, int> indeg;

        for (auto p : l)
        {
            T node = p.first;
            indeg[node] = 0;
        }

        for (auto p : l)
        {
            T node = p.first;
            for (auto nbr : l[node])
            {
                indeg[nbr]++;
            }
        }

        queue<T> q;

        for (auto p : indeg)
        {
            T node = p.first;
            if (indeg[node] == 0)
            {
                q.push(node);
            }
        }

        list<T> ordering;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            ordering.push_back(node);

            for (auto nbr : l[node])
            {
                indeg[nbr]--;
                if (indeg[nbr] == 0)
                {
                    q.push(nbr);
                }
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