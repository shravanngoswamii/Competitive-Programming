/*
Colliding Balls Problem

Problem Statement (Solve in C++)

There are n red balls kept on the positive X axis, and m blue balls kept on the
positive Y axis. You are given the positions of the balls. For each i from 1 to n,
the i-th red ball has the coordinates (xi, 0), where xi is a positive integer. For
each i from 1 to m, the i-th blue ball has the coordinates (0, yi), where yi is a
positive integer.
It is given that all xi are distinct. Also, all yi are distinct.
At time t = 0, for each i from 1 to n, the i-th red ball is thrown towards
the positive Y axis with a speed of ui (that is, with velocity vector (0, ui)).
Simultaneously (at time t = 0), for each i from 1 to m, the i-th blue ball is
thrown towards the positive X axis with a speed of vi (that is, with velocity
vector (vi, 0)).
Two balls are said to collide if they are at the same position at the same
time. When two balls collide, they disappear and no longer collide with other
balls.
Your task is to find the total number of collisions that occur between the
balls.


Input:

- The first line contains n and m, the number of red balls and the number of blue balls, respectively.
- The next n lines each contain two space-separated integers xi and ui, representing the position and speed of the i-th red ball, respectively.
- The next m lines each contain two space-separated integers yi and vi, representing the position and speed of the i-th blue ball, respectively.


Output:

Print the total number of collisions.


Constraints:

1 ≤ n, m ≤ 10^5
1 ≤ xi, ui, yi, vi ≤ 10^9
For all 1 ≤ i < j ≤ n, xi not equals to xj
For all 1 ≤ i < j ≤ m, yi not equals to yj


Example:

Input 1
1 1
1 2
2 1

Output 1
1

Input 2
1 2
1 2
2 1
1 2

Output 2
1

Explanation

- Example Case 1: The balls collide at t = 1, at the coordinates (1, 2).
- Example Case 2: The red ball and the second blue ball collide at time t = 0.5 at coordinates (1, 1). Note that the first blue ball would have collided with the red ball at t = 1 (like in sample input #1), if the second blue ball wasn’t present. However, since the red ball disappears at t = 0.5, its collision with the first blue ball does not happen. Thus, the total number of collisions is 1*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> ks;
    vector<ll> rK(n);
    for (int i = 0; i < n; ++i) {
        ll x, u;
        cin >> x >> u;
        rK[i] = x * u;
        ks.push_back(rK[i]);
    }

    vector<ll> bK(m);
    for (int i = 0; i < m; ++i) {
        ll y, v;
        cin >> y >> v;
        bK[i] = y * v;
        ks.push_back(bK[i]);
    }

    sort(ks.begin(), ks.end());
    ks.erase(unique(ks.begin(), ks.end()), ks.end());
    map<ll, int> k_id;
    for (int i = 0; i < ks.size(); ++i) {
        k_id[ks[i]] = i;
    }

    vector<int> r(ks.size(), 0);
    vector<int> b(ks.size(), 0);

    for (int i = 0; i < n; ++i) {
        int id = k_id[rK[i]];
        r[id]++;
    }
    for (int i = 0; i < m; ++i) {
        int id = k_id[bK[i]];
        b[id]++;
    }

    ll tc = 0;
    for (int i = 0; i < ks.size(); ++i) {
        tc += min(r[i], b[i]);
    }

    cout << tc << endl;

    return 0;
}
