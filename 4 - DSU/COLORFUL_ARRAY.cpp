//Problem Link: https://www.spoj.com/problems/CLFLARR/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;

int findSet(int i, vector<int> &parent)
{
    if (parent[i] == i)
    {
        return i;
    }

    return parent[i] = findSet(parent[i], parent);
}

void unionSet(int a, int b, vector<int> &parent)
{
    int s1 = findSet(a, parent);
    int s2 = findSet(b, parent);

    if (s1 != s2)
    {
        int mx = max(parent[s1], parent[s2]);
        parent[s1] = parent[s2] = mx;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    int l[q], r[q], c[q];

    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i] >> c[i];
    }

    vector<int> parent(n + 2);
    iota(all(parent), 0);
    int ans[n + 2] = {0};

    for (int i = q - 1; i >= 0; i--)
    {
        int idx = findSet(l[i], parent);
        while (idx <= r[i])
        {
            ans[idx] = c[i];
            unionSet(idx, idx + 1, parent);
            idx = findSet(idx, parent);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    cout.flush();
    return 0;
}