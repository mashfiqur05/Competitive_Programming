#include <bits/stdc++.h>
using namespace std;

int parent[123];
int sz[123];

int findParent(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void make_union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}

int32_t main()
{

    int n, ed;
    cin >> n >> ed;
    vector<pair<int, pair<int, int>>> edge;

    for (int i = 0; i < ed; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, {u, v}});
    }

    int mnST = 0, cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    sort(all(edge));

    for (auto e : edge)
    {
        int u = e.second.first;
        int v = e.second.second;
        int w = e.first;

        u = findParent(u);
        v = findParent(v);

        if (u != v)
        {
            cnt++;
            mnST += w;
            make_union(u, v);
        }
        if (cnt == n - 1)
            break;
    }

    cout << mnST << endl;

    return 0;
}
