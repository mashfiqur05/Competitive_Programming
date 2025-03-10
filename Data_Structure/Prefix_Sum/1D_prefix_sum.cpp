///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int prefix_sum[n+1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + arr[i-1];

    for (int i = 1; i <= n; i++) cout << prefix_sum[i] << " "; cout << endl;

    return 0;
}
