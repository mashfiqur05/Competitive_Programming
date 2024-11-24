z`#include<bits/stdc++.h>
using namespace std;

int main ()
{
    /// Declaring Tuples
    tuple <string, int, double> tup1;

    /// Assigning values to tuple using make_tuple()
    tup1 = make_tuple ("Nadif", 19, 24.245);

    /// You can also declaring tuples and assigning values together.
    tuple <string, int, double> tup2 ("Shihab", 23, 67.345);
    

    /// Accessing tuples values
    cout << get<0>(tup1) << endl; /// Output: Nadif
    cout << get<1>(tup1) << endl; /// Output: 19
    cout << get<2>(tup1) << endl; /// Output: 24.245\
    

    /// Tuples size
    cout << tuple_size<decltype(tup1)>::value << endl;  /// Output: 3
    cout << tuple_size<decltype(tup2)>::value << endl;  /// Output: 3


    /// Changing values
    get<0>(tup1) = "Mashfiqur";
    cout << get<0>(tup1) << endl;   /// Output: Mashfiqur


    /// Swaping Tuples
    tuple<int, char, bool> thing1 (12, 'a', true);
    tuple<int, char, bool> thing2 (28, 'v', false);
    thing1.swap (thing2);

    cout << get<0>(thing1) << ' ' << get<1>(thing1) << ' ' << get<2>(thing1) << endl; /// Output: 28 v 0
    cout << get<0>(thing2) << ' ' << get<1>(thing2)<< ' ' << get<2>(thing2) << endl; /// Output: 12 a 1


    /// Decomposing Tuples
    tuple <int, int> t(12, 16);
    tuple <int, char, string> tup3(28, 'w', "uddin");
    int x, y, z;
    string s;

    tie (x, y) = t;
    cout << x << " " << y << endl;  /// Output: 12 16
    cout << get<0>(t) << ' ' << get<1>(t) << endl;   /// Output: 12 16


    // Use of tie() with ignore
    // ignores char value
    tie (z, ignore, s) = tup3;
    cout << z << " " << s << endl;  /// Output: 28 uddin


    /// Concating Tuples
    tuple <string, int> t1 ("rahman", 25);
    tuple <double, char, bool> t2 (13.45, 'e', true);
    tuple <string, int, double, char, bool> t3 = tuple_cat (t1, t2);
    /// If you want to avoid to write data type  you can write this way.
    /// auto t3 = tuple_cat(t1, t2);
    /// It will automatically determine what type of tuples it is.

    cout << get<0>(t3) << endl; /// Output: rahman
    cout << get<1>(t3) << endl; /// Output: 25
    cout << get<2>(t3) << endl; /// Output: 13.45
    cout << get<3>(t3) << endl; /// Output: e
    cout << get<4>(t3) << endl; /// Output: 1


    return 0;
}