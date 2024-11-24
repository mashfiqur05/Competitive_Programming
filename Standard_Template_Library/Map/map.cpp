///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "nadif";     /// O(log(n)).
    m[6] = "shihab";
    m[3] = "jimel";
    m[7] = "samiha";
    m[4] = "arik";
    m.insert ({5, "bobi"});     /// O(log(n)).

    for (auto u : m)
    {
        cout << u.first << " " << u.second << endl;     /// O(log(n)).
    }
    /*
    1 nadif
    3 jimel
    4 arik
    5 bobi
    6 shihab
    7 samiha
    */

    m[4] = "jihan";    /// change the value arik to jihan.
    cout << "Changing arik to ";
    cout << m[4] << endl;   /// jihan.


    auto it = m.find (7);       /// Olog(n). return the iterator of 3.
    if (it != m.end()) cout << (*it).first << ' ' << (*it).second << endl;  /// samiha
    else cout << "NO Value" << endl;

    auto balu = m.find (10);    /// Olog(n)
    if (balu != m.end()) cout << (*balu).first << ' ' << (*balu).second << endl;  /// NO Value
    else cout << "NO Value" << endl;

    m.erase (4);        /// O(log(n)). removes 4.
    it = m.find(3);     /// O(log(n)). 
    if (it != m.end()) m.erase (it);       /// this time time O(1). if we erase through iterator then O(1).
    cout << "\nAfter erasing..." << endl;
    for (auto u : m) cout << u.first << ' ' << u.second << endl;
    /*
    1 nadif
    5 bobi
    6 shihab
    7 samiha
    */

    map<string, string> mp;
    mp["asdfg"] = "qwer";   /// O(key.size() * log(n))

    
    /// Count frequency by maping.

    vector <long long> v = {2, 102393903303, 3774, 748484994, 102393903303, 40505, 40505};
    map<long long, int> cnt;

    for (auto u : v) cnt[u]++;

    cout << cnt[102393903303] << endl;  /// 2

    for (auto u : cnt) cout << u.first << ' = ' << u.second << endl;    /// O(n * log(n))
    
    /*
    will be sorted automatically
        2 = 1
        3774 = 1
        40505 = 2
        748484994 = 1
        102393903303 = 2
    */


    return 0;
}
