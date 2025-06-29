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
    	int n, c=0;
    	cin >> n;
    	vector<int> v(n);
    	while(n--){
    		cin >> v[c];
    		c++;
    	}
    	if(v[0]==1){
    		cout << "YES" << endl;
    	}
    	else{
    		cout << "NO" << endl;
    	}
    }

    return 0;   
}

