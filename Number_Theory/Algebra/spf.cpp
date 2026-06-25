#include<bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 123;

vector<int> spf(MX);
// SPF build: O(n log log n)
// Factorization: O(log n)

void buildSPF() {
    for(int i = 1; i < MX; i++) {
        spf[i] = i;
    }

    for(int i = 2; i * i < MX; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < MX; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;

    while(n > 1) {
        int prime = spf[n];
        int cnt = 0;

        while(n % prime == 0) {
            n /= prime;
            cnt++;
        }

        factors.push_back({prime, cnt});
    }

    return factors;
}

int main() {
    buildSPF();

    int n;
    cin >> n;

    vector<pair<int, int>> factors = factorize(n);

    for(auto [p, cnt] : factors) {
        cout << p << "^" << cnt << endl;
    }

    return 0;
}