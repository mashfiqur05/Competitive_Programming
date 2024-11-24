# Introduction to Dynamic Programming

The purpose of dynamic programming is to avoid repeated calcualtion and solve problem with a better time complexity.Dynamic problem normally solvable with recursion.

One of the famous example of recursion is to find the n-th fibonacci number.

```c++
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n-1) + fib(n-2);
}
```
This is a easy way to find fibonacci number with recursion. But its time complexity is O(2^n). It is huge. You can do this O(n) complexity by using dynamic programming. 

If we want to find fib(6). Here fib(6) call fib (5) and fib(4). then fib(5) will call fib(4) and fib(3). on the other side fib(4) will call fib(3) and fib(2). Look here we are calculating multiple time fib(4), fib(3), fib(2)... 
We can save the fib(4) then when we need it then we can return it in O(1) without again claculating it. This is called `memoization` means writting in a memo pad (not memorization).

```c++
const int MAXN = 100;
int dp[MAXN];
memset(dp, -1, sizeof(dp)); /// all elements filled with -1.

int fib (int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];

    return dp[n] = fib (n-1) + fib (n - 2);
}
```

This approch is called as top-down approch. we are calculation from the top and going towards down(base case).

This problem can be written with bottom-up approch.

```c++
const int MAXN = 100;
int dp[MAXN];
memset(dp, -1, sizeof(dp)); /// all elements filled with -1.

dp[0] = 0;
dp[1] = 1;
for (int i = 2; i <= n; i++)
{
    dp[i] = dp[i-1] + dp[i-2];
}
```

Bottom-up approch is opposote of top-down approch.

## When we use DP in a problem

### Properties of `DP`
- Overlapping Subproblems
- Optimal Substructure

### Defining a `DP` problem
- State / Parameter
- Return Values
- Base Case / Corner Case
- Transitins
- Memorization

