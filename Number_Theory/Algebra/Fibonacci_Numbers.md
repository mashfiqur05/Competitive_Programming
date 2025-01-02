# Fibonacci Numbers
The fibonacci sequence is defined as:
```math
F_0 = 0, F_1 = 1, F_n = F_{n-1} + F_{n-2}
```
```math
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55,...
```

## Properties
Fibonacci follows some interesting properties.Here are few of them:

- Cassini's identity:
```math
F_{n-1}F_{n+1} - F_n^2 = (-1)^n
```
- The "addition" rule:
```math
F_{n+k} = F_k F_{n+1} + F_{k-1} F_n
```
Applying the previous identity to the case $k = n$ , we get: 
```math
F_{2n} = F_n (F_{n+1} + F_{n-1})
``` 

From that we can say that for any positive integer k, F<sub>nk</sub> is a multiple of F<sub>n</sub> and also if F<sub>m</sub> is a multiple of F<sub>n</sub>, then m is a multiple of n.

`GCD identity:`
```math
GCD(F_m, F_n) = F_{GCD(m, n)}
```

According to Zeckendorf's theorem, any natural number
n can be uniquely represented as a sum of Fibonacci numbers:
```math
N = F_{k_1} + F_{k_2} + \ldots + F_{k_r}
```
Example:
```math
\begin{aligned}
1 &= 1 &= F_2 &= (11)_F \\
2 &= 2 &= F_3 &= (011)_F \\
6 &= 5 + 1 &= F_5 + F_2 &= (10011)_F \\
8 &= 8 &= F_6 &= (000011)_F \\
9 &= 8 + 1 &= F_6 + F_2 &= (100011)_F \\
19 &= 13 + 5 + 1 &= F_7 + F_5 + F_2 &= (1001011)_F
\end{aligned}
```

## Formulas for the n<sup>th</sup> Fibonacci number

There is a formula known as "Binet's formula", even though it was already known by Moivre:
```math
F_n = \frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n - \left(\frac{1 - \sqrt{5}}{2}\right)^n}{\sqrt{5}}
```

## Fibonacci in linear time
The n<sup>th</sup> fibonacci number can be obatained in O(n) complexity by adding number one by one up to n.
### Implementation
```c++
int fib(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}
```

## Fast Doubling Method

The **Fast Doubling Method** is an efficient algorithm to compute Fibonacci numbers in **O(log n)** time using recursive relationships. It is particularly useful when you need to compute large Fibonacci numbers quickly. The method is based on the observation that Fibonacci numbers can be calculated using the following recursive identities:

## Fast Doubling Identities

For any integer `n`, the following identities hold:

1. **For even indices**:
   \[
   F(2k) = F(k) \cdot \left( 2F(k+1) - F(k) \right)
   \]
2. **For odd indices**:
   \[
   F(2k+1) = F(k+1)^2 + F(k)^2
   \]

In the Fast Doubling method, we calculate Fibonacci numbers in pairs, specifically, both `F(n)` and `F(n+1)` at each step. By doing this, we reduce the number of recursive calls needed and achieve **O(log n)** time complexity.

### Implementation
```cpp
// Function to return a pair of Fibonacci numbers F(n) and F(n+1)
pair<int, int> fib(int n) {
    if (n == 0)
        return {0, 1};  // Base case: F(0) = 0, F(1) = 1
    
    // Recursive call for n // 2
    auto p = fib(n >> 1);
    
    // F(k) = p.first, F(k+1) = p.second
    int c = p.first * (2 * p.second - p.first);  // F(2k)
    int d = p.first * p.first + p.second * p.second;  // F(2k+1)
    
    if (n & 1)  // If n is odd
        return {d, c + d};  // F(n) = d, F(n+1) = c+d
    else  // If n is even
        return {c, d};  // F(n) = c, F(n+1) = d
}
```

The above code returns F<sub>n</sub> and F<sub>n+1</sub> as a pair.
