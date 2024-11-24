
int depth[MX];

void dfs (int vertex, int parent=0)
{
    for (auto child : adj[vertex])
    {
        if (child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs (child, vertex);
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

    dfs (1);
    int mx_depth = -1, node;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
            node = i;
        }
    }

    memset (depth, 0, sizeof(depth));
    dfs (node);
    mx_depth = -1;

    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > mx_depth)
        {
            mx_depth = depth[i];
        }
    }

    cout << mx_depth << endl;

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
8
*/