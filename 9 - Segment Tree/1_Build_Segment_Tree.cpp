#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> tree;
    int capacity, size;
    const int SENTINAL = INT_MAX;

    int logic(int a, int b)
    {
        return min(a, b);
    }

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

    void buildTree(vector<int> const &a)
    {
        buildTree(a, 0, a.size() - 1, 1);
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

        tree[idx] = logic(tree[2 * idx], tree[2 * idx + 1]);
    }


    int query(int qs, int qe)
    {
        return query(0, size - 1, qs, qe, 1);
    }

    int query(int ss, int se, int qs, int qe, int idx)
    {
        //Complete overlap
        if (ss >= qs and se <= qe)
            return tree[idx];

        //No overlap
        if (ss > qe or qs > se)
            return SENTINAL;

        //Partial Overlap
        int mid = ss + (se - ss) / 2;
        int left = query(ss, mid, qs, qe, 2 * idx);
        int right = query(mid + 1, se, qs, qe, 2 * idx + 1);

        return logic(left, right);
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
    segmentTree.buildTree(a);
    //segmentTree.printTree();

    cout << segmentTree.query(0,2);
}