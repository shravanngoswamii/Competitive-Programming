// Author: Shravan Goswami

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, L;
    cin >> N >> L;
    vector<int> T(N);
    for (int i = 0; i < N; i++){
        cin >> T[i];
    }
    
    // For each employee i, choose a_i = (i+1)%N and b_i = (i+1)%N.
    // This creates a cycle: starting from employee 0,
    // the cleaning duty goes to employee 1, then 2, ... then N-1, then back to 0.
    for (int i = 0; i < N; i++){
        int nxt = (i + 1) % N;
        cout << nxt << " " << nxt << "\n";
    }
    
    return 0;
}
