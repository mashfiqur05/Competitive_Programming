///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;

int main ()
{
    vector<int> v = {1, 4, 6, 7, 8, 9, 10, 123, 4, 6};
    
    int mn = *min_element (v.begin(), v.end()); /// returns the minimum number in the given range
    cout << mn << endl; /// 1

    int mx = *max_element (v.begin(), v.end()); /// returns the maximum number in the given range
    cout << mx << endl; /// 123

    int sum = accumulate (v.begin(), v.end(), 0);   /// returns the total sum in the range and with adding intital value.  
    cout << sum << endl;    /// 178

    int cnt = count (v.begin(), v.end(), 4);    //// returns the count of the given number.
    cout << cnt << endl;    /// 2


    reverse (v.begin(), v.end());
    cout << "After reverse..." << endl;
    for (auto val : v) cout << val << " ";  /// 6 4 123 10 9 8 7 6 4 1 
    cout << endl;


    ///   ***   ---   |||		 Lamda Function		|||   ---   ***   ///

    /// Syntax
    /// Let's write a function of add 2 number.
    auto sumOf2Number = [](int x, int y){return x + y;};
    cout <<  sumOf2Number (5, 8) << endl;   /// 13


    vector<int> a = {2, 3, 5}, b = {2, -4, 56}, c = {-3, -4, -34};

    /// all_of : If  all element's returns true then return 1 else 0.
    cout << all_of (a.begin(), a.end(), [](int x){return x > 0;}) << endl; /// 1. 
    cout << all_of (b.begin(), b.end(), [](int x){return x > 0;}) << endl; /// 0

    /// any_of: any of the element is true then return true.
    cout << any_of (b.begin(), b.end(), [](int x){return x > 0;}) << endl; /// 1. 
    cout << any_of (c.begin(), c.end(), [](int x){return x > 0;}) << endl; /// 0

    /// none_of : if every element return false then returns true.
    cout << none_of (b.begin(), b.end(), [](int x){return x > 0;}) << endl; /// 0. 
    cout << none_of (c.begin(), c.end(), [](int x){return x > 0;}) << endl; /// 1


    return 0;
}