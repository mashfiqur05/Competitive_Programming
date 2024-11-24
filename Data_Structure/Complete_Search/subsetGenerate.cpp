//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

void generateSubset(vector<int>& arr, vector<int>& subset, int index)
{
    if (index == arr.size())
    {
        cout << "{ ";
        for (auto val : subset) cout << val << " ";
        cout << "}" <<endl;
        return;
    }
    else
    {
        // Exclude the current element and move to the next
        generateSubset (arr, subset, index+1);
            
        // Include the current element in the subset and move to the next
        subset.push_back (arr[index]);
        generateSubset(arr, subset, index + 1);

        // Backtrack: remove the last element to restore state
        subset.pop_back();
    }
}

int32_t main() 
{
    fastio();

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> subset;
    generateSubset (v, subset, 0);

    return 0;
}

/* Problem
https://cses.fi/problemset/task/1623

*/
