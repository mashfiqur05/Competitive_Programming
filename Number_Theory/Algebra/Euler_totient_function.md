# Euler's totient function
Euler's totient function also known as phi function Φ(n).

Φ (n) = total number of integer from 1 to n that is coprime with n.

### Formula to find Φ(n)
```
Φ(n) = n-1, if n = prime.
Φ(n) = (p-1) * (q-1) if n = p * q and p and q are prime number.
Φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * .., if n = p1 * p2 where p1, p2 are composite numbers. 
```

Actually we can also find Φ(n) like this

Φ(n) = n - not to co-prime with n.<br>
Φ(p<sup>x</sup>) = p<sup>x</sup> - not to co-prime with p<sup>x</sup>.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; = P<sup>x</sup> - number of multiple of P.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; = P<sup>x</sup> - (p<sup>x</sup>/P)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; = P<sup>x-1</sup> (P-1)<br>

### Implementation
O(sqrt(n))
```c++
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
```

#### Euler totient function 1 to n using sieve idea
Complexity: O(nloglogn)
```c++
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```

