# Tuples
### What is a tuple? 
A tuple is an object that can hold a number of elements. The elements can be of different data types. Normally it is used to store multiples items in a single variable.

<br>

**Header file for tuples**

```c++
#include<tuple> 
```


## Declaring Tuples
```c++
tuple <string, int, double> tup1;
```
## Assigning Values
**make_tuple():**  make_tuple() is used to assign tuple with values. The values passed should be in order with the values declared in tuple. 

```c++
tup1 = make_tuple ("Nadif", 19, 24.245);
```

You can also declaring tuples and assigning values in the same time.
```c++
tuple <string, int, double> tup2 ("Shihab", 23, 67.345);
```
## Accessing tuples values

**get():** get() is used to access the tuple values and modify them, it accepts the index and tuple name as arguments to access a particular tuple element. 

**Syntax**
```c++
get<index_value>(tuples_name)
```
## Use of get() to change values of tuple

```c++
get<0>(tup1) = "Mashfiqur";
```
## tuple_size
It returns the number of elements present in the tuple.
```c++
tuple <string, int, double> tup1;
cout << tuple_size<decltype(tup1)>::value << endl;
```
## Swaping Values 
**swap():** The swap(), swaps the elements of the two different tuples. 
```c++
tuple<int, char, bool> thing1 (12, 'a', true);
tuple<int, char, bool> thing2 (28, 'v', false);
thing1.swap (thing2);
```
## Decomposing Tuples

**tie()**: The work of tie() is to unpack the tuple values into separate variables. There are two variants of tie(), with and without “**ignore**” , the “**ignore**” ignores a particular tuple element and stops it from getting unpacked.

```c++
tuple <int, int> t(12, 16);
tuple <int, char, string> tup3(28, 'w', "uddin");
int x, y, z;
string s;

tie (x, y) = t;
cout << x << " " << y << endl;  /// Output: 12 16
cout << get<0>(t) << ' ' << get<1>(t) << endl;  ///Output: 12 16

// Use of tie() with ignore
// ignores char value

tie (z, ignore, s) = tup3;
cout << z << " " << s << endl; /// Output: 28 uddin
```
## Concating Tuples

**tuple_cat() :** This function concatenates two tuples and returns a new tuple. 

```c++
tuple <string, int> t1 ("rahman", 25);
tuple <double, char, bool> t2 (13.45, 'e', true);
auto t3 = tuple_cat(t1, t2);

cout << get<0>(t3) << endl; /// Output: rahman
cout << get<1>(t3) << endl; /// Output: 25
cout << get<2>(t3) << endl; /// Output: 13.45
cout << get<3>(t3) << endl; /// Output: e
cout << get<4>(t3) << endl; /// Output: 1
```