///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, scc;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> comp;

void dfs(int v)
{
    stack<int> st;
    st.push(v);

    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!vis[curr])
        {
            vis[curr] = true;
            comp.push_back(curr);
            for (int i = adj[curr].size() - 1; i >= 0; i--)
            {
                st.push(adj[curr][i]);
            }
        }
    }
}

void find_comps()
{
    fill(vis.begin(), vis.end(), false);
    for (int v = 1; v <= n; ++v)
    {
        if (!vis[v])
        {
            scc++;
            comp.clear();
            dfs(v);
            cout << "Component " << scc << ":";
            for (int u : comp)
                cout << ' ' << u;
            cout << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n >> m;

    adj.resize(n + 1); // Initialize adjacency list
    vis.resize(n + 1, false); // Initialize visited vector

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_comps();

    return 0;
}

/*
input 
12 9
1 2
2 3
3 4
4 5
4 1
6 7
7 9
8 9
11 12

output :
Component 1: 1 2 3 4 5
Component 2: 6 7 9 8
Component 3: 10
Component 4: 11 12
*/