#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T u, T v)
    {
        //Assuming bidir
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src]=true;

        while (!q.empty())
        {
            T front = q.front();
            q.pop();

            foo(front);

            for (T nbr : l[front])
            {
                if (visited.count(nbr) == 0)
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void foo(T node)
    {
        //Do something with node;
        cout << node << " "; 
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

    return 0;
}