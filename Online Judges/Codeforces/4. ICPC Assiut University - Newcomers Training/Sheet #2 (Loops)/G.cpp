// https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/G

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long f = 1;
        for(int i = 1; i <= n; ++i) {
            f *= i;
        }
        cout << f << endl;
    }
    return 0;
}
