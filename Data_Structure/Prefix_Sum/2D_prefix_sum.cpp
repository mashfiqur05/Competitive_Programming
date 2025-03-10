///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix[i][j] = arr[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) cout << prefix[i][j] << " "; cout << endl;
    }

    // Query: Find sum of submatrix (r1, c1) to (r2, c2)
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int sum = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];

    cout << "Submatrix Sum: " << sum << endl;

    return 0;
}
