/*
url: https://codeforces.com/problemset/problem/1901/A

Approach:
1. Calculate the maximum distances from $0$ to the first gas station, between consecutive gas stations, and from the last gas station to $x$ (doubled for the return trip).
2. The minimum gas tank volume is the maximum of these distances.
*/

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        int d = 0;
        d = max(d, s[0]);

        for (int j = 1; j < n; ++j) {
            d = max(d, s[j] - s[j - 1]);
        }

        d = max(d, 2 * (x - s[n - 1]));
        cout << d << endl;
    }

    return 0;   
}
