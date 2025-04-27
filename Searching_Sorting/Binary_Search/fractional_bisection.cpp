///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
x^2 + 5*x = 20
x > 0 Find the value of x
*/

bool isOk (double x)  /// change according to problem
{
    if (x*x + 5*x < 20) return 0;
    return 1;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    double l = 0, r = 10, err = 0.0000000001;
    while (r - l > err)
    {
        double mid = (l + r) / 2;
        if (isOk (mid) == 0) l = mid;
        else r = mid; 
    }

    cout << l << endl;

    return 0;
}

/// x^2 + 6*x = -7. Can you find x using binary search in this equation.
