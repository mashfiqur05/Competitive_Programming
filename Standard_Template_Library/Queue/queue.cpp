///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    
    q.push (1);     /// O(1)
    q.push (2);
    q.push (3);
    q.push (4);
    q.push (5);

    cout << q.size() << endl;   /// 5

    cout << q.front () << endl;  /// 1
    q.pop ();   /// removed the first element

    cout << q.front () << endl; /// 2

    while (!q.empty ())
    {
        cout << q.front () << " ";  /// 2 3 4 5
        q.pop ();
    }
    cout << endl;


    return 0;
}