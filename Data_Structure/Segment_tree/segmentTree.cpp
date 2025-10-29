///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 2e5;

int segm_tree[4*MX], arr[MX];

// Calculate the value of a node from its children
int calculate(int node) {
    return min(segm_tree[2*node], segm_tree[2*node + 1]);
}

// Build the segment tree: node = current node in tree, [left, right] = segment
void build(int node, int left, int right) {
    if (left == right) {
        segm_tree[node] = arr[left]; // leaf node
    } else {
        int mid = left + (right - left)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segm_tree[node] = calculate(node);
    }
}

// Update position idx to value val
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] = val;
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx, val);
        else update(2*node + 1, mid + 1, right, idx, val);
        segm_tree[node] = calculate(node);
    }
}

// Query minimum in range [l, r]
int query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) return LLONG_MAX; // no overlap
    if (l <= left && right <= r) return segm_tree[node]; // full overlap
    int mid = left + (right - left)/2;
    return min(
        query(2*node, left, mid, l, r),
        query(2*node + 1, mid + 1, right, l, r)
    );
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    // Read 1-indexed array
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n); // root at 1, array 1-indexed

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(1, 1, n, a, b); // no -1 needed now
        } else {
            cout << query(1, 1, n, a, b) << endl;
        }
    }
}
