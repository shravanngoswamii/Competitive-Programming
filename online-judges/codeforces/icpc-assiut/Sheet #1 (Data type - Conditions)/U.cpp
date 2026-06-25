// https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/U

#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;

    // Check if n is an integer
    if (n - int(n) == 0) {
        cout << "int " << int(n);
    } else {
        cout << "float " << int(n) << " " << n-int(n);
    }

    return 0;
}
