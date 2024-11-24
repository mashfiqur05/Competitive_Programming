# Vector
Vectors in STL are basically dynamic arrays that have the ability to change size whenever elements are added or deleted from them. Vector elements can be easily accessed and traversed using iterators. A vector stores elements in contiguous memory locations.

**Syntax**
```c++
vector<data_type> variable_name;
```

**Example:**
```c++
vector<int> v1;
vector<char> v2;
vector<string> v3;
```

# Most used functions in Vector:

**begin()** - It returns an iterator pointing to the first element of the vector.

**end()** - it returns an iterator pointing to the element theoretically after the last element of the vector.

**push_back()** - it accepts a parameter and insert the element passed in the parameter in the vectors, the element is inserted at the end.
```c++
vector<int> v;

v.push_back(1);
v.push_back(2);
```

**insert()** - it is used to insert an element at a specified position.
```c++
auto it= v1.begin();
v1.insert(it,5); //inserting 5 at the beginning
v1.insert(it+4, 9)  /// inserting 9 at the 5th position.
```
**erase()** - it is used to delete a specific element
```c++
vector<int> v1;
auto it= v1.begin();
v1.erase(it);// erasing the first element
```
**pop_back()** - it deletes the last element and returns it to the calling function.
```c++
v1.pop_back();
```
**front()** - it returns a reference to the first element of the vector.
```c++
v1.front();
```
**back()** - it returns a reference to the last element of the vector.
```c++
v1.back();
```
**clear()** - deletes all the elements from the vector.
```c++
v1.clear();
```
**empty()** - to check if the vector is empty or not.
```c++
v1.empty();
```
**size()** - returns the size of the vector
```c++
v1.size();
```
## Other Functions:

**cbegin()** - it refers to the first element of the vector.

**cend()** - it refers to the theoretical element after the last element of the vector.

**rbegin()** - it points to the last element of the vector.

**rend()** - it points to the theoretical element before the first element of the vector.

**crbegin()** - it refers to the last element of the vector.

**crend()** - it refers to the theoretical element before the first element of the vector.

**max_size()** - returns the maximum size the vector can hold.

**capacity()** - it returns the current capacity of the vector.