///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<bool> visited;           // Tracks visited vertices
vector<int> order;              // Stores vertices in exit time order
vector<int> roots;              // Root vertex of each SCC
vector<vector<int>> adj;        // Adjacency list of G
vector<vector<int>> adj_rev;    // Adjacency list of G^T
vector<vector<int>> components; // List of SCCs
vector<vector<int>> adj_cond;   // Condensation graph

// First DFS: Processes vertices in exit time order
void dfs1(int v)
{
    visited[v] = true;
    for (auto u : adj[v])
    {
        if (!visited[u])
        {
            dfs1(u);
        }
    }
    order.push_back(v); // Append vertex after all descendants are processed
}

// Second DFS: Collects vertices in a single SCC
void dfs2(int v, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v); // Add vertex to the current SCC
    for (auto u : adj_rev[v])
    {
        if (!visited[u])
        {
            dfs2(u, component);
        }
    }
}

// Function to find SCCs using Kosaraju's Algorithm
void strongly_connected_components(int n)
{
    // First DFS on the original graph to get exit times
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }

    // Second DFS on G^T to find SCCs
    visited.assign(n, false);
    reverse(order.begin(), order.end()); // Process vertices by decreasing exit time
    roots.assign(n, 0);
    components.clear();

    for (auto v : order)
    {
        if (!visited[v])
        {
            vector<int> component;
            dfs2(v, component);
            components.push_back(component);

            // Identify the root vertex of this SCC
            int root = *min_element(component.begin(), component.end());
            for (auto u : component)
            {
                roots[u] = root;
            }
        }
    }

    // Build condensation graph (G^SCC)
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
    {
        for (auto u : adj[v])
        {
            if (roots[v] != roots[u])
            {
                adj_cond[roots[v]].push_back(roots[u]);
            }
        }
    }

    // Remove duplicate edges in the condensation graph
    for (auto &neighbors : adj_cond)
    {
        sort(neighbors.begin(), neighbors.end());
        neighbors.erase(unique(neighbors.begin(), neighbors.end()), neighbors.end());
    }
}

// Main Function with Input/Output
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    // Input adjacency list
    adj.assign(n, {});
    adj_rev.assign(n, {}); // Initialize the reverse graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // Directed edge u -> v
        adj[u].push_back(v);
        adj_rev[v].push_back(u); // Reverse the graph
    }

    // Find SCCs
    strongly_connected_components(n);

    // Output the SCCs
    cout << "\nStrongly Connected Components:\n";
    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";
        for (auto v : components[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }

    // Output the Condensation Graph
    cout << "\nCondensation Graph (edges):\n";
    for (int v = 0; v < adj_cond.size(); v++)
    {
        for (auto u : adj_cond[v])
        {
            cout << v << " -> " << u << endl;
        }
    }

    return 0;
}

/*input:
7 9
0 1
1 2
2 0
1 3
3 4
4 3
4 5
5 6
6 5

output:
Strongly Connected Components:
Component 1: 0 2 1 
Component 2: 3 4 
Component 3: 5 6 

Condensation Graph (edges):
0 -> 3
3 -> 5
*/