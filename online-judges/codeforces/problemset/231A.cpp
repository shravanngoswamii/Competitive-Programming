// https://codeforces.com/contest/231/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int tp = 0;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                count++;
            }
        }
        if (count >= 2) {
            tp++;
        }
    }
    
    cout << tp << endl;

}
