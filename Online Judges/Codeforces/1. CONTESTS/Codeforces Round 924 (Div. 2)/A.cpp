#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a % 2 != 0 && b % 2 != 0) {
            cout << "NO" << endl;
        } else if (a % 2 == 0 && b % 2 == 0) {
            cout << "YES" << endl;
        } else if (a % 2 == 0 && b % 2 != 0) {
            if (a / 2 == b) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else if (b % 2 == 0 && a % 2 != 0) {
            if (b / 2 == a) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
