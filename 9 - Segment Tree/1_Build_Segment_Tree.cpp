#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int capacity, size;

public:
    SegmentTree(int n)
    {
        size = n;
        capacity = 4 * n + 1;
        tree.reserve(capacity);

        for (int i = 0; i < capacity; i++)
        {
            tree.push_back(INT_MIN);
        }
    }

    void buildTree(vector<int> const &a, int s, int e, int idx)
    {
        if (s == e)
        {
            tree[idx] = a[s];
            return;
        }

        int mid = s + (e - s) / 2;
        buildTree(a, s, mid, 2 * idx);
        buildTree(a, mid + 1, e, 2 * idx + 1);

        tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
    }

    void printTree()
    {
        for (int x : tree)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    vector<int> a({1, 3, 2, -5, 6, 4});
    int n = a.size();

    SegmentTree segmentTree(n);
    segmentTree.buildTree(a, 0, n - 1, 1);
    segmentTree.printTree();
}