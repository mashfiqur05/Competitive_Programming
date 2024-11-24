#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

/*Given queries q, q <= 10^5
In each query given v.
Print subtree sum of V and number of even numbers in subtree v.
*/

const int MX = 1e5+123;
vector<int> adj[MX];
int subtree_sum[MX];
int even_cnt[MX];


void dfs (int vertex, int parent=0)
{

    if (vertex % 2 == 0) even_cnt[vertex]++;
    for (auto child : adj[vertex])
    {
        if (child == parent) continue;
        dfs (child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_cnt[vertex] += even_cnt[child];
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
    for (int i = 1; i <= n; i++) subtree_sum[i] = i;

    dfs (1, 0);
    /*  
    int q;
    cin >> q;
    while (q--)
    {
        int v;
        cin >> v;
        cout << subtree_sum[v] << " " << even_cnt[v] << endl;
    }
    */
    for (int i = 1; i <= n; i++) cout << i << " " << subtree_sum[i] << " " << even_cnt[i] << endl;

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

output:
1 91 6
2 40 4
3 37 2
4 34 2
5 38 3
6 6 1
7 7 0
8 20 2
9 9 0
10 21 1
11 11 0
12 12 1
13 13 0

*/