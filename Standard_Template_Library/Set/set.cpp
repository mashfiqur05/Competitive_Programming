///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


int main()
{
    /// Declaration of set of integers
	set<int> s = { 1, 1, 2, 1, 3 };
    s.insert (4);   /// O(log(n)) for insert same as map.

    for (auto val : s)  /// Print in sorted order and only unique value. O(log(n)) for every iterator.
        cout << val << " ";  /// 1 2 3 4 
    cout << endl;

    auto it = s.find (2);    /// O(log(n)).
    if (it != s.end ()) cout << *it << endl;    /// 2 

    if (it != s.end ())  s.erase (it);  /// deletes 2.

    for (auto val : s) cout << val << " ";  /// 1 3 4
    cout << endl;


    /// set of pair ///
	set<pair<int, int>> s1;

	s1.insert ( { 1, 2 } );
	s1.insert ( { 1, 2 } );
	s1.insert ( { 4, 2 } );
	s1.insert ( { 4, 3 } );
	s1.insert ( { 2, 2 } );
	s1.insert ( { 2, 1 } );

	cout << s1.size() << endl;
	for ( auto u : s1 ) cout << u.first << " " << u.second << endl;


	/**

	Output :

	5
    1 2
    2 1
    2 2
    4 2
    4 3

    */


	/// Set of string

	set<string> s2;

	s2.insert ( "momo" );
	s2.insert ( "momo" );
	s2.insert ( "prety" );
	s2.insert ( "prety" );
	s2.insert ( "shahriar" );
	s2.insert ( "nobel" );
	s2.insert ( "sharif" );
	s2.insert ( "proma" );

	cout << s2.size() << endl; // 6
	for ( auto u : s2 ) cout << u << endl;

	/**

	Output :

	6
    momo
    nobel
    prety
    proma
    shahriar
    sharif

    */

    /// set in decreasing order
    set<int, greater<int>> s3 = {3, 4, 1, 2};
    for ( auto u : s3 ) cout << u << " "; /// 4 3 2 1
    cout << endl;


    set<string, greater<string>> s4;

	s4.insert ( "momo" );
	s4.insert ( "momo" );
	s4.insert ( "prety" );
	s4.insert ( "prety" );
	s4.insert ( "shahriar" );
	s4.insert ( "nobel" );
	s4.insert ( "sharif" );
	s4.insert ( "proma" );

	cout << s4.size() << endl;
	for ( auto u : s4 ) cout << u << endl;

	/**
	Output :

	6
    sharif
    shahriar
    proma
    prety
    nobel
    momo

    */

    set<pair<int, int>, greater<pair<int,int>>> s5;

	s5.insert ( { 1, 2 } );
	s5.insert ( { 1, 2 } );
	s5.insert ( { 4, 2 } );
	s5.insert ( { 4, 3 } );
	s5.insert ( { 2, 2 } );
	s5.insert ( { 2, 1 } );


	cout << s5.size() << endl;
	for ( auto u : s5 ) cout << u.first << " " << u.second << endl;

	/**

	Output :
	5
    4 3
    4 2
    2 2
    2 1
    1 2

    */



    ///   ***   ---   |||		 Unordered set		|||   ---   ***   ///

    unordered_set<int>s6;

    s6.insert (3);   /// O(1).
    s6.insert (3);
    s6.insert (1);
    s6.insert (2);


    for (auto u : s6) cout << u << " ";	/// 2 3 1. randomly ordered 
    cout << endl;



    ///   ***   ---   |||		 Multi Set		|||   ---   ***   ///

    multiset<int> ms;
    ms.insert (12);     /// O(log(n))
    ms.insert (22);
    ms.insert (22);
    ms.insert (15);
    ms.insert (12);
    
    /// Allow duplicates. Otherwise same as set.

    for (auto val : ms) cout << val << " ";  /// 12 12 15 22 22
    cout << endl;

    it = ms.find (12);
    if (it != ms.end()) ms.erase (it);  /// deletes 12 and delete only one value.
    for (auto val : ms) cout << val << " ";  /// 12 15 22 22
    cout << endl;

    ms.erase (22);  /// this time deletes all 22.
    for (auto val : ms) cout << val << " ";  /// 12 15 
    cout << endl;

    /// When we erase through iterator then erase the only value that iterator indicates.
    /// When we erase through value it erase its own duplictes also.


	return 0;
}