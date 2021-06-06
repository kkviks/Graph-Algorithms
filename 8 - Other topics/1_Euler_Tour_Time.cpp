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

    void euler_tour_1(int node, int parent)
    {
        //Timing not as useful so lite
        cout << node << " ";
        for (auto nbr : l[node])
        {
            if (nbr != parent)
            {
                euler_tour_1(nbr, node);
                cout << node << "";
            }
        }
    }

    void euler_tour_2(int node, int parent, int &timer)
    {
        //cout << node << " ";

        time_in[node] = timer++;

        for (auto nbr : l[node])
        {
            if (nbr != parent)
            {
                euler_tour_2(nbr, node, timer);
            }
        }
        time_out[node] = timer++;
        //cout << node << " ";
    }

    void euler_tour_3(int node, int parent, int &timer)
    {
        //cout << node << " ";

        time_in[node] = ++timer;

        for (auto nbr : l[node])
        {
            if (nbr != parent)
            {
                euler_tour_3(nbr, node, timer);
            }
        }

        time_out[node] = timer;
    }

    void printTime()
    {
        int n = l.capacity();
        cout << "Node, Time-in,Time-out" << endl;
        for (int i = 1; i < n; i++)
        {
            cout << "Node " << i << ": " << time_in[i] << " " << time_out[i] << endl;
        }
        cout << endl;
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

    int timer = 0;

    cout << "Euler Tour 2:\n";
    g.euler_tour_2(1, -1, timer = 1);
    g.printTime();

    cout << "Euler Tour 3:\n";
    g.euler_tour_3(1, -1, timer = 0);
    g.printTime();

    return 0;
}