// O(k * log n)
// k = number of different prime factors

int power(int base, int exp) {
    int ans = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            ans *= base;
        }

        base *= base;
        exp /= 2;
    }

    return ans;
}

int productOfDivisors(map<int, int>& factors) {
    int nod = numberOfDivisors(factors);
    int ans = 1;

    for (auto u : factors) {
        int prime = u.first;
        int powerCount = u.second;

        int exponent = (powerCount * nod) / 2;

        ans *= power(prime, exponent);
    }

    return ans;
}