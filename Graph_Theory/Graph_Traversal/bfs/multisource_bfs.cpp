/*Suppose there are n towns connected by m bidirectional roads. 
There are s towns among them with a police station. 
We want to find out the distance of each town from the nearest police station. 
If the town itself has one the distance is 0.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MX = 1e5+123;
vector<int> g[MX];
vector<int> sources (MX);
bool vis[MX];
int level[MX];
int node, edges, s;

/*
Time Complexity: O(V+E)
Auxiliary Space: O(V) 
*/
void bfs()
{
    queue<int> q;
    for (int i = 0; i < s; i++)
    {
        q.push (sources[i]);
        vis[sources[i]] = 1;
    }

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        for (auto child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push (child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}


int32_t main()
{
    cin >> node >> edges;

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }

    cin >> s;
    for (int i = 0; i < s; i++) cin >> sources[i];

    bfs();

    for (int i = 1; i <= node; i++)
    {
        cout << i << " " << level[i] << endl;
    }

    return 0;
}

/*
input
Number of Vertices = 6
Number of Edges = 9
Edges:
1 2
1 6
2 6
2 3
3 6
5 4
6 5
3 4
5 3
Number of sources : 2
Towns with Police Station : 1, 5

output:
1 0
2 1
3 1
4 1
5 0
6 1

*/