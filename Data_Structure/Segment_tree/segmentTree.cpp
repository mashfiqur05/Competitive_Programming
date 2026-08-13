///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

struct Node {
    int mn;

    Node(int _mn = LLONG_MAX) {
        mn = _mn;
    }
};

struct SegTree {

    int n;
    vector<Node> tree;
    vector<int> arr;

    SegTree(int _n) {
        n = _n;

        tree.assign(4 * n + 5, Node());
        arr.assign(n + 1, 0);
    }

    Node mergeNode(Node left, Node right) {
        return Node(min(left.mn, right.mn));
    }

    void build(int node, int left, int right) {

        if (left == right) {
            tree[node] = Node(arr[left]);
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);

        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    void update(int node, int left, int right,
                int idx, int val) {

        if (left == right) {
            tree[node] = Node(val);
            return;
        }

        int mid = left + (right - left) / 2;

        if (idx <= mid)
            update(2 * node, left, mid, idx, val);

        else
            update(2 * node + 1,
                   mid + 1, right,
                   idx, val);


        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    Node query(int node, int left, int right,
               int l, int r) {

        // No overlap
        if (r < left || right < l)
            return Node();

        // Full overlap
        if (l <= left && right <= r)
            return tree[node];

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
};


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {

        int n, q;
        cin >> n >> q;

        SegTree st(n);

        for (int i = 1; i <= n; i++)
            cin >> st.arr[i];

        st.build(1, 1, n);

        while (q--) {

            int type, a, b;
            cin >> type >> a >> b;

            if (type == 1) {

                st.update(1, 1, n, a, b);

            } else {

                Node ans =
                    st.query(1, 1, n, a, b);

                cout << ans.mn << endl;
            }
        }
    }

    return 0;
}