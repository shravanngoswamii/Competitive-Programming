// Author: Shravan Goswami

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();
    int start = (n % 2 == 0) ? n : n + 1;
    for (int l = start; l <= 2 * n; l += 2) {
        int j = 0;
        for (int pos = 0; pos < l && j < n; pos++) {
            char required = (pos % 2 == 0) ? 'i' : 'o';
            if (s[j] == required) {
                j++;
            }
        }
        if (j == n) {
            cout << l - n << endl;
            return 0;
        }
    }
    return 0;
}