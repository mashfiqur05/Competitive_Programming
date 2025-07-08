///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<pair<int, int>> g[100100];
int dis[100100];
int n, m;

void bfs01(int src)
{
    deque<int> dq;
    for (int i = 1; i <= n; i++) dis[i] = 1e9;

    dis[src] = 0;
    dq.push_back (src);

    while (!dq.empty())
    {
        int cur = dq.front();   
        dq.pop_front();

        for (auto v : g[cur])
        {
            int neigh = v.first, weight = v.second;
            if (dis[neigh] > dis[cur] + weight)
            {
                dis[neigh] = dis[cur] + weight;
                
                if (weight == 0) dq.push_front (neigh);
                else dq.push_back (neigh);
            }
        }
    }
}


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c; /// weight is only 0 or 1
        cin >> a >> b >> c;
        g[a].push_back ({b, c});
        g[b].push_back ({a, c});
    }

    int source; cin >> source;

    bfs01(source);

    for (int i = 1; i <= n i++) cout << i << "--> " << dis[i] << endl;

    return 0;
}
