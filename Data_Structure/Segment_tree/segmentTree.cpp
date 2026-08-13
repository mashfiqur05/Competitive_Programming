///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int MX = 2e5 + 5;

int arr[MX];

struct Node {
    int mn = LLONG_MAX;
};

Node segm_tree[4 * MX];


Node mergeNode(Node left, Node right) {
    Node res;

    res.mn = min(left.mn, right.mn);

    return res;
}

void build(int node, int left, int right) {

    if (left == right) {
        segm_tree[node].mn = arr[left];
        return;
    }

    int mid = left + (right - left) / 2;

    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);

    segm_tree[node] =
        mergeNode(segm_tree[2 * node],
                  segm_tree[2 * node + 1]);
}

void update(int node, int left, int right,
            int idx, int val) {

    if (left == right) {
        segm_tree[node].mn = val;
        return;
    }

    int mid = left + (right - left) / 2;

    if (idx <= mid)
        update(2 * node, left, mid, idx, val);

    else
        update(2 * node + 1, mid + 1, right, idx, val);


    segm_tree[node] =
        mergeNode(segm_tree[2 * node],
                  segm_tree[2 * node + 1]);
}

Node query(int node, int left, int right,
           int l, int r) {

    // No overlap
    if (r < left || right < l) {
        return Node();
    }

    // Full overlap
    if (l <= left && right <= r) {
        return segm_tree[node];
    }

    // Partial overlap
    int mid = left + (right - left) / 2;

    Node q1 =
        query(2 * node,
              left, mid,
              l, r);

    Node q2 =
        query(2 * node + 1,
              mid + 1, right,
              l, r);

    return mergeNode(q1, q2);
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (q--) {

        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            update(1, 1, n, a, b);

        } else {

            Node ans = query(1, 1, n, a, b);

            cout << ans.mn << endl;
        }
    }
}