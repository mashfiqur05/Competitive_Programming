///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


void IS_BRIDGE(int v, int neighbour)
{
    cout << "Bridge between nodes: " << v << " and " << neighbour << endl;
}

int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int neighbour : adj[v])
    {
        if (neighbour == p && !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[neighbour])
        {
            low[v] = min(low[v], tin[neighbour]);
        }
        else
        {

            dfs(neighbour, v);
            low[v] = min(low[v], low[neighbour]);
            if (low[neighbour] > tin[v])
                IS_BRIDGE(v, neighbour);
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int m; // number of edges
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_bridges();

    for (int i = 0; i < n; i++)
    {
        cout << low[i] << " " << tin[i] << endl;
    }
    cout << timer << endl;
    return 0;
}

/* input 
5 5
0 1
0 2
1 2
1 3
3 4

output
Bridge between nodes: 3 and 4
Bridge between nodes: 1 and 3
0 0
0 1
0 2
3 3
4 4
5
*/