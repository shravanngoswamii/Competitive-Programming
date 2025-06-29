#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int d(int a, int b, int n) {
    return (b - a + n) % n;
}

void solve() {
    int n, q, t = 0, l = 1, r = 2;
    cin >> n >> q;
    while (q--) {
        char h;
        int x;
        cin >> h >> x;
        if (h == 'L' && x != r) {
            int cl = d(l, x, n);
            int cr = d(r, x, n);
            if (cl <= cr) {
                t += cl;
            } else {
                t += n - cl;
            }
            l = x;
        } else if (h == 'R' && x != l) {
            int cl = d(l, x, n);
            int cr = d(r, x, n);
            if (cr < cl) {
                t += cr;
            } else {
                t += n - cr;
            }
            r = x;
        }
    }
    cout << t << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;   
}
