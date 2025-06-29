#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans=0;
    for (int i=0; i<=n-2; i++){
        ans+=s.substr(i,3)=="#.#";
    }
    cout << ans;
    return 0;   
}

