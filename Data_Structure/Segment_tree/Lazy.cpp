#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

struct Node {
    ll sum = 0;
};

struct Lazy {
    ll add = 0;
};

Node tree[4 * N];
Lazy lazy[4 * N];

ll a[N];

Node mergeNode(Node left, Node right) {
    Node res;

    res.sum = left.sum + right.sum;

    return res;
}


// Apply lazy update to a node
void apply(int node, int l, int r, ll val) {

    tree[node].sum += val * (r - l + 1);

    lazy[node].add += val;
}


// Push lazy value to children
void push(int node, int l, int r) {

    if (lazy[node].add == 0)
        return;

    if (l != r) {

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, lazy[node].add);

        apply(node * 2 + 1, mid + 1, r, lazy[node].add);
    }

    lazy[node].add = 0;
}

void build(int node, int l, int r) {

    if (l == r) {
        tree[node].sum = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] =
        mergeNode(tree[node * 2],
                  tree[node * 2 + 1]);
}

void update(int node, int l, int r,
            int ql, int qr, ll val) {

    // No overlap
    if (r < ql || qr < l)
        return;

    // Complete overlap
    if (ql <= l && r <= qr) {
        apply(node, l, r, val);
        return;
    }

    push(node, l, r);

    int mid = (l + r) / 2;

    update(node * 2, l, mid,
           ql, qr, val);

    update(node * 2 + 1, mid + 1, r,
           ql, qr, val);

    tree[node] =
        mergeNode(tree[node * 2],
                  tree[node * 2 + 1]);
}


Node query(int node, int l, int r,
           int ql, int qr) {

    // Complete overlap
    if (ql <= l && r <= qr)
        return tree[node];

    push(node, l, r);

    int mid = (l + r) / 2;

    if (qr <= mid)
        return query(node * 2,
                     l, mid,
                     ql, qr);

    if (ql > mid)
        return query(node * 2 + 1,
                     mid + 1, r,
                     ql, qr);

    Node left =
        query(node * 2,
              l, mid,
              ql, qr);

    Node right =
        query(node * 2 + 1,
              mid + 1, r,
              ql, qr);

    return mergeNode(left, right);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int l, r;
            ll x;

            cin >> l >> r >> x;

            update(1, 1, n, l, r, x);
        }

        else {

            int l, r;
            cin >> l >> r;

            Node ans =
                query(1, 1, n, l, r);

            cout << ans.sum << '\n';
        }
    }
}