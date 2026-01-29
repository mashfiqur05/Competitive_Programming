///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

/*
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4
*/

void solve (int CaseNo)
{
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else 
            {
                dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // cout << dp[n][m] << endl;

    /// Lcs retrieval
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1]) 
        {
            lcs.push_back (a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse (all (lcs));
    cout << lcs.size() << endl;
    for (auto u : lcs) cout << u << " "; cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}