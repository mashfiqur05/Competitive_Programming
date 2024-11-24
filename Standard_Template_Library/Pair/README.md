# Pair
`Pair` is used to combine together two values that may be of different data types.

## Declaration and Initialization

**Syntax**

```c
pair <data_type1, data_type2> Pair_name
```

`make_pair():` This template function allows to create a value pair without writing the types explicitly. 

```c++
pair<int,int> p;

p = make_pair ( 13, 15 );
cout << p.first << " " << p.second << endl; /// Output: 13 15

pair<int, int> p1 = { 2, 3 };
pair<int, int> p2 = { 1, 6 };
```

## Swap
`Swap()`: This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of the same type.

```c++
pair1.swap(pair2) ;
```

## Decomposing
`tie()`: This function works the same as in tuples. It creates a tuple of lvalue references to its arguments i.e., to unpack the tuple (or here pair) values into separate variables. Just like in tuples, here are also two variants of the tie, with and without “ignore”. “ignore” keyword ignores a particular tuple element from getting unpacked. 
```c++
tie(int &, int &) = pair1; 
```

