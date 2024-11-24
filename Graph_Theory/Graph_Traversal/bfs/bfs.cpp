#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+123;
vector<int> g[N];
int vis[N], parent[N];
int level[N];


void bfs (int source)   /// Complexity : O(V+e) where v = total node and e = total edge.
{
    queue<int> q;
    q.push (source);
    vis[source] = 1;
    parent[source] = -1;

    while (!q.empty())
    {
        int cur_vartex = q.front();
        q.pop();

        for (auto child : g[cur_vartex])
        {
            if (!vis[child])
            {
                q.push (child);
                vis[child] = 1;
                level[child] = level[cur_vartex] + 1;
                parent[child] = cur_vartex;
            }
        }
    }
}


/// If we have to restore and display the shortest path from the source to some vertex u
void path_printing(int u)
{
    if (!vis[u]) 
        cout << "No Path" << endl;
    else 
    {
        vector<int> path;
        for (int i = u; i != -1; i = parent[i])
        {
            path.push_back (i);
        }

        reverse (path.begin(), path.end());
        for (int v : path)
        cout << v << " ";
    }
}


int32_t main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }
    
    bfs (1);
    /// bfs is used to determine shortest path.

    return 0;
}