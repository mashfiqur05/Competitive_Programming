#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n+1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    int ans = -1;
    int x; cin >> x;

    int l = 1, r = n;
    
    /// Complexity O(log2(n))
    while (l <= r)
    {
        int mid = l + (r - l) / 2;  

        if (v[mid] == x)
        {
            ans = mid;
            break;
        }

        if (v[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }


    cout << ans << endl;
    
    return 0;
}