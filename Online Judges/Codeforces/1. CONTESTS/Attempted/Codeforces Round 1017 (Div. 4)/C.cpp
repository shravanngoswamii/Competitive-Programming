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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        int m = 2 * n;
        vector<int> p(m + 1, 0);
        vector<bool> u(m + 1, false);
        for (int s = 2; s <= n + 1; s++) {
            int x = a[0][s - 2];
            p[s] = x;
            u[x] = true;
        }

        for (int s = n + 2; s <= m; s++) {
            int x = a[s - n - 1][n - 1];
            p[s] = x;
            u[x] = true;
        }

        int x = 0;
        for (int i = 1; i <= m; i++) {
            if (!u[i]) {
                x = i;
                break;
            }
        }
        p[1] = x;

        for (int i = 1; i <= m; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
