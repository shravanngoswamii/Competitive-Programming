#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d, l;
        cin >> n >> d >> l;

        vector<pair<int, int>> edges;

        if (d == 1) {
            if (n != 2 || l != 2) {
                cout << -1 << '\n';
                continue;
            }
            edges.push_back({1, 2});
        } else if (d == 2) {
            if (l != n - 1) {
                cout << -1 << '\n';
                continue;
            }
            for (int i = 2; i <= n; ++i) {
                edges.push_back({1, i});
            }
        } else {
            if (n != d + l - 1 || l < 2) {
                cout << -1 << '\n';
                continue;
            }

            for (int i = 1; i <= d; ++i) {
                edges.push_back({i, i + 1});
            }

            int next_node = d + 2;
            for (int i = 2; i <= d && next_node <= n; ++i) {
                edges.push_back({i, next_node});
                ++next_node;
            }
        }

        for (auto &edge : edges) {
            cout << edge.first << ' ' << edge.second << '\n';
        }
    }
    return 0;
}
