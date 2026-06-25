#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);

        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i) pq.push({a[i], b[i]});

        long long sc = 0;
        while (k-- && !pq.empty()) {
            auto [v, dec] = pq.top();
            pq.pop();

            sc += v;
            int nv = v - dec;
            if (nv > 0) {
                pq.push({nv, dec});
            }
        }

        cout << sc << endl;
    }

    return 0;
}
