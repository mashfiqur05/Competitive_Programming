#include<bits/stdc++.h>
using namespace std;

/// Upper bound - Maximum index that can insert x in a array and the array  will be sorted.
/// Complexity O(log2(n))

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int up = n;
    int l = 0, r = n-1, mid;
    
    while (l <= r)
    {
        mid = (l + r) / 2;
        
        if (v[mid] > x) 
        {
            up = mid;
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }
    
    /// Number of values less than or equal x = Upper bound;
    /// Number of values strictly greater than x = n - upper bound;

    cout << up << endl;

    return 0;
}