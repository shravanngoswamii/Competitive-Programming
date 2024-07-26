#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        long long cnt = 0;
        for (int a = 1; a <= min(x - 2, n); ++a) {
            for (int b = 1; b <= min(x - a - 1, n / a); ++b) {
                int maxcsum = x - a - b;
                int maxcprod = (n - a * b) / (a + b);
                if (maxcprod < 1) continue;
                int maxc = min(maxcsum, maxcprod);
                if (maxc >= 1) {
                    cnt += maxc;
                }
            }
        }
        cout << cnt << endl;
    }
}