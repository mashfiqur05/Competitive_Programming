//  O(log n)

int numberOfDivisors(map<int, int>& factors) {
    int ans = 1;

    for (auto u : factors) {
        int power = u.second;

        ans *= (power + 1);
    }

    return ans;
}
