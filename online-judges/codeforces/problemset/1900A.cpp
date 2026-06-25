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
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	if (s.find("...") != string::npos){
    		cout << "2" << endl;
    	}
    	else {
            int c = count(s.begin(), s.end(), '.');
    		cout << c << endl;
    	}
    }

    return 0;   
}

