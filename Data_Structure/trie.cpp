#include<bits/stdc++.h>
using namespace std;

struct Trie {
    struct node {
        node* nxt[26];
        bool isEnd;
        node() {
            for(int i = 0; i < 26; i++) nxt[i] = NULL;
            isEnd = false;
        }
    }*root;

    Trie() { root = new node(); }

    void insert(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
        }
        cur->isEnd = true;
    }

    // checks if query string exists exactly OR is a prefix of any inserted string
    pair<bool,bool> query(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) return {false, false}; // doesn't exist at all
            cur = cur->nxt[b];
        }

        bool isExact  = cur->isEnd;         // exact match exists
        bool isPrefix = true;               // we reached here = it's a prefix
        return {isExact, isPrefix};
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Trie t;
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        t.insert(s);
    }

    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        auto [isExact, isPrefix] = t.query(s);
        if(isExact && isPrefix) cout << "Exact match and prefix of longer string\n";
        else if(isExact)        cout << "Exact match only\n";
        else if(isPrefix)       cout << "Prefix only\n";
        else                    cout << "Not found\n";
    }
    return 0;
}

/*
input
5
apple
app
application
banana
bat
3
ap
app
xyz

output
Prefix only
Exact match and prefix of longer string
Not found
*/