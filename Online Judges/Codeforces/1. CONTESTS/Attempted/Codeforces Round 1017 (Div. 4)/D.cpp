// Author: Shravan Goswami

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        vector<int> dp(m + 1, -1);
        dp[0] = 0;
        for (int j = 0; j < m; j++) {
            if (dp[j] >= 0 && dp[j] < n) {
                int i = dp[j];
                if (b[j] == a[i]) {
                    dp[j + 1] = max(dp[j + 1], i + 1);
                }
                if (j + 1 < m && b[j] == b[j + 1] && b[j] == a[i]) {
                    dp[j + 2] = max(dp[j + 2], i + 1);
                }
            }
        }
        cout << (dp[m] == n ? "YES" : "NO") << "\n";
    }
    return 0;
}
