#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

int parent[MAXN];
long long potential[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        potential[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        int old_parent = parent[x];
        parent[x] = find(parent[x]);
        potential[x] += potential[old_parent];
    }
    return parent[x];
}

void union_sets(int x, int y, long long sum) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) {
        // Already in the same set, ensure consistency
        if (potential[x] + potential[y] != sum) {
            // Contradiction, handle it appropriately (e.g., return an error)
            // In this case, we can simply return and let the subsequent queries handle it.
            return;
        }
        return;
    }
    // Merge the sets and update potentials
    parent[ry] = rx;
    potential[ry] = sum - potential[x] - potential[y];
}

int main() {
    int n, q;
    cin >> n >> q;

    init(n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            long long k;
            cin >> i >> j >> k;
            union_sets(i, j, k);
        } else if (t == 2) {
            int i, j;
            cin >> i >> j;
            int ri = find(i);
            int rj = find(j);
            if (ri != rj) {
                cout << -1 << endl;
            } else {
                long long sum = potential[i] + potential[j];
                cout << sum << endl;
            }
        }
    }

    return 0;
}