///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MX 200005

int n, m;
vector<int> g[MX];
int vis[MX], colour[MX];
bool isPossible = true;

void dfs (int vertex, int c)
{
    if (vis[vertex])
    {
        if (colour[vertex] == c) return;
        else 
        {
            isPossible = false;
            return;
        }

        vis[vertex] = 1;
        colovertexr[vertex] = c;

        for (auto u : g[vertex])
        {
            dfs (u, (c == 1 ? 2 : 1));
        }
    }
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);covertext.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i]) dfs (i, 1);
        }

        if (isPossible) 
        {
            for (int i = 1; i <= n; i++) cout << i << " -> " << colour[i] << endl;
        }
        else cout << "Bi-colouring Impossible" << endl;
    }

    return 0;
}
