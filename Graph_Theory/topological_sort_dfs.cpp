#include <bits/stdc++.h>

using namespace std;

#define N 200005

int n, m;
vector<int> adj[N];
int visited[N];
vector<int> topological_order;

void dfs(int u)
{
    visited[u] = 1;

    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }

    topological_order.push_back(u);
}

void topological_sort()
{
    topological_order.clear();
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }

    reverse(topological_order.begin(), topological_order.end());
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    topological_sort();

    int ans[n + 2];
    for (int i = 1; i <= n; i++)
    {
        ans[i] = INT_MIN;
    }

    ans[n] = 1;

    int nxt[n + 2];

    for (int i = n - 1; i >= 0; i--)
    {
        int u = topological_order[i];

        if (u == n)
        {
            continue;
        }

        int mx = INT_MIN;
        int mx_node = 0;

        for (int v : adj[u])
        {
            if (ans[v] > mx)
            {
                mx = ans[v];
                mx_node = v;
            }
        }

        ans[u] = mx + 1;
        nxt[u] = mx_node;
    }

    if (ans[1] < 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << ans[1] << endl;
    int node = 1;
    while (node != n)
    {
        cout << node << " ";
        node = nxt[node];
    }
    cout << n << endl;

    return 0;
}