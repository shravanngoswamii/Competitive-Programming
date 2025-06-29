// Author: Shravan Goswami

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull n;
    cin >> n;

    for (ull d = 1; d * d * d <= n; d++) {
        if (n % d != 0) continue;
        ull t = n / d;
        ull di = 12ULL * t;
        if (3ULL * d * d > di) continue;
        di -= 3ULL * d * d;

        long double sq = sqrt((long double)di);
        ull r = (ull)(sq + 1e-9);
        if (r * r != di) continue;

        if (r < 3 * d) continue;
        if ((r - 3 * d) % 6 != 0) continue;
        ull y = (r - 3 * d) / 6;
        if (y == 0) continue;

        ull x = y + d;
        cout << x << " " << y << endl;
        return 0;
    }

    cout << -1 << endl;
    return 0;
}