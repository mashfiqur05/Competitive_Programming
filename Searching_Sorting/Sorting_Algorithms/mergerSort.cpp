///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, arr[100005], tmp[100005];

void merge (int l, int r)
{
    int mid = (l + r) / 2;
    int i1 = l, i2 = mid + 1, j = l;

    while (i1 <= mid && i2 <= r)
    {
        if (arr[i1] <= arr[i2])
        {
            tmp[j] = arr[i1];
            i1++;
        }
        else 
        {
            tmp[j] = arr[i2];
            i2++;
        }
        j++;
    }

    while (i1<=mid) tmp[j++] = arr[i1++];
    while (i2<=r) tmp[j++] = arr[i2++];

    for (int j = l; j <= r; j++) arr[j] = tmp[j];
}

void mergeSort (int l, int r)
{
    if (l == r) return;

    int mid = (l + r) / 2;
    mergeSort (l, mid);
    mergeSort (mid + 1, r);

    merge (l, r);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort (0, n-1);

    for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;

    return 0;
}
