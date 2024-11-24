#include<bits/stdc++.h>
using namespace std;

int main()
{
    /// Declare a vector
    vector<int> v;

    /// Input
    v.push_back(1);    /// It means push element from back
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    /// Access elements of vector
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl; /// Output: 1 2 3


    /// Difference between capacity() and size() function
    vector<int> v1 = {1, 3, 5, 7};
    cout << v1.size() << endl;  /// Output: 4
    cout << v1.capacity() << endl;  /// Output: 4

    v1.push_back(7);
    cout << v1.size() << endl;  /// Output: 5
    cout << v1.capacity() << endl;  /// Output: 8
    
    v1.push_back(9);
    cout << v1.size() << endl;  /// Output: 6
    cout << v1.capacity() << endl;  /// Output: 8

    /// Using shrink_to_fit function
    v1.shrink_to_fit();
    cout << v1.size() << endl;  /// Output: 6
    cout << v1.capacity() << endl;  /// Output: 6

    vector<int> v2 = {1, 2, 3, 4, 5};
    v2.insert(v2.begin(), 5);
    cout << v2[0]  << endl;  /// Output: 5
    v2.insert(v2.begin() + 4, 9);
    cout << v2[4]  << endl;  /// Output: 9


    /// Output method
    vector<int> v3 = {2, 4, 6, 8, 10};
    /// using for loop
    for (int i = 0; i < v3.size(); i++) cout << v3[i] << ' ';  /// Output: 2 4 6 8 10
    cout << endl;

    /// Using iterators
    vector<int>::iterator it;
    for (it = v3.begin(); it != v3.end(); it++) cout << *it << " "; /// Output: 2 4 6 8 10
    cout << endl;

    /// Using for each loop
    for (auto u : v3) cout << u << ' ';  /// Output: 2 4 6 8 10
    cout << endl;

    
    v.clear();  /// Clears the value only, does not delete the memory
    cout << v.size() << endl; /// Output: 0
    cout << v.empty() << endl; /// Output: 1
    cout << v1.empty() << endl; /// Output: 0

    v.resize(5);  //// Change the size of the vector
    cout << v.size() << endl;   /// Output: 5
    for (auto u : v) cout << u << ' '; /// Output: 0 0 0 0 0
    cout << endl;


    vector<int> a = { 3, 4, 5, 1, 2, 1};

    /// sort all element in non-decreasing order
    sort(a.begin(), a.end()); /// O(n*log2(n))
    for (auto u : a) cout << u << " "; /// Output: 1 1 2 3 4 5
    cout << endl;

    sort(a.begin(), a.end(), greater<int>());   ///sort all element in non-increasing order
    for (auto u : a) cout << u << " "; /// Output : 5 4 3 2 1 1
    cout << endl;

    /// reverse the vector
    a = { 3, 4, 5, 1, 2 };
    reverse(a.begin(), a.end());
    for (auto u : a) cout << u << " "; /// Ouput: 2 1 5 4 3
    cout << endl;

    /// Remove the last element
    cout << a.back() << endl; /// 3
    a.pop_back(); /// O(1) complexity.
    cout << a.back() << endl; /// 4

    a = { 3, 4, 5, 1, 2 };
    cout << *a.begin() << endl; /// Output: 3

    a.erase(a.begin()); /// O(n) complexity.
    for (auto u : a) cout << u << " "; /// Output: 4 5 1 2
    cout << endl;

    a.erase(a.begin() + 2);
    for (auto u : a) cout << u << " "; /// Output: 4 5 2
    cout << endl;


    /// Find unique elements 
    a = { 1, 1, 2, 2, 2, 3, 3 };
    auto end = unique(a.begin(), a.end());

    for (auto it = a.begin(); it != end; ++it) cout << *it << " "; /// Output: 1 2 3
    cout << endl;

    int unique_count = end - a.begin();   /// Determine the number of unique elements
    cout << unique_count << endl; /// Output: 3

    /// maximum element. Complexity = O(n).
    a = {2, 3, 1, 5};
    cout << max_element(a.begin(), a.end()) - a.begin() << endl; /// Output: 3. print index of max value.
    cout << *max_element(a.begin(), a.end()) << endl;            /// Output: 5 print the max value.

    //// same thing using iterator .
    vector<int>::iterator max_it = max_element(a.begin(), a.end());
    cout << *max_it << endl; /// Output: 5.

    int max_index = max_element(a.begin(), a.end()) - a.begin();
    cout << max_index << endl; /// Output: 3. index of max value.

    /// minimum element. Complexity = O(n)
    vector<int>::iterator min_it = min_element(a.begin(), a.end()); /// min value.
    cout << *min_it << endl;  /// Output: 1

    int min_index = min_element(a.begin(), a.end()) - a.begin(); /// index of min value
    cout << min_index << endl; /// Output: 2

    return 0;
}
