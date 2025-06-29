// Author: Shravan Goswami

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Optimize I/O
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int c = k / __gcd(k, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << (i + (long long)j * c) % k + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}