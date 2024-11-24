///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;

    pq.push (1);
    pq.push (2);
    pq.push (5);
    pq.push (4);
    pq.push (3);

    cout << pq.top() << endl;   /// 5

    pq.pop();
    cout << pq.top() << endl;   /// 4

    while (!pq.empty())
    {                               //// Automatically sorted in non-increasing order.
        cout << pq.top() << ' ';    /// 4 3 2 1
        pq.pop();
    }
    cout << endl;



    /// default priority in pair 
    priority_queue<pair<int, int>> p;

    p.push ({ 1, 2});
    p.push ({ 2, 4});
    p.push ({ 2, 3});
    p.push ({ 4, 4});
    p.push ({ 3, 4});   

    cout << "Default order..." << endl;

    while (!p.empty())
    {
        cout << p.top().first << ' ' << p.top().second << endl;
        p.pop();
    }

    /* Output
    4 4
    3 4
    2 4
    2 3
    1 2
    */

    ///  sorting smaller to greater
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push ({ 1, 2});
    q.push ({ 2, 4});
    q.push ({ 2, 3});
    q.push ({ 4, 4});
    q.push ({ 3, 4});

    cout << "Sorting smaller to greater..." << endl;
    while (!q.empty())
    {
        cout << q.top().first << ' ' << q.top().second << endl;
        q.pop();
    }

    /*Output
    1 2
    2 3
    2 4
    3 4
    4 4
    */
    

    return 0;
}