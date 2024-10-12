// B - Traveling Takahashi Problem /

// Time Limit: 2 sec / Memory Limit: 1024 MB

// It is prohibited to directly input all or part of the information issued as problems in ongoing AtCoder contests into software. Please refer to this post for details.

// Score :

// 150 p
// Problem Statement

// Takahashi is at the origin on a two-dimensional coordinate plane.

// The cost for him to move from point
// (a,b) to point (c,d) is (a−c)2+(b−d)2

// ​.

// Find the total cost when he starts at the origin, visits
// N p

// (X1​,Y1​),…,(XN​,YN​) in this order, and then returns to the origin.
// Constraints

// 1≤N≤2×105

//     −109≤Xi​,Yi​≤109
//     All input values are integers.

// Input

// The input is given from Standard Input in the following format:

// N

// X1​ 

// Y1​

// ⋮

// XN​ 

// YN​

// Output

// Print the answer.
// Your output will be considered correct if its absolute or relative error from the true value is at most

// 10−6.
// Sample Input 1
// Copy

// 2
// 1 2
// -1 0

// Sample Output 1
// Copy

// 6.06449510224597979401

// The journey consists of the following three steps:

//     Move from 

// (0,0) to (1,2). The cost is (0−1)2+(0−2)2
// ​=5
// ​=2.236067977....
// Move from
// (1,2) to (−1,0). The cost is (1−(−1))2+(2−0)2
// ​=8
// ​=2.828427124....
// Move from
// (−1,0) to (0,0). The cost is (−1−0)2+(0−0)2
// ​=1

//     ​=1.

// The total cost is

// 6.064495102....
// Sample Input 2
// Copy

// 7
// -14142 13562
// -17320 50807
// -22360 67977
// 24494 89742
// -26457 51311
// 28284 27124
// 31622 77660

// Sample Output 2
// Copy

// 384694.57587932075868509383

// Sample Input 3
// Copy

// 5
// -100000 100000
// 100000 -100000
// -100000 100000
// 100000 -100000
// -100000 100000

// Sample Output 3
// Copy

// 1414213.56237309504880168872

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    double ans = 0;
    ans += sqrt(pow(p[0].first, 2) + pow(p[0].second, 2));
    
    for (int i = 0; i < n - 1; i++) {
        ans += sqrt(pow(p[i].first - p[i + 1].first, 2) + pow(p[i].second - p[i + 1].second, 2));
    }
    
    ans += sqrt(pow(p[n-1].first, 2) + pow(p[n-1].second, 2));
    
    cout << fixed << setprecision(20) << ans << endl;
}