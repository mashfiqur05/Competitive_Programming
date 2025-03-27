# C++ Bitwise Operators

Bitwise Operators are utilized to execute operations on the bit level of integers. During the execution of these operations, integers are regarded as sequences of binary digits. In C++, we have various types of Bitwise Operators.

1. Bitwise AND (&)
2. Bitwise OR (|)
3. Bitwise XOR (^)
4. Bitwise NOT (~)
5. Left Shift (<<)
6. Right Shift (>>)

**Note**: Bitwise operators can only be used alongside `char` and `int` data types.

## Bitwise AND Operator
The **bitwise AND** & operator returns `1` if and only if both the operands are `1`. Otherwise, it returns `0`.

The following table demonstrates the working of the **bitwise AND** operator. Let **a and b** be two operands that can only take binary values i.e. 1 and 0.

| a        |     b    |  a & b   |
|:----------:|:----------:|:----------:|
| 0        | 0        |   0      |
| 0        | 1        |   0      |
| 1        | 0        |   0      |
| 1        | 1        |   1      |

**Note**: The table above is known as the "**Truth Table**" for the **bitwise AND** operator.

**Example:  Bitwise AND**

Let us look at the **bitwise AND** operation of two integers 7 and 13:
```c++
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a = 7, b = 13; 

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;

    return 0;
}
```
**Output**
```
a = 7
b = 13
a & b = 5
```
<br>

**Performing with the help of truth table**
```
7 = 00000111 (In Binary)

13 = 00001101 (In Binary)

//Bitwise AND Operation of 7 and 13

     00000111
&    00001101
     _________
     00000101  = 5 (In decimal)
```

## 2. Bitwise OR (|)
The **bitwise OR** | operator returns `1` if at least one of the operands is `1`. Otherwise, it returns `0`.

The following truth table demonstrates the working of the **bitwise OR** operator. Let **a** and **b** be two operands that can only take binary values i.e. **1** or **0**.

| a        |     b    |  a  b   |
|:----------:|:----------:|:----------:|
| 0        | 0        |   0      |
| 0        | 1        |   1      |
| 1        | 0        |   1      |
| 1        | 1        |   1      |

**Example: Bitwise OR**

Let us look at the **bitwise OR** operation of two integers 7 and 13:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 7, b = 13;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a | b = " << (a | b) << endl;

    return 0;
}
```

**Output**

```
a = 7
b = 13
a | b = 15
```

**Performing with the help of truth table**
```
7 = 00000111 (In Binary)

13 = 00001101 (In Binary)

//Bitwise OR Operation of 7 and 13

     00000111
|    00001101
     _________
     00001111 = 15 (In decimal)
```

## Bitwise XOR Operator

The **bitwise XOR (^)** operator returns `1` if and only if one of the operands is `1`. However, if both the operands are `0`, or if both are `1`, then the result is `0`.

| a        |     b    |  a ^ b   |
|:----------:|:----------:|:----------:|
| 0        | 0        |   0      |
| 0        | 1        |   1      |
| 1        | 0        |   1      |
| 1        | 1        |   0      |

**Example: Bitwise XOR**

Let us look at the **bitwise XOR** operation of two integers 7 and 13:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 7, b = 13;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a ^ b = " << (a ^ b) << endl;

    return 0;
}
```

**Output**

```
a = 7
b = 13
a ^ b = 10
```
<br>

**Performing with the help of truth table**
```
7 = 00000111 (In Binary)

13 = 00001101 (In Binary)

//Bitwise XOR Operation of 7 and 13

     00000111
^    00001101
     _________
     00001010 = 10 (In decimal)
```

## 4. Bitwise NOT / Bitwise Complement (~)

The **bitwise NOT** operator is a **unary operator** (works on only one operand). It is denoted by `~` that changes binary digits `1 to 0` and `0 to 1`.

**Note:** bitwise complement of any integer N is equal to `-(N + 1)`.

Consider an integer 35. As per the rule, the bitwise complement of `35` should be `-(35 + 1) = -36`. Now, let's see if we get the correct answer or not.

```
35 = 00100011 (In Binary)

// Using bitwise complement operator
~ 00100011 
 __________
  11011100
```

In the above example, we get that the bitwise complement of `00100011 (35)` is `11011100`. Here, if we convert the result into decimal we get `220`.

However, it is important to note that we cannot directly convert the result into decimal and get the desired output. This is because the binary result `11011100` is also equivalent to `-36`.

To understand this we first need to calculate the binary output of **-36.** We use **2's complement** to calculate the binary of negative integers.

### 2's Complement
The **2's complement** of a number N gives -N.

Example: 
```
36 = 00100100 (In Binary)

1's Complement = 11011011 

2's Complement :   
11011011
 +     1
_________
11011100    
````
Here, we can see the 2's complement of **36 (i.e. -36)** is **11011100**. This value is equivalent to the bitwise complement of **35** that we have calculated in the previous section.

Hence, we can say that the bitwise complement of **35 = -36**.

**Example**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int num1 = 35;
    int num2 = -150;
    cout << "~(" << num1 << ") = " << (~num1) << endl;
    cout << "~(" << num2 << ") = " << (~num2) << endl;

    return 0;
}
```
**Output**
```
~(35) = -36
~(-150) = 149
```

## 5. Left Shift (<<)

The **left shift operator** shifts all bits towards the left by a certain number of **specified bits**. It is denoted by `<<`.

When we shift any number to left, the **most significant bits**are discared, while the **least significant bits** are replaced by **zeros**.

**Example**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 157;
    
    for (int i = 0; i < 4; i++)
    {
        cout << "157 << " << i << " = " << (a << i) << endl;
    }
    
    return 0;
}
```
**Output**
```
157 << 0 = 157
157 << 1 = 314
157 << 2 = 628
157 << 3 = 1256
```
From the output of the program above, we can infer that, for any number N, the results of the **shift left operator** are:
```
N << 0 = N
N << 1 = (N << 0) * 2
N << 2 = (N << 1) * 2
N << 3 = (N << 2) * 2
```

## 6. Right Shift (>>)
The **right shift operator** shifts all bits towards the right by a certain number of **specified bits**. It is denoted by `>>`.

When we shift any number to the right, the **least significant bits** are discarded, while the **most significant bits** are replaced by **zeroes**.

**Example**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 157;
    
    for (int i = 0; i < 4; i++)
    {
        cout << "157 >> " << i << " = " << (a >> i) << endl;
    }
    
    return 0;
}
```
**Output**
```
157 >> 0 = 157
157 >> 1 = 78
157 >> 2 = 39
157 >> 3 = 19
```
From the output of the program above, we can infer that, for any number N, the results of the shift right operator are:
```
N >> 0 = N
N >> 1 = (N >> 0) / 2
N >> 2 = (N >> 1) / 2
N >> 3 = (N >> 2) / 2
```

**Hence we can also include**
```
N >> m = [ N >> (m-1) ] / 2
N << m = [ N << (m-1) ] * 2
```
If there is no overflow, an expression `x << k` is equal to `x*2^k`.

Same as `x >> k` is equal to `x/2^k`.

Another important thing `x % 2^k` is equal to `x & ((1 << k) - 1)`.

<br>

**Some property or trick of bitwise operations**

1. 
    If no. of set bit in A = x.

    and no. of set bit in B = y.

    and no. of set bit in (A^B) = z.

    then z will be even if (x+y) is even and z will be odd if (x+y) is odd.

2. 
    Your task if if `x = 20` make `x = 15` and if `x = 15` make `x = 20`. You can do this easily by using conditions.
Hence, you can do this in a cool way by writting only 1 line code.

    `x = 20 ^ 15 ^ x`.

    Here if `x = 20` then equation will be `x = 20 ^ 15 ^ 20`.
    and x will be `15`.Same for x = 15.

3. 
    (A + B) = (A ^ B) + 2 * (A & B).

    (A + B) = (A | B) + (A & B).

4. Finding the number of set bits in a number x with a complexity of O(1).
    ```c++
    __builtin_popcount (x); /// When x is int.
    __builtin_popcountll (x); /// When x is long long int.
    ```


## Here are some property of bitwise operation

### Addition
- a+b = (a^b) + 2(a&b)
- a+b = (a|b) + (a&b)

