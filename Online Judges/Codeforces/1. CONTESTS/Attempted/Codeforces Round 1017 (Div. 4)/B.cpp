// Author: Shravan Goswami

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int amn = max(l, -m);
        int amx = min(r - m, 0);
        int a = max(amn, amx);
        cout << a << ' ' << a + m << '\n';
    }
    return 0;
}