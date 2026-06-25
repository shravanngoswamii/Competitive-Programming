#include <bits/stdc++.h>
using namespace std;

bool isBetter(const vector<int>& a, const vector<int>& b) {
    bool flag = false;
    for (int i = 0; i < 3; ++i) {
        if (a[i] < b[i]) return false;
        if (a[i] > b[i]) flag = true;
    }
    return flag;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<vector<int>> v(3, vector<int>(3));
        for (int i = 0; i < 3; ++i) {
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }

        vector<int> p = {0, 1, 2};
        bool res = false;
        
        do {
            bool valid = true;
            for (int i = 0; i < 2; ++i) {
                if (!isBetter(v[p[i]], v[p[i + 1]])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = true;
                break;
            }
        } while (next_permutation(p.begin(), p.end()));

        if (res) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
