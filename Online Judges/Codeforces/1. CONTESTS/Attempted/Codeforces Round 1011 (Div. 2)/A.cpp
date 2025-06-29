#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        if (s < rev_s) {
            cout << "YES\n";
        } else {
            if (s == rev_s) {
                bool all_same = true;
                for (int i = 1; i < n; ++i) {
                    if (s[i] != s[0]) {
                        all_same = false;
                        break;
                    }
                }
                if (all_same) {
                    cout << "NO\n";
                } else {
                    if (k >= 1) {
                        cout << "YES\n";
                    } else {
                        cout << "NO\n";
                    }
                }
            } else {
                int i;
                for (i = 0; i < n / 2; ++i) {
                    if (s[i] != rev_s[i]) {
                        break;
                    }
                }
                int j = n - 1 - i;
                if (s[i] > s[j]) {
                    if (k >= 1) {
                        cout << "YES\n";
                    } else {
                        cout << "NO\n";
                    }
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}