//In the name of ALLAH
#include<bits/stdc++.h>
using namespace std;


const int MX = 123;
bool vis[MX, record[MX]];
vector<int> adj[MX];    /// adjacency list.


/// Checking is there any cycle or not
/// O(V+E).
bool cycleDetection (int vertex, int par = 0)
{
    vis[vertex] = true;
    bool isLoopExists = false;

    for (auto child : adj[vertex])
    {
        if (vis[child] && child == par) continue;
        if (vis[child]) return true;

        isLoopExists |= cycleDetection (child, vertex); // or equal
    }

    return isLoopExists;
}

bool cycleDetectionForDirectedGraph (int vertex, int par = 0)
{   
    if (record[vertex]) return true;
    if (vis[vertex]) return false;

    vis[vertex] = true;
    record[vertex] = true;

    for (auto u : g[vertex])
    {
        if (cycleDetectionForDirectedGraph (u, vertex)) return true;
    }

    record[vertex] = false;

    return false;
}



int32_t main ()
{
    adj[1].push_back (2);
    adj[2].push_back (1);

    adj[2].push_back (3);
    adj[3].push_back (2);

    adj[3].push_back (4);
    adj[4].push_back (3);

    bool flag = cycleDetection (1, 0);
    
    cout << flag << endl;


    return 0;
}