#include <bits/stdc++.h>
using namespace std;

const int b = 30;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long long> p(b);
    p[0] = 1;
    for (int i = 1; i < b; ++i) {
        p[i] = p[i - 1] * 2;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> c(b, 0);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < b; ++j) {
                if ((a[i] >> j) & 1) {
                    c[j]++;
                }
            }
        }

        long long m = 0;
        for (int i = 0; i < n; ++i) {
            long long s = 0;
            for (int j = 0; j < b; ++j) {
                int x = c[j];
                int y = n - x;
                if ((a[i] >> j) & 1) {
                    s += (long long)y * p[j];
                } else {
                    s += (long long)x * p[j];
                }
            }
            m = max(m, s);
        }

        cout << m << endl;
    }
}