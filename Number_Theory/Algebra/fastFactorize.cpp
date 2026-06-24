/// Complexity: O(n^(1/4) * log n)


using u64 = unsigned long long;

void fastFactorize(u64 n, map<u64, int>& factors) {
    if (n == 1) return;

    if (isPrimeMillerRabin(n)) {
        factors[n]++;
        return;
    }

    u64 d = pollardRho(n);

    fastFactorize(d, factors);
    fastFactorize(n / d, factors);
}