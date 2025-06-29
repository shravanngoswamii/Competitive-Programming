// Author: Shravan Goswami

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n, 0), s(n, 0);
    vector<int> f(n + 1, 0);
    int d = 0;

    for (int i = 0; i < n; i++) {
        if (f[a[i]] == 0) {
            d++;
        }
        f[a[i]]++;
        p[i] = d;
    }

    fill(f.begin(), f.end(), 0);
    d = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (f[a[i]] == 0) {
            d++;
        }
        f[a[i]]++;
        s[i] = d;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, p[i] + s[i + 1]);
    }

    cout << ans << "\n";
    return 0;
}