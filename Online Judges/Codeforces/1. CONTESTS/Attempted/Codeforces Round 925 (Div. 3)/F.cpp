#include<bits/stdc++.h>
using namespace std;

vector<int> g[200001];
int v[200001];
int dv[200001];

bool dfs(int n) {
    v[n] = 1;
    dv[n] = 1;
    for (int it : g[n]) {
        if (!v[it]) {
            if (dfs(it))
                return true;
        } else if (dv[it])
            return true;
    }
    dv[n] = 0;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            v[i] = 0;
            dv[i] = 0;
        }
        for (int i = 0; i < k; i++) {
            vector<int> vec(n);
            for (int j = 0; j < n; j++) {
                cin >> vec[j];
            }
            for (int j = 2; j < n; j++) {
                g[vec[j - 1]].push_back(vec[j]);
            }
        }
        bool f = false;
        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                if (dfs(i)) {
                    f = true;
                    break;
                }
            }
        }
        cout << (f ? "NO" : "YES") << endl;
    }
    return 0;
}
