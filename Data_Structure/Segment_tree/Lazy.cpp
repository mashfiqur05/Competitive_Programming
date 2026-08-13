///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long


struct Node {
    int sum;

    Node(int _sum = 0) {
        sum = _sum;
    }
};


struct Lazy {
    int add;

    Lazy(int _add = 0) {
        add = _add;
    }
};


struct SegTree {

    int n;

    vector<Node> tree;
    vector<Lazy> lazy;
    vector<int> arr;

    SegTree(int _n) {

        n = _n;

        tree.assign(4 * n + 5, Node());

        lazy.assign(4 * n + 5, Lazy());

        arr.assign(n + 1, 0);
    }

    Node mergeNode(Node left, Node right) {

        return Node(left.sum + right.sum);
    }


    // Apply lazy update to current node
    void apply(int node, int left, int right,
               int val) {

        tree[node].sum +=
            val * (right - left + 1);

        lazy[node].add += val;
    }


    // Push lazy value to children
    void push(int node, int left, int right) {

        if (lazy[node].add == 0)
            return;

        if (left != right) {

            int mid =
                left + (right - left) / 2;

            apply(2 * node,
                  left, mid,
                  lazy[node].add);

            apply(2 * node + 1,
                  mid + 1, right,
                  lazy[node].add);
        }

        lazy[node] = Lazy();
    }

    void build(int node, int left, int right) {

        if (left == right) {

            tree[node] = Node(arr[left]);

            return;
        }

        int mid =
            left + (right - left) / 2;

        build(2 * node,
              left, mid);

        build(2 * node + 1,
              mid + 1, right);

        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    void update(int node,
                int left, int right,
                int l, int r,
                int val) {

        // No overlap
        if (r < left || right < l)
            return;

        // Full overlap
        if (l <= left && right <= r) {

            apply(node,
                  left, right,
                  val);

            return;
        }

        // Push before going downward
        push(node, left, right);


        int mid =
            left + (right - left) / 2;


        update(2 * node,
               left, mid,
               l, r, val);

        update(2 * node + 1,
               mid + 1, right,
               l, r, val);


        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    Node query(int node,
               int left, int right,
               int l, int r) {

        // No overlap
        if (r < left || right < l)
            return Node();


        // Full overlap
        if (l <= left && right <= r)
            return tree[node];


        // Push before going downward
        push(node, left, right);


        int mid =
            left + (right - left) / 2;


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

            int type;
            cin >> type;


            if (type == 1) {

                int l, r, x;
                cin >> l >> r >> x;

                st.update(
                    1, 1, n,
                    l, r, x
                );

            }

            else {

                int l, r;
                cin >> l >> r;

                Node ans =
                    st.query(
                        1, 1, n,
                        l, r
                    );

                cout << ans.sum << endl;
            }
        }
    }

    return 0;
}