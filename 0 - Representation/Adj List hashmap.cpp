#include <bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string u, string v, bool bidir, int wt)
    {
        l[u].push_back({v, wt});
        if (bidir)
            l[v].push_back({u, wt});
    }

    void printGraph()
    {
        for (auto p : l)
        {
            string key = p.first;
            cout << key << " : ";
            for (auto pp : p.second)
            {
                string dest = pp.first;
                int wt = pp.second;
                cout << "(" << dest << "," << wt << "), ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Graph g;
    g.addEdge("A", "B", true, 10);
    g.addEdge("A", "C", false, 20);

    g.printGraph();

    return 0;
}