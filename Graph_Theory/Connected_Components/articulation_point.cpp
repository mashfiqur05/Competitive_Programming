///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;                // number of vertices and edges
vector<vector<int>> adj; // adjacency list of the graph
vector<bool> visited;
vector<int> tin, low;
set<int> articulation_points;
int timer;

void IS_CUTPOINT(int v)
{
    articulation_points.insert(v); // Mark the vertex as an articulation point
}

void dfs(int v, int parent = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;

    for (int to : adj[v])
    {
        if (to == parent)
            continue; // Ignore edge to parent
        if (visited[to])
        {
            // Update low[v] for a back edge
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            // Recursive DFS call
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && parent != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }

    if (parent == -1 && children > 1)
        IS_CUTPOINT(v); // Root vertex case
}

void find_cutpoints()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    articulation_points.clear();

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cutpoints();

    cout << "Articulation points are:\n";
    for (int point : articulation_points)
    {
        cout << point << " ";
    }
    if (articulation_points.empty())
        cout << "None";

    return 0;
}

/* input 
9 11
0 1
0 2
1 2
1 3
3 4
4 5
5 6
6 4
5 7
7 8
 
output:
Articulation points are:
1 3 4 5 7 
*/