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
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<int, int>> e(n);
        for (int i = 0; i < n; i++) {
            e[i] = {a[i], b[i]};
        }
        sort(e.begin(), e.end());

        int m = LLONG_MAX;
        priority_queue<int> pq;
        int s = 0;

        for (int i = 0; i < n; i++) {
            pq.push(e[i].second);
            s += e[i].second;

            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                m = min(m, e[i].first * s);
            }
        }

        cout << m << endl;
    }

    return 0;   
}

