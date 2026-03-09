# Knuth Optimization (DP Optimization)

## 1. Problem Pattern

Knuth Optimization applies to **interval DP** problems with the following transition:

```
dp[l][r] = min(dp[l][k] + dp[k+1][r]) + C[l][r]
```

where

```
k ∈ [l, r-1]
```

* `dp[l][r]` = optimal value for interval `[l, r]`
* `C[l][r]` = cost of merging / combining the interval
* `C[l][r]` must **not depend on k**

Typical examples:

* Merging slimes
* File merging
* Optimal BST

Normal complexity:

```
States = O(N²)
Transitions = O(N)
Total = O(N³)
```

---

# 2. Key Observation

Let

```
opt[l][r] = value of k that minimizes dp[l][r]
```

Knuth Optimization works when the **optimal split index is monotonic**:

```
opt[l][r-1] ≤ opt[l][r] ≤ opt[l+1][r]
```

This means the optimal split for a larger interval **never moves to the left**.

---

# 3. Optimization Idea

Instead of searching:

```
k = l → r-1
```

we only search:

```
k = opt[l][r-1] → opt[l+1][r]
```

This significantly reduces the search space.

Resulting complexity:

```
O(N²)
```

---

# 4. Conditions for Knuth Optimization

Knuth Optimization works if:

1.

```
dp[l][r] = min(dp[l][k] + dp[k+1][r]) + C[l][r]
```

2.

```
C[l][r] is independent of k
```

3. Cost satisfies **Quadrangle Inequality**:

```
C[a][c] + C[b][d] ≤ C[a][d] + C[b][c]
for a ≤ b ≤ c ≤ d
```

In practice this often happens when:

```
C[l][r] = prefix[r] - prefix[l-1]
```

---

# 5. Implementation Template

```cpp
vector<vector<long long>> dp(n, vector<long long>(n));
vector<vector<int>> opt(n, vector<int>(n));

for(int i=0;i<n;i++)
{
    dp[i][i] = 0;
    opt[i][i] = i;
}

for(int len=2; len<=n; len++)
{
    for(int l=0; l+len-1<n; l++)
    {
        int r = l + len - 1;
        dp[l][r] = LLONG_MAX;

        for(int k = opt[l][r-1]; k <= opt[l+1][r]; k++)
        {
            long long val =
                dp[l][k] + dp[k+1][r] + cost(l,r);

            if(val < dp[l][r])
            {
                dp[l][r] = val;
                opt[l][r] = k;
            }
        }
    }
}
```

---
Typical transition:

```
dp[l][r] = min(dp[l][k] + dp[k+1][r]) + sum(l,r)
```

---

Key idea:

```
opt[l][r-1] ≤ opt[l][r] ≤ opt[l+1][r]
```

which restricts the search range of `k`.
