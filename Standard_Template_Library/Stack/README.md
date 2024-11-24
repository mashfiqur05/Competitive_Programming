# Stack
he STL stack provides the functionality of a stack data structure in C++.

The stack data structure follows the **LIFO (Last In First Out)** principle. That is, the element added last will be removed first.

## Create a Stack
In order to create a stack in C++, we first need to include the stack header file.

```c++
#include <stack>
```
Once we import this file, we can create a stack using the following syntax:
```c++
stack<type> st;
```
Here, type indicates the data type we want to store in the stack. For instance,
```c++
// create a stack of integers
stack<int> integer_stack;

// create a stack of strings
stack<string> string_stack;
```

The functions associated with stack are: 

## Add Element Into the Stack

**push(g) –** Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
```c++
stack<int> st;
st.push (10);
st.push (15);
```

## Remove Elements From the Stack

**pop() –** Deletes the most recent entered element of the stack – Time Complexity : O(1) 
```c++
st.pop();   /// removes top element
```

## Access Elements From the Stack
**top() –** Returns a reference to the top most element of the stack – Time Complexity : O(1)
```c++
int a = st.top();
```

## Get the Size of the Stack
**size() –** Returns the size of the stack – Time Complexity : O(1) 
```c++
int sz = st.size(); /// stores the size of the stack
```
## Check if the Stack Is Empty

**empty() –** Returns whether the stack is empty – Time Complexity : O(1) 
