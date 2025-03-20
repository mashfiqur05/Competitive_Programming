///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;


int arr[] = {0, 0, 0, 0, 1, 1, 1, 1};
/// Find the last index of last occurance of 0 and first occurance of 1.



int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n = arr.size();
    int l = 0, r = n;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == 0) l = mid + 1;
        else r = mid - 1;
    }

    int ans0 = l-1;
    int ans1 = l;

    cout << ans0 << " " << ans1 << endl;

    return 0;
}
