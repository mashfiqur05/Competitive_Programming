#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+123;
vector<int> parent(N);
vector<int> size(N);

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) //// Path compression optimization O(log(n)).
{
    if (v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) ///  Union by size / rank.
{

    if (size[a] < size[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}

int32_t main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 1; i <= node; i++)
    {
        make_set(i);
    }

    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;

        int u = find_set(a);
        int v = find_set(b);

        if (u != v)
        {
            union_sets(u, v);
        }
    }

    int ans = 0;
    for (int i = 1; i <= node; i++)
    {
        if (parent[i] == i)
            ans++;
    }

    cout << ans << endl;

    return 0;
}

/*10 10
1 2
1 3
4 5
8 9
5 6
2 3
3 5
4 7
3 4
9 10

output : 2
*/