// AUTHOR: Shravan Goswami

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        array<int, 10> counts = {0};
        const array<int, 10> required = {3, 1, 2, 1, 0, 1, 0, 0, 0, 0};

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            counts[a[i]]++;
            bool ok = true;
            for (int d : {0, 1, 2, 3, 5}) {
                if (counts[d] < required[d]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}