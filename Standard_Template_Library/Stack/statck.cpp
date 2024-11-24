#include <bits/stdc++.h>
using namespace std;

int main ()
{
    /// Declare a stack
    stack<int> st;

    /// Adding elements in stack
    st.push (3);    /// O(1)
    st.push (2);
    st.push (1);
    st.push (4);

    ///returns the size of the stack
    cout << st.size() << endl;  /// Output: 4


    /// Access the top element
    int a = st.top();
    cout << a << endl;  /// Output: 4

    /// returns 0 or 1.
    cout << st.empty() << endl; /// Ouput: 0

    /// print all element of stack
    while (!st.empty())
    {
        cout << st.top() << " ";   /// Output: 4 1 2 3 
        st.pop();   
    }
    cout << endl;

    cout << st.empty() << endl; /// Output: 1

    return 0;
}