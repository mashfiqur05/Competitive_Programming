///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int arr[] = {5, 1, 3, 2, 6, 8, 12, 5, 6, 10};
    int n = 10;     /// size of the array
    int swaps = 0;

    /// Bubble Sort - large at end for ascending

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1])  /// for descending just change the operator.
            {
                swap (arr[i], arr[i+1]);
                swaps++;
            }
        }
    }

    cout << "Array is sorted in " << swaps << "swap" << endl;
    cout << "First Element: " << arr[0] << endl;
    cout << "Last Element: " << arr[n-1] << endl;

    return 0;
}

/// Problem - https://vjudge.net/problem/HackerRank-ctci-bubble-sort