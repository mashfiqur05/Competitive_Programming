# Chinese Remainder Theorem
Chinese Remainder Theorem says that there is a unique solution for the system of simultaneous congruences
```
x ≡ a1 (mod m1)
x ≡ a2 (mod m2)
.
.
.
x ≡ ak (mod mk)
```
Here m<sub>i</sub> are pairwise co-prime.

x = (a<sub>1</sub>M<sub>1</sub>M<sub>1</sub><sup>-1</sup> + a<sub>2</sub>M<sub>2</sub>M<sub>2</sub><sup>-1</sup> + a<sub>k</sub>M<sub>k</sub>M<sub>k</sub><sup>-1</sup>) mod M

Here, M = m<sub>1</sub>*m<sub>2</sub>*..m<sub>k</sub>
, M<sub>i</sub> = (M / m<sub>i</sub>)


## Implementation
```c++
struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
```
### Trick
Problem: The number of students in a school is between 500 and 600. If we group them into groups of 12, 20, or 36 each, 7 students are always left over. How many students are in this school?

```
x = 7 (mod 12)
x = 7 (mod 20)
x = 7 (mod 36)

we can write..
x = 7 (mod lcm (12, 20, 36))
x = 7 (mod 180)
```
Here moduli are not pairwise co-prime. But it is possible because of remainders are same.
