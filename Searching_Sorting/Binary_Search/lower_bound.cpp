#include<bits/stdc++.h>
using namespace std;

/// Lower bound- minimum index that can be insert x in a array and the array will be sorted.
/// Complexity O(log2(n))

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int lo = n; 
    int l = 0, r = n-1, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v[mid] >= x) ~
        {
            lo = mid;
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }
    
    /// Number of values less than x = lower bound;
    /// Number of values greater or equal to x = n - lower bound;
    cout << lo << endl;

    return 0;
}