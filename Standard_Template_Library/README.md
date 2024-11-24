# Standard Template Library
In C++, the **Standard Template Library (STL)** provides a set of programming tools to implement algorithms and data structures like vectors, lists, queues, etc.

C++ STL has 3 major components:
- Containers
- Iterators
- Algorithms

## STL Containers

STL containers store data and organize them in a specific manner as required.

For example, vectors store data of the same type in a sequential order. Whereas, maps store data in key-value pairs.

We can classify STL containers into 3 types:

**1. Sequence containers:**
- Array
- Vector
- Queue
- Deque
- Forward_list
- List

**2. Associative containers:**

- Set
- Multiset
- Map
- Multimap

**3. Unordered associative containers:**

- Unordered_set
- Unordered_multiset
- Unordered_map
- Unordered_multimap

##  STL Iterators

terators are objects that are used to access elements of a container.

We can declare an iterator for each container in the **C++ Standard Template Library.** For example,
```c++
vector<int>::iterator it;
```

**Note:** The asterisk * before itr indicates that the value of the element that the iterator points to is being accessed. This is similar to dereferencing pointers.

Also, when we try to print the iterators, we get an error.
```C++
// error
cout << itr << "  ";
This is because, unlike pointers, we cannot print an iterator.
```

## STL Algorithms
An algorithm is a series of instructions to solve a particular problem.

Some of the most commonly used **algorithms** in the C++ Standard Template Library are:

- Sorting algorithms
- Searching algorithms
- Copying algorithms
- Counting algorithms

```C++
// sort vector elements in ascending order
    sort(numbers.begin(), numbers.end());
```