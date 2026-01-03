///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    /*Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
     */

    int n, sum;
    cin >> n >> sum;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    const int inf = 1e9;
    vector<int> dp(sum + 1, inf), parent(sum + 1, -1);

    dp[0] = 0;

    for (int k = 1; k <= sum; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= k && dp[k - v[i]] + 1 < dp[k])
            {
                dp[k] = dp[k - v[i]] + 1;
                parent[k] = v[i]; // last used coin
                // parent[k] = k - v[i]; // store the next optimal option.
            }
        }
    }

    if (dp[sum] == inf)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << dp[sum] << endl;

    cout << "Coin used: ";
    // int cur = sum;
    // while (cur != 0)
    // {
    //     int nxt = parent[cur];
    //     int val = cur - nxt;
    //     cout << val << " ";
    //     cur = nxt;
    // }
    int cur = sum;
    while (cur != 0)
    {
        int val = parent[cur];
        cout << val << " ";
        cur -= val;
    }

    return 0;
}
