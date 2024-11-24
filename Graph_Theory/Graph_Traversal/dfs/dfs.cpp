#include<bits/stdc++.h>
using namespace std;

const int MX = 123;
bool vis[MX];
vector<int> adj[MX];    /// adjacency list.

/// Complexity O(V+E) where V = Number of vertex and E = Number of edges.

void dfs (int vertex)
{
    /// Take actions on vertex after entering a vertex
    cout << "Vertex: " << vertex << endl;
    vis[vertex] = 1;

    for (auto child : adj[vertex])
    { 
        cout << "Parent: " << vertex << " Child: " << child << endl;
        if (vis[child]) continue;
    /// Take actions on child before entering the child node 
        dfs (child);    
    /// Take actions on child after exiting the child node 
    }
    // Take actions on vertex before exiting the vertex
}


int32_t main()
{

    adj[1].push_back (2);
    adj[2].push_back (1);

    adj[2].push_back (3);
    adj[3].push_back (2);

    adj[3].push_back (4);
    adj[4].push_back (3);

    dfs (1);
    /*Output
Vertex: 1
Parent: 1 Child: 2
Vertex: 2
Parent: 2 Child: 1
Parent: 2 Child: 3
Vertex: 3
Parent: 3 Child: 2
Parent: 3 Child: 4
Vertex: 4
Parent: 4 Child: 3
*/
    
    return 0;
}