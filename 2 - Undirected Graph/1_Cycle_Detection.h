#include <vector>
using namespace std;

int V;
vector<vector<int>> l(V);

bool cycle_helper(int node, vector<bool> &visited, int parent)
{
    visited[node] = true;

    for (auto nbr : l[node])
    {
        if (!visited[nbr])
        {
            bool hasCycle = cycle_helper(nbr, visited, node);
            if (hasCycle)
            {
                return true;
            }
            else if (visited[nbr] and nbr != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool contains_cycle()
{
    vector<bool> visited(V, false);
    int src = 0;
    int parent = -1;
    return cycle_helper(src, visited, parent);
}