# Sieve of Eratosthenes

The Sieve of Eratosthenes is one of the most efficient algorithms for finding all prime numbers up to a given number \( n \). It is simple to implement and uses the concept of marking multiples of primes.

---

## Algorithm Overview

### Definition of Primality
- A prime number is a number greater than 1 that has no divisors other than 1 and itself.

### Core Idea
- For each prime \( p \), mark all multiples of \( p \) (starting from \( p^2 \)) as non-prime.

### Optimization
- Start marking from \( p^2 \) because any smaller multiple of \( p \) (e.g., \( 2p, 3p \)) would have already been marked by smaller primes.

---

## Algorithm Steps

1. **Initialization**:
   - Create a boolean array `is_prime` of size \( n+1 \) and set all entries to `true`.
   - Set `is_prime[0]` and `is_prime[1]` to `false` (0 and 1 are not prime).

2. **Mark Multiples**:
   - For each \( i \) starting from 2 up to \( \sqrt{n} \):
     - If `is_prime[i]` is `true`, mark all multiples of \( i \) as `false`.

3. **Output**:
   - All indices of the array `is_prime` that remain `true` correspond to prime numbers.

---

### Implementation
```cpp
vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int multiple = i * i; multiple <= n; multiple += i) {
                is_prime[multiple] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}
```
---
## Complexity Analysis

### Time Complexity
- The algorithm iterates over all numbers up to \( n \), but marking the multiples of each prime \( p \) occurs only once for all primes.
- The total number of operations is proportional to:
  Sum(p is prime) [n / p]

  This series converges to `O(n log log n).`

### Space Complexity
- The algorithm uses a boolean array of size \( n+1 \) to keep track of whether a number is prime.
- Space required: \( O(n) \).

**Summary**:
- **Time Complexity**: `O(n log log n).`
- **Space Complexity**: \( O(n) \)
---
## Segmented Sieve - Explanation

The **Segmented Sieve** is an optimized version of the Sieve of Eratosthenes designed to efficiently find prime numbers in a range or when memory constraints exist. It divides the range into smaller **blocks** and processes each block independently.

### Key Concepts

1. **Block Processing**:
   - The range \( [1, n] \) is divided into smaller blocks of size \( S \).
   - Each block \( k \) represents the range \( [k * S, k * S + S - 1] \).

2. **Precomputed Small Primes**:
   - First, all prime numbers up to √n are computed using a simple sieve. These primes are reused to mark non-prime numbers in each block.

3. **Efficient Sieving**:
   - For each block, use the precomputed primes to mark multiples of those primes as non-prime.

4. **Cache-Friendly**:
   - Blocks are small enough to fit into CPU caches, leading to better performance compared to processing the entire range at once.

5. **Memory Usage**:
   - The memory complexity is \( O(√n + S) \), where \( S \) is the block size.

---

## Finding Primes in a Specific Range

This method is useful for finding primes in a range \( [L, R] \), where \( R \) can be very large, such as 10<sup>12</sup>.

### Key Concepts

1. **Small Prime Precomputation**:
   - Compute all prime numbers up to √R using a simple sieve.

2. **Range Sieving**:
   - Use the precomputed primes to mark multiples of those primes as non-prime in \( [L, R] \).
   - Adjust the marking for the range:
     - The smallest multiple of a prime `p` int [L, R] is max (p<sup>2</sup>, [L/p] * p).
3. **Edge Cases**:
   - Numbers \( 0 \) and \( 1 \) are set as non-prime explicitly.
   - If \( L = 1 \), mark \( 1 \) as non-prime.

4. **Time Complexity**:
   -  `O((R - L + 1) log log R + √R log log √R).`

### Benefits
- Efficient for large ranges with small size differences (\( R - L + 1 \)).
- Memory efficient, storing only the range \( [L, R] \) and primes up to \( √R \).

---
## Implementation

This code counts the number of primes less than or equal to 
n using a Segmented Sieve approach.

```cpp
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}
```

This code finds all prime numbers in the range [L,R] using a Segmented Sieve approach with precomputed primes.

```c++
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
```

This code finds all primes in the range [L,R] using a Segmented Sieve approach without precomputing primes.
```cpp
vector<char> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
```
---

By using the Segmented Sieve, we can efficiently handle both large ranges and memory constraints 
while maintaining the core idea of the Sieve of Eratosthenes.
