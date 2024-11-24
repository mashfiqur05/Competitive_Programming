#include<bits/stdc++.h>
using namespace std;
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.

int maxSubarrayLength(const vector<int>& a, int s) 
{
    int n = a.size();
    int x = 0, L = 0, res = 0;
    
    for (int R = 0; R < n; ++R) 
    {
        x += a[R];
        while (x > s) 
        {
            x -= a[L];
            ++L;
        }
        res = max(res, R - L + 1);
    }
    
    return res;
}


int32_t main()
{
    Bismillah();

    vector<int> a = {1, 3, 5, 8, 10};
    vector<int> b = {2, 6, 7, 8, 9, 13};
    vector<int> c;

    /// Two pointer method
    int i = 0, j = 0;
    int id = 1;
    while (i < a.size() || j < b.size())
    {
        if (j == b.size() || (i < a.size() && a[i] < b[j]))
        {
            c.push_back (a[i]); /// c[i+j] = a[i];
            i++;
        }
        else 
        {
            c.push_back (b[j]); /// c[i+j] = b[j];
            j++;
            
        }
    }

    for (auto u : c) cout << u << " ";
    cout << endl;

    a = {1, 2, 3, 4, 5}; /// Example input array
    int s = 10; /// Example sum limit
    cout << "Maximum subarray length with sum less than or equal <= " << s << " is " << maxSubarrayLength(a, s) << endl;

    
    return 0;
}