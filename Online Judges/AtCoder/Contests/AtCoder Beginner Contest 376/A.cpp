#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t=1;
    // cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> ti(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> ti[i];
        }

        int count = 0;
        int time = -c;

        for (int i = 0; i < n; ++i) {
            if (ti[i] - time >= c) {
                count++;
                time = ti[i];
            }
        }

        cout << count << endl;
    }

    return 0;   
}
