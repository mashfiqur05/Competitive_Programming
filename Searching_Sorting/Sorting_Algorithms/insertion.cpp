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

    for (int i = 1; i < n; i++)
    {
        int j = i-1, key = arr[i];

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<arr[j] to key>arr[j].
        
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;

    return 0;
}

/// Problem - https://vjudge.net/problem/Aizu-ALDS1_1_A
