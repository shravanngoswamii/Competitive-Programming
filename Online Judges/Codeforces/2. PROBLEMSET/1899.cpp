#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
    	int n; cin >> n;
    	if(n%3==0){
    		cout << "Second" << endl;
    	}
    	else {
    		cout << "First" << endl;
    	}
    }

    return 0;   
}

