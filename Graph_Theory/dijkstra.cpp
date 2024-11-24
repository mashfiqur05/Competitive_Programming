#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const ll infLL = 9000000000000000000;
const int MX = 1e3+123;


vector<pair<int, int>> adj[MX];
ll dis[MX];
bool vis[MX];

void dijkstra(int source, int n)
{
    for (int i = 0; i <= n; i++) dis[i] = infLL;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    pq.push ({0, source});
    dis[source] = 0;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        ll node = x.second;
        if (vis[node]) continue;
        vis[node] = 1;

        for (auto y : adj[node])
        {
            ll v = y.first;
            ll w = y.second;
            if (dis[node] + w < dis[v])
            {
                dis[v] = dis[node] + w;
                pq.push ({dis[v], v});
            }
        }
    }
}


int32_t main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back ({b, cost});   
        adj[b].push_back ({a, cost});   
    }


    dijkstra (1, n);

    for (int i = 1; i <= n; i++) cout << i << " " << dis[i] << endl;
    
    return 0;
}

/*input: 
5 7 
1 3 3
1 2 2
1 4 6
2 5 6
2 3 7
5 4 3
3 4 5

output :
1 0
2 2
3 3
4 6
5 8

*/