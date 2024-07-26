#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        vector<int> p = {x1, x2, x3};
        sort(p.begin(), p.end());

        int m = p[1];

        int td = abs(m - x1) + abs(m - x2) + abs(m - x3);

        cout << td << endl;
    }

    return 0;
}
