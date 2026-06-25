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
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (auto &x:v){
            cin >> x.first >> x.second;
        }
        v.emplace_back(0,0);
        reverse(v.begin(),v.end());
        v.emplace_back(0,0);
        n=size(v);
        long double ans=0;
        for (int i=0; i+1<n; i++) {
            const int x=v[i].first-v[i+1].first, y=v[i].second-v[i+1].second;
            ans+=sqrt(x*x+y*y);
        }
        cout << fixed << setprecision(20) << ans << endl;
    }
    return 0;   
}

