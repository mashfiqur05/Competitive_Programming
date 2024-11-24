#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MX = 1e5+123;
vector<int> adj[MX];
int parent[MX];


void dfs (int vertex, int p = -1)
{
    parent[vertex] = p;

    for (auto child : adj[vertex])
    {
        if (child == p) continue;
        dfs (child, vertex);
    }
}

/// return the path of a vertex
vector<int> path (int vertex)
{
    vector<int> ret;

    while (vertex != -1)
    {
        ret.push_back (vertex);
        vertex = parent[vertex];
    }

    return ret;
}


int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs (1);

    int x, y;
    cin >> x >> y;

    vector<int> path_x = path (x);
    vector<int> path_y = path (y);

    int mn_len = min (path_x.size(), path_y.size());

    int lca = -1;
    for (int i = 0; i < mn_len; i++)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
            break;
        }
    }

    cout << lca << endl;
 
    return 0;
}

/*
input
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

6 7

output: 5
*/