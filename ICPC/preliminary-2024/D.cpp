#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N;
vector<unordered_set<int>> H;
int c[MAXN], o[MAXN];
long long DP[2][2][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    H.resize(N + 2);
    vector<int> a(N + 1);
    int t = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        t += a[i];
    }

    for (int i = 1; i <= N; ++i) {
        int x = a[i];
        for (int j = 0; j < x; ++j) {
            int h;
            cin >> h;
            H[i].insert(h);
        }
    }

    for (int i = 1; i <= N - 1; ++i) {
        int cnt = 0;
        for (int h : H[i]) {
            if (H[i + 1].count(h)) {
                ++cnt;
            }
        }
        c[i] = cnt;
    }

    for (int i = 2; i <= N - 1; ++i) {
        int cnt = 0;
        for (int h : H[i - 1]) {
            if (H[i + 1].count(h)) {
                ++cnt;
            }
        }
        o[i] = cnt;
    }

    memset(DP, 0x3f, sizeof(DP));
    DP[1 % 2][1][1] = 0;

    for (int i = 2; i <= N; ++i) {
        int cur = i % 2;
        int prev = (i - 1) % 2;
        memset(DP[cur], 0x3f, sizeof(DP[cur]));

        for (int p = 0; p <= 1; ++p) {
            for (int d_prev = 0; d_prev <= 1; ++d_prev) {
                for (int d = 0; d <= 1; ++d) {
                    if (i == N && d != 0) continue;
                    long long cost = 0;

                    if (d_prev == 1 && d == 0) {
                        if (i - 1 >= 1) cost += c[i - 1];
                    }
                    if (p == 1 && d == 0 && i - 1 >= 2) {
                        cost += o[i - 1];
                    }

                    if (DP[prev][p][d_prev] + cost < DP[cur][d_prev][d]) {
                        DP[cur][d_prev][d] = DP[prev][p][d_prev] + cost;
                    }
                }
            }
        }
    }

    long long ans = LLONG_MAX;
    int cur = N % 2;
    for (int p = 0; p <= 1; ++p) {
        if (DP[cur][p][0] < ans) {
            ans = DP[cur][p][0];
        }
    }

    cout << ans << '\n';
    return 0;
}
