# Euclidean Algorithm (Basic and Extended)

## Computing GCD using Euclidean Algorithm

GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common prime factors.

```
36 = 2 * 2 * 3 * 3
60 = 2 * 2 * 3 * 5

GCD = Multiplication of common factor
    = 2 * 2 * 3
    = 12
```

### Intuition

- If we subtract a smaller number from a larger one (we reduce a larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
- Now instead of subtraction, if we divide the larger number, the algorithm stops when we find the remainder 0.

**Recursive Implementation**

```c++
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
```

**Time Complexity:** `O(log (min (a, b)))`

## Least common multiple

```c++
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
```

## Extended Euclidean Algorithm

Extended version represent an equation

```
a*x + b*y = gcd (a, b)
```

Besides from Bézout's lemma we can say that let a, b is interger and gcd (a, b) = d then there exist integer such that x and y.

The original algorithm is simple we will call untill b = 0 and a = g, g = gcd (a, b).

```
g*1 + 0*0 = g
```

Staring from (x, y) = (1, 0) we canrecursively find such result.

Now, we can write the coefficient (x1, y1) = (b, a mod b)

```
b*x1 + (a mod b)*y1 = g
a mod b = a - floor (a/b) * b
.
.
.
x = y1
y = x1 - y1 * floor (a/b)
```

### Implementation

```c++
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
```
This implementation produces correct results for negative integers 
as well.