// O(log n)
int sumOfDivisors(map<u64, int>& factors) {
    int ans = 1;

    for (auto u : factors) {
        int prime = u.first;
        int power = u.second;

        int term = 1;
        int curPower = 1;

        for (int i = 1; i <= power; i++) {
            curPower *= prime;
            term += curPower;
        }

        ans *= term;
    }

    return ans;
}