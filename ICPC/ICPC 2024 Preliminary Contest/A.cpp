#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        sort(c.begin(), c.end());
        vector<ll> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + c[i];
        }
        vector<ll> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + c[i - 1];
            if (i >= k + 1) {
                dp[i] = min(dp[i], dp[i - k - 1] + prefix_sum[i] - prefix_sum[i - k]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << dp[i] << (i == n ? '\n' : ' ');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
