#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        string n;
        cin >> n;
        
        int mp = INT_MAX;
        
        for (int i = 0; i < n.length(); ++i) {
            string nn = n.substr(0, i) + n.substr(i + 1);
            mp = min(mp, stoi(nn));
        }
        
        cout << mp << endl;
    }
    
    return 0;
}
