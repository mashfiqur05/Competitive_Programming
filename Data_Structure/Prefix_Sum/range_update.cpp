/*****
You are given an initialized array with size n. You will perform some operations.
In each operation you will given l, r and x. From l to r you have to add x in the array.
At last you have to print the array after performing all operations.
1 <= n <= 1e5, 1 <= q <= 1e5, 1 <= a[i] <= 1e5, 1 <= x <= 1e5
*****/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
 
    int arr[n+2] = {0};
 
    for(int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
 
        arr[i] += v;
        arr[i+1] -= v;
    }
 
    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
 
        arr[l] += x;
        arr[r+1] -= x;
    }
 
    for(int i = 1; i <= n; i++)
    {
        arr[i] += arr[i-1];
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//// https://codeforces.com/contest/276/problem/C