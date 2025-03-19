#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define mxn 1000005

int arr[mxn], temp[mxn];

ll merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    ll inv = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++], inv += mid - i + 1;
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    k = 0;
    for (i = l; i <= r; i++) arr[i] = temp[k++];
    
    return inv;
}

ll msort(int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int mid = (l + r) / 2;
    ll a = msort(l, mid);
    ll b = msort(mid + 1, r);
    ll c = merge(l, mid, r);
    return a + b + c;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll ans = msort(0, n - 1);
    cout << ans << endl;

    return 0;
}