///---  In the name of ALLAH    ---///

#include <bits/stdc++.h>
using namespace std;

int arr[] = {0, 0, 0, 0, 1, 1, 1, 1};

bool isOk(int ind) /// Change
{
    if (arr[ind] == 0) return 1;
    else return 0;
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = sizeof(arr) / sizeof(arr[0]); 
    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (isOk(mid)) l = mid + 1;
        else r = mid - 1;
    }

    int ans0 = l - 1; 
    int ans1 = l;     

    cout << ans0 << " " << ans1 << endl;    //// Change 

    return 0;
}
