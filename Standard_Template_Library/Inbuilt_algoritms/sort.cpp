///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///


#include<bits/stdc++.h>
using namespace std;

int main ()
{  
    int arr[] = {4, 5, 3, 25, 7, 8, 5, 30, 2};

    sort (arr, arr+9);  /// Have to send 2 parameter starting point and ending point you want to sort.
    cout << "Sorted in non-decreasing order..." << endl;
    for (auto val : arr) cout << val << " ";        //// 2 3 4 5 5 7 8 25 30 
    cout << endl;


    vector<int> v = {1, 4, 56, 778, 23, 3, 4, 67, 78, 9};
    sort (v.begin(), v.end());      /// O(n * log(n))
    for (auto val : v) cout << val << ' ';  /// 1 3 4 4 9 23 56 67 78 778 
    cout << endl;


    cout << "Sorted in non-increasing order..." << endl;

    sort (v.rbegin(), v.rend());        /// O(n * log(n))
    for (auto val : v) cout << val << " ";      //// 778 78 67 56 23 9 4 4 3 1 
    cout << endl;

    return 0;
}