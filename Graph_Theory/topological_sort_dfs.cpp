#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, m;
vector<int> adj[N];
int visited[N]; // 0 = unvisited, 1 = visiting, 2 = visited
vector<int> topological_order;
bool has_cycle = false;

void dfs(int u)
{
    visited[u] = 1; // mark as visiting

    for (int v : adj[u])
    {
        if (visited[v] == 0)
        {
            dfs(v);
            if (has_cycle)
                return;
        }
        else if (visited[v] == 1)
        {
            // Found a back edge → cycle exists
            has_cycle = true;
            return;
        }
    }

    visited[u] = 2; // mark as fully processed
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
            if (has_cycle)
                return;
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

    if (has_cycle)
        cout << "The graph has a cycle.\n";
    else
    {
        cout << "Topological Order:\n";
        for (int node : topological_order)
            cout << node << " ";
        cout << '\n';
    }

    return 0;
}
