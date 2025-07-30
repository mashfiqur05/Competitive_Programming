## Some technique or facts that I noticed while practicing

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
