///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int inf = 2000000000;

int node, start, destination, edge;
vector<vector<int>> capacity;
vector<vector<int>> g;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, inf});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : g[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(node+1); // For backtrack
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)    /// Backtracking
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    cin >> node >> start >> destination >> edge;
    
    capacity.assign(node+1, vector<int>(node+1, 0));
    g.assign(node+1, vector<int>());
    
    for (int i = 0; i < edge; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;

        capacity[u][v] += cost;  
        capacity[v][u] += cost;

        g[u].push_back(v);
        g[v].push_back(u); 
    }

    cout << maxflow(start, destination) << endl;

    return 0;
}


/*Input
4 1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
*/