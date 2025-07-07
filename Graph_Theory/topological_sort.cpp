#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, m;
vector<int> adj[N];
int indegree[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topological_order;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topological_order.push_back(u);

        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if (topological_order.size() != n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int node : topological_order)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}