#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        auto cd = [](int p) {
            return int(log10(p) + 1);
        };
        auto ctz = [](int p) {
            int zeros = 1, count = 0;
            while (p % (zeros *= 10) == 0) {
                ++count;
            }
            return count;
        };
        sort(num.begin(), num.end(), [&](int i, int j) {
            return ctz(i) < ctz(j);
        });
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += cd(num[i]);
            if (i % 2 == (n - 1) % 2) {
                ans -= ctz(num[i]);
            }
        }
        if (ans <= m) {
          cout << "Anna" << endl;
        } 
        else {
          cout << "Sasha" << endl;
}

    }
    return 0;
}
