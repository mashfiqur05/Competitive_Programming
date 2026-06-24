## Some formula, technique or facts that I noticed while practicing

## Formula
- The formula for the sum of the first n square numbers (1^2+2^2+3^2+4^2+...n^2) is 
```
(n*(n+1)*(2n+1)) / 6
```
- The formula for the sum of the first \(n\) odd square numbers is
```
(n(2n+1)(2n-1))/3
```

- To find the sum of all multiples of 3 less than 
𝑛
```
Multiple of 3 less than n - 3, 6, , 9, ...3k
sum = 3(1+2+3+..+k)
    = 3 * ((n * (n+1))/2) where k = (n-1)/3.
```
what if multiples of 7 or 11 below 500

- Even Fibonacci pattern:<br>
Every 3rd Fibonacci number is even.
```
if e1 = 2, e2 = 8
E(n) = 4*(E(n-1)) + E(n-2)
```

## Facts/Technique

- Basic property of GCD we know that gcd(x, y) = gcd (x-y, y) is applicable for multiple argument.

```
gcd (p, q, r, s) = gcd (p-p, q-p, r-p, s-p) /// p = min (p, q, r, s)
gcd(x, 0) = x
```

- If two numbers have the same remainder of m then difference of these two number is divisible by m.
```
if a % m = x and b % m = x
then abs(a - b) % m = 0.
```
