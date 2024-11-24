#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MX = 1e5+123;
vector<int> adj[MX];
int height[MX];
int depth[MX];


void dfs (int vertex, int parent)
{
    for (auto child : adj[vertex])
    {
        if (child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs (child, vertex);
        height[vertex] = max (height[vertex], height[child] + 1);
    }
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
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ' << depth[i] << ' ' << height[i] << endl;
    }

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

output 
1 0 4
2 1 3
3 1 3
4 2 2
5 2 2
6 3 0
7 3 0
8 3 1
9 3 0
10 3 1
11 4 0
12 4 0
13 1 0


*/